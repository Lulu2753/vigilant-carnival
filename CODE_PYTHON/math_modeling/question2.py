import numpy as np


def air_mass(alpha_deg):
    """计算大气质量"""
    if alpha_deg <= 0:
        return 1e10
    sin_alpha = np.sin(np.radians(alpha_deg))
    m = 1 / (sin_alpha + 0.50572 * (alpha_deg + 6.07995) ** (-1.6364))
    return m


def calculate_daily_energy(n, I0, phi, beta, gamma):
    """计算某一天光伏板接收的日总辐射能量（固定6:00-19:00）"""
    u = 0.542 #0.196103  # 衰减系数
    dt = 0.5  # 时间步长（小时）
    longitude = 114.3167  # 当地经度（度），东经114°19′

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
    while hour <= 19.0 + 1e-6:  # 加小量避免浮点误差
        # 步骤1：北京时间 → 真太阳时
        ts = hour + (longitude - 120) / 15

        # 步骤2：时角 ω
        omega_deg = 15 * (ts - 12)
        omega_rad = np.radians(omega_deg)

        # 太阳高度角 α
        sin_alpha = (np.sin(phi_rad) * np.sin(delta_rad) +
                     np.cos(phi_rad) * np.cos(delta_rad) * np.cos(omega_rad))
        sin_alpha = np.clip(sin_alpha, 0, 1)
        alpha_rad = np.arcsin(sin_alpha)
        alpha_deg = np.degrees(alpha_rad)

        # 大气质量 m（Kasten-Young）
        m = air_mass(alpha_deg)

        # 法向直射辐射强度 In
        I_normal = I0 * np.exp(-u * m) if m < 1e9 else 0

        # cosθ（太阳光线与光伏板法线的夹角余弦）
        if gamma == 0:
            # 正南朝向简化
            cos_theta = (np.sin(delta_rad) * np.sin(phi_rad - beta_rad) +
                         np.cos(delta_rad) * np.cos(phi_rad - beta_rad) * np.cos(omega_rad))
        else:
            # 完整公式
            cos_theta = (np.sin(delta_rad) * np.sin(phi_rad) * np.cos(beta_rad) -
                         np.sin(delta_rad) * np.cos(phi_rad) * np.sin(beta_rad) * np.cos(gamma_rad) +
                         np.cos(delta_rad) * np.cos(phi_rad) * np.cos(beta_rad) * np.cos(omega_rad) +
                         np.cos(delta_rad) * np.sin(phi_rad) * np.sin(beta_rad) * np.cos(gamma_rad) * np.cos(
                        omega_rad) +
                         np.cos(delta_rad) * np.sin(beta_rad) * np.sin(gamma_rad) * np.sin(omega_rad))

        cos_theta = np.clip(cos_theta, 0, 1)

        # 光伏板接收的直射辐射强度 Ip
        I_tilt = I_normal * cos_theta

        if I_tilt > I_max:
            I_max = I_tilt

        # 积分累加 (Wh/m²)
        E_day += I_tilt * dt

        # 下一步
        hour += dt

    return E_day, I_max


def optimize_single_objective(phi):
    """问题2：单目标优化 - 找最优朝向"""
    best_E = 0
    best_gamma = 0
    best_beta = 0

    month_days = [15, 46, 74, 105, 135, 166, 196, 227, 258, 288, 319, 349]
    I0_monthly = [1405, 1394, 1378, 1353, 1334, 1316, 1308, 1315, 1330, 1350, 1372, 1392]

    print("正在搜索最优朝向...")

    # 步长5°平衡精度和速度
    for gamma in range(-90, 91, 5):
        for beta in range(0, 91, 5):
            E_total = 0
            for n, I0 in zip(month_days, I0_monthly):
                E_day, _ = calculate_daily_energy(n, I0, phi, beta, gamma)
                E_total += E_day
            E_avg = E_total / 12
            if E_avg > best_E:
                best_E = E_avg
                best_gamma = gamma
                best_beta = beta
                print(f"发现更优: γ={best_gamma}°, β={best_beta}°, E={best_E:.2f} Wh/m²")

    return best_gamma, best_beta, best_E


# 主程序
if __name__ == "__main__":
    phi_wuhan = 30.5833  # 武汉纬度
    print("=" * 60)
    print("A题 第二问：单目标优化（固定安装，日均总能量最大）")
    print("=" * 60)
    print(f"当地纬度: {phi_wuhan}°")
    print(f"时间范围: 6:00 - 19:00 (北京时间)")
    print(f"步长: 0.5 小时")
    print("-" * 60)

    best_gamma, best_beta, best_E = optimize_single_objective(phi_wuhan)

    print("-" * 60)
    print("【优化结果】")
    print(f"最优方位角 γ: {best_gamma}°")
    print(f"最优倾角 β: {best_beta}°")
    print(f"最大年均日总能量: {best_E:.2f} Wh/m²")
    print(f"最大年均日总能量: {best_E / 1000:.2f} kWh/m²")