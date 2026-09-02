import numpy as np


def air_mass(alpha_deg):
    """
    Kasten-Young 公式计算大气质量
    alpha_deg: 太阳高度角 (度)
    """
    if alpha_deg <= 0:
        return 1e10
    sin_alpha = np.sin(np.radians(alpha_deg))
    m = 1 / (sin_alpha + 0.50572 * (alpha_deg + 6.07995) ** (-1.6364))
    return m


def calculate_daily_energy_and_duration(n, I0, phi, beta, gamma):
    """计算某一天光伏板接收的日总辐射能量和有效时长（固定6:00-19:00，不判断日出日落）"""
    u = 0.542  #0.196103  # 大气总光学厚度
    dt = 0.5      # 时间步长（小时）
    longitude = 114.3167  # 当地经度（度）

    # 有效时长统计
    T1 = 0  # 上午 > 150 W/m² 的时段数
    T2 = 0  # 下午 > 100 W/m² 的时段数

    # 转换为弧度
    phi_rad = np.radians(phi)
    beta_rad = np.radians(beta)
    gamma_rad = np.radians(gamma)

    # 赤纬角 δ (弧度)
    delta_rad = np.radians(23.45 * np.sin(2 * np.pi * (284 + n) / 365))

    E_day = 0.0
    I_max = 0.0

    # 遍历时间：6:00 到 19:00，步长 0.5 小时
    hour = 6.0
    while hour <= 19.0 + 1e-6:
        # 北京时间 → 真太阳时
        ts = hour + (longitude - 120) / 15

        # 时角 ω
        omega_deg = 15 * (ts - 12)
        omega_rad = np.radians(omega_deg)

        # 太阳高度角 α
        sin_alpha = (np.sin(phi_rad) * np.sin(delta_rad) +
                     np.cos(phi_rad) * np.cos(delta_rad) * np.cos(omega_rad))
        sin_alpha = np.clip(sin_alpha, 0, 1)
        alpha_rad = np.arcsin(sin_alpha)
        alpha_deg = np.degrees(alpha_rad)

        # 大气质量 m
        m = air_mass(alpha_deg)

        # 法向直射辐射强度
        I_normal = I0 * np.exp(-u * m) if m < 1e9 else 0

        # cosθ
        if gamma == 0:
            cos_theta = (np.sin(delta_rad) * np.sin(phi_rad - beta_rad) +
                         np.cos(delta_rad) * np.cos(phi_rad - beta_rad) * np.cos(omega_rad))
        else:
            cos_theta = (np.sin(delta_rad) * np.sin(phi_rad) * np.cos(beta_rad) -
                         np.sin(delta_rad) * np.cos(phi_rad) * np.sin(beta_rad) * np.cos(gamma_rad) +
                         np.cos(delta_rad) * np.cos(phi_rad) * np.cos(beta_rad) * np.cos(omega_rad) +
                         np.cos(delta_rad) * np.sin(phi_rad) * np.sin(beta_rad) * np.cos(gamma_rad) * np.cos(omega_rad) +
                         np.cos(delta_rad) * np.sin(beta_rad) * np.sin(gamma_rad) * np.sin(omega_rad))

        cos_theta = np.clip(cos_theta, 0, 1)
        I_tilt = I_normal * cos_theta

        # 统计有效时长
        if 6.0 <= hour < 12.0 and I_tilt > 150:
            T1 += 1
        elif 12.0 <= hour <= 19.0 and I_tilt > 100:
            T2 += 1

        if I_tilt > I_max:
            I_max = I_tilt

        # 积分累加
        E_day += I_tilt * dt
        hour += dt

    # 有效时长（小时）= 时段数 × 步长
    T_day = (T1 + T2) * dt

    return E_day, T_day, I_max


def optimize_multi_objective(phi):
    """
    问题3：双目标优化 - 找最优朝向
    目标1：日均总能量 E 最大
    目标2：日均有效时长 T 最大
    综合得分 F = E/Emax + T/Tmax
    """
    month_days = [15, 46, 74, 105, 135, 166, 196, 227, 258, 288, 319, 349]
    I0_monthly = [1405, 1394, 1378, 1353, 1334, 1316, 1308, 1315, 1330, 1350, 1372, 1392]

    results = []

    print("正在遍历搜索...")
    print("gamma(方位角) beta(倾角) 年均能量(Wh/m²) 年均时长(h) 综合得分")
    print("-" * 70)

    for gamma in range(-90, 91, 5):
        for beta in range(0, 91, 5):
            E_total = 0
            T_total = 0
            for n, I0 in zip(month_days, I0_monthly):
                E_day, T_day, _ = calculate_daily_energy_and_duration(n, I0, phi, beta, gamma)
                E_total += E_day
                T_total += T_day
            E_avg = E_total / 12
            T_avg = T_total / 12
            results.append({
                'gamma': gamma,
                'beta': beta,
                'E': E_avg,
                'T': T_avg
            })

    E_max = max(r['E'] for r in results)
    T_max = max(r['T'] for r in results)

    print(f"\n归一化基准: Emax = {E_max:.2f} Wh/m², Tmax = {T_max:.2f} 小时")
    print("\n" + "-" * 70)

    best_score = -1
    best_result = None

    for r in results:
        E_norm = r['E'] / E_max
        T_norm = r['T'] / T_max
        score = E_norm + T_norm

        if score > best_score:
            best_score = score
            best_result = r

    return best_result, E_max, T_max


# 主程序
if __name__ == "__main__":
    phi_wuhan = 30.5833  # 武汉纬度

    print("=" * 70)
    print("A题 第三问：双目标优化（储电量最大 + 储电效率最高）")
    print("=" * 70)
    print("时间范围: 固定 6:00 - 19:00（北京时间）")
    print("不判断日出日落，全天按此范围计算")
    print("-" * 70)

    best, E_max, T_max = optimize_multi_objective(phi_wuhan)

    print("\n" + "=" * 70)
    print("【优化结果】")
    print("=" * 70)
    print(f"最优方位角 γ: {best['gamma']}°")
    print(f"最优倾角 β: {best['beta']}°")
    print(f"\n对应的性能指标：")
    print(f"  日均总能量 E = {best['E']:.2f} Wh/m² = {best['E'] / 1000:.2f} kWh/m²")
    print(f"  日均有效时长 T = {best['T']:.2f} 小时")
    print(f"\n归一化基准：")
    print(f"  Emax = {E_max:.2f} Wh/m²")
    print(f"  Tmax = {T_max:.2f} 小时")
    print(f"\n综合得分 F = {best['E'] / E_max:.4f} + {best['T'] / T_max:.4f} = {best['E'] / E_max + best['T'] / T_max:.4f}")