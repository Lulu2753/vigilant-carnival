import math
from datetime import datetime, timedelta

import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'DejaVu Sans']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

ASIN = math.asin
SIN = math.sin
COS = math.cos
RADIANS = math.radians
DEGREES = math.degrees
 
#时差: 
def TimeDifference(lon):
    t = (lon -120) / 15
    return t
 
#真太阳时(T：北京时间)
def TrueSolarTime(T, t):
    ST = T + t
    return ST
 
#时角
def HourAngle(ST):
    h = 15 * (ST -12)
    return h
 
#太阳赤纬(N为积日，一年中的第几天)
def SolarDeclination(N):
    DEC = -23.443 * COS(RADIANS(round(360/365, 8) * (N + 10))) #三角函数需要用弧度制
    return DEC
    
#积日
def DayOfYear(time):
    day_of_year = time.timetuple().tm_yday  # 获取当年的第几天
    return day_of_year
 
#计算时角
def CalculateHourAngle(lon, T):
    t = TimeDifference(lon)
    ST = TrueSolarTime(T, t)
    H = HourAngle(ST)
    return H
    
#计算太阳赤纬
def CalculateSolarDeclination(time):
    N = DayOfYear(time)
    DEC = SolarDeclination(N)
    return DEC
    
def CalculateSunPosition(latitude, longitude, time):
    T = time.hour + round(1/60, 8) * time.minute + round(1/3600, 8) * time.second
    H = CalculateHourAngle(longitude, T)
    print("Hour Angle: ", H)
    DEC = CalculateSolarDeclination(time)
    print("DEC: ", DEC)
    sun_altitude = DEGREES(ASIN(SIN(RADIANS(latitude))*SIN(RADIANS(DEC))+COS(RADIANS(DEC))*COS(RADIANS(latitude))*COS(RADIANS(H))))
    sun_azimuth = DEGREES(ASIN(round((-COS(RADIANS(DEC))*SIN(RADIANS(H)) / COS(RADIANS(sun_altitude))), 8)))
    print("altitude_angle_deg:", sun_altitude)
    print("azimuth_angle_deg:", sun_azimuth)
    return sun_altitude, sun_azimuth

# 计算大气质量 m 的函数
def CalculateAirMass(sun_altitude):
    """
    计算大气质量 m
    公式: m = 1 / (sin a + 0.50572 * (a + 6.07995)^(-1.6364))
    其中 a 为太阳高度角（度数）
    """
    a = sun_altitude  # 太阳高度角（度数）
    
    # 确保太阳高度角大于0，否则大气质量无定义
    if a > 0:
        # 计算 sin(a)，a 需要转换为弧度
        sin_a = SIN(RADIANS(a))
        
        # 计算第二项: 0.50572 * (a + 6.07995)^(-1.6364)
        # 注意：当 a 很小时，这个公式仍然有效
        term2 = 0.50572 * ((a + 6.07995) ** (-1.6364))
        
        # 计算大气质量
        m = 1 / (sin_a + term2)
        return m
    else:
        return None  # 太阳在地平线以下时返回 None
 
# 修改后的循环部分
time_str = '2023-5-23 6:00:00'  # 从6:00开始
time = datetime.strptime(time_str, '%Y-%m-%d %H:%M:%S')

# 假设的IN数据（27个数据，请根据实际情况替换）
IN_data = [21.132,64.906
,155.472 
,265.660 
,372.830 
,499.623 
,587.170 
,643.019 
,688.302 
,727.547 
,736.604 
,747.170 
,750.189 
,754.717 
,762.264 
,744.151 
,733.585 
,698.868 
,653.585 
,605.283 
,546.415 
,464.906 
,377.358 
,271.698 
,125.283 
,48.302 
,10.566 
] 

# 存储结果的列表
results = []
altitudes = []
ln_values = []
m_values = []
time_points = []

print("\n" + "="*80)
print("计算结果：ln(IN / sin(a)) 和 大气质量 m")
print("="*80)

# 从6:00到19:00，每隔30分钟计算一次
for i in range(27):  # 6:00到19:00共27个时间点
    # 计算当前时间
    current_time = time + timedelta(minutes=30 * i)
    
    # 如果超过19:00则停止
    if current_time.hour > 19 or (current_time.hour == 19 and current_time.minute > 0):
        break
    
    print(f"\n=== 时间点 {i+1}: {current_time.strftime('%H:%M')} ===")
    sun_altitude, sun_azimuth = CalculateSunPosition(30.35, 114.19, current_time)
    
    # 计算 sin(a)，其中 a 是太阳高度角（转换为弧度）
    a_radians = RADIANS(sun_altitude)
    sin_a = SIN(a_radians)
    
    # 获取对应的 IN 值
    IN = IN_data[i]
    
    # 计算 ln(IN / sin(a))
    # 注意：需要确保 sin_a > 0，否则除以0或负数会出错
    if sin_a > 0:
        ln_value = math.log(IN / sin_a)
    else:
        ln_value = None  # 当sin(a) <= 0时无法计算
        print(f"警告：sin(a) = {sin_a}，无法计算ln值")
    
    # 计算大气质量 m
    m = CalculateAirMass(sun_altitude)
    
     # 存储结果
    results.append({
        'time': current_time,
        'altitude': sun_altitude,
        'azimuth': sun_azimuth,
        'sin_a': sin_a,
        'IN': IN,
        'ln_value': ln_value,
        'm': m
    })
    
    # 收集有效数据用于拟合
    if ln_value is not None and m is not None:
        m_values.append(m)
        ln_values.append(ln_value)
        time_points.append(current_time)
    

    # 输出结果
    print(f"太阳高度角 a = {sun_altitude:.4f}°")
    print(f"太阳方位角 = {sun_azimuth:.4f}°")
    print(f"sin(a) = {sin_a:.6f}")
    print(f"IN = {IN}")
    if ln_value is not None:
        print(f"ln(IN / sin(a)) = {ln_value:.6f}")
    else:
        print(f"ln(IN / sin(a)) = 无法计算")
    
    if m is not None:
        print(f"大气质量 m = {m:.6f}")
    else:
        print(f"大气质量 m = 无法计算（太阳高度角≤0）")
    print("-"*50)

# 输出汇总表格
print("\n" + "="*120)
print("汇总表格")
print("="*120)
print(f"{'序号':<6} {'时间':<10} {'高度角(°)':<12} {'方位角(°)':<12} {'sin(a)':<12} {'IN':<10} {'ln(IN/sin(a))':<18} {'m':<12}")
print("-"*120)

for i, result in enumerate(results):
    time_str = result['time'].strftime('%H:%M')
    ln_display = f"{result['ln_value']:.6f}" if result['ln_value'] is not None else "无法计算"
    m_display = f"{result['m']:.6f}" if result['m'] is not None else "无法计算"
    print(f"{i+1:<6} {time_str:<10} {result['altitude']:<12.4f} {result['azimuth']:<12.4f} {result['sin_a']:<12.6f} {result['IN']:<10} {ln_display:<18} {m_display:<12}")

# ========== 数据剔除优化：寻找最大R² ==========
print("\n" + "="*120)
print("数据剔除优化：寻找最大 R² 对应的 u 值")
print("="*120)

# 原始数据
original_m = np.array(m_values)
original_ln = np.array(ln_values)
n_total = len(original_m)

print(f"\n总数据点数: {n_total}")
print(f"理论公式: ln(IN/sin(a)) = ln(1334) - u * m")
print(f"ln(1334) = {math.log(1334):.6f}")

# 存储所有剔除方案的结果
results_fitting = []

# 方案1：不剔除任何数据
coefficients_full = np.polyfit(original_m, original_ln, 1)
u_full = -coefficients_full[0]
ln_pred_full = np.polyval(coefficients_full, original_m)
ss_res_full = np.sum((original_ln - ln_pred_full) ** 2)
ss_tot_full = np.sum((original_ln - np.mean(original_ln)) ** 2)
r2_full = 1 - (ss_res_full / ss_tot_full)

results_fitting.append({
    'type': '全部数据',
    'indices': list(range(n_total)),
    'n': n_total,
    'u': u_full,
    'r2': r2_full,
    'm_data': original_m,
    'ln_data': original_ln,
    'coefficients': coefficients_full
})

print(f"\n【全部数据】数据点数: {n_total}, u = {u_full:.8f}, R² = {r2_full:.6f}")

# 方案2：每次剔除前后各一个数据（对称剔除）
# 从剔除1对开始，到最多剔除 floor(n_total/2) 对
max_pairs_to_remove = n_total // 2

for n_remove in range(1, max_pairs_to_remove + 1):
    # 剔除前 n_remove 个和后 n_remove 个数据
    start_idx = n_remove
    end_idx = n_total - n_remove
    
    if start_idx >= end_idx:
        break
    
    m_trimmed = original_m[start_idx:end_idx]
    ln_trimmed = original_ln[start_idx:end_idx]
    n_remaining = len(m_trimmed)
    
    # 进行线性拟合
    coeff = np.polyfit(m_trimmed, ln_trimmed, 1)
    u_temp = -coeff[0]
    
    # 计算R²
    ln_pred = np.polyval(coeff, m_trimmed)
    ss_res = np.sum((ln_trimmed - ln_pred) ** 2)
    ss_tot = np.sum((ln_trimmed - np.mean(ln_trimmed)) ** 2)
    r2_temp = 1 - (ss_res / ss_tot)
    
    results_fitting.append({
        'type': f'剔除前{n_remove}后{n_remove}个',
        'indices': list(range(start_idx, end_idx)),
        'n': n_remaining,
        'u': u_temp,
        'r2': r2_temp,
        'm_data': m_trimmed,
        'ln_data': ln_trimmed,
        'coefficients': coeff,
        'n_removed': n_remove
    })
    
    print(f"【剔除前{n_remove}后{n_remove}个】数据点数: {n_remaining}, u = {u_temp:.8f}, R² = {r2_temp:.6f}")

# 方案3：不对称剔除（尝试不同的前后剔除组合）
print("\n" + "-"*80)
print("尝试不对称剔除组合...")
print("-"*80)

for remove_front in range(1, 6):  # 剔除前1-5个
    for remove_back in range(1, 6):  # 剔除后1-5个
        start_idx = remove_front
        end_idx = n_total - remove_back
        
        if start_idx >= end_idx:
            continue
        
        m_trimmed = original_m[start_idx:end_idx]
        ln_trimmed = original_ln[start_idx:end_idx]
        n_remaining = len(m_trimmed)
        
        if n_remaining < 3:  # 至少需要3个点进行拟合
            continue
        
        coeff = np.polyfit(m_trimmed, ln_trimmed, 1)
        u_temp = -coeff[0]
        
        ln_pred = np.polyval(coeff, m_trimmed)
        ss_res = np.sum((ln_trimmed - ln_pred) ** 2)
        ss_tot = np.sum((ln_trimmed - np.mean(ln_trimmed)) ** 2)
        r2_temp = 1 - (ss_res / ss_tot)
        
        results_fitting.append({
            'type': f'剔除前{remove_front}后{remove_back}个',
            'indices': list(range(start_idx, end_idx)),
            'n': n_remaining,
            'u': u_temp,
            'r2': r2_temp,
            'm_data': m_trimmed,
            'ln_data': ln_trimmed,
            'coefficients': coeff,
            'remove_front': remove_front,
            'remove_back': remove_back
        })
        
        print(f"剔除前{remove_front}后{remove_back}个: 数据点数={n_remaining:2d}, u={u_temp:.8f}, R²={r2_temp:.6f}")

# 找出R²最大的方案
best_result = max(results_fitting, key=lambda x: x['r2'])

print("\n" + "="*120)
print("【最优拟合结果】")
print("="*120)
print(f"最佳剔除方案: {best_result['type']}")
print(f"使用数据点数: {best_result['n']}")
print(f"拟合得到的 u = {best_result['u']:.10f}")
print(f"拟合优度 R² = {best_result['r2']:.8f}")

# 显示使用的数据范围
if 'n_removed' in best_result:
    print(f"剔除的数据: 前{best_result['n_removed']}个和后{best_result['n_removed']}个")
elif 'remove_front' in best_result:
    print(f"剔除的数据: 前{best_result['remove_front']}个和后{best_result['remove_back']}个")

# 计算拟合直线的截距（应该接近 ln(1334)）
best_coeff = best_result['coefficients']
a_fit = best_coeff[1]  # 截距
b_fit = best_coeff[0]  # 斜率
print(f"\n拟合直线方程: ln(IN/sin(a)) = {a_fit:.8f} + ({b_fit:.8f}) * m")
print(f"拟合得到的 ln(1334) = {a_fit:.8f} (理论值: {math.log(1334):.8f})")
print(f"拟合得到的斜率 = {b_fit:.8f}")
print(f"u = -斜率 = {best_result['u']:.10f}")

# ========== 可视化比较 ==========
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))

# 图1：全部数据的拟合
m_range = np.linspace(min(original_m), max(original_m), 100)
ln_fit_full = math.log(1334) - u_full * m_range

ax1.scatter(original_m, original_ln, color='blue', s=50, alpha=0.6, label='全部数据点')
ax1.plot(m_range, ln_fit_full, color='red', linewidth=2, label=f'拟合: u={u_full:.6f}, R²={r2_full:.6f}')
ax1.axhline(y=math.log(1334), color='green', linestyle='--', alpha=0.5, label=f'ln(1334)={math.log(1334):.4f}')
ax1.set_xlabel('大气质量 m', fontsize=12)
ax1.set_ylabel('ln(IN / sin(a))', fontsize=12)
ax1.set_title('全部数据拟合结果', fontsize=14)
ax1.legend()
ax1.grid(True, alpha=0.3)

# 图2：最优拟合结果
best_m = best_result['m_data']
best_ln = best_result['ln_data']
best_coeff = best_result['coefficients']
ln_fit_best = np.polyval(best_coeff, m_range)

ax2.scatter(best_m, best_ln, color='green', s=50, alpha=0.6, label='保留的数据点')

# 标记被剔除的数据点
if 'n_removed' in best_result:
    removed_front = best_result['n_removed']
    removed_back = best_result['n_removed']
    front_indices = list(range(removed_front))
    back_indices = list(range(n_total - removed_back, n_total))
    removed_indices = front_indices + back_indices
    removed_m = original_m[removed_indices]
    removed_ln = original_ln[removed_indices]
    ax2.scatter(removed_m, removed_ln, color='red', s=50, alpha=0.6, marker='x', label='剔除的数据点')
elif 'remove_front' in best_result:
    remove_front = best_result['remove_front']
    remove_back = best_result['remove_back']
    front_indices = list(range(remove_front))
    back_indices = list(range(n_total - remove_back, n_total))
    removed_indices = front_indices + back_indices
    removed_m = original_m[removed_indices]
    removed_ln = original_ln[removed_indices]
    ax2.scatter(removed_m, removed_ln, color='red', s=50, alpha=0.6, marker='x', label='剔除的数据点')

ax2.plot(m_range, ln_fit_best, color='blue', linewidth=2, label=f'拟合: u={best_result["u"]:.6f}, R²={best_result["r2"]:.6f}')
ax2.axhline(y=math.log(1334), color='orange', linestyle='--', alpha=0.5, label=f'ln(1334)={math.log(1334):.4f}')
ax2.set_xlabel('大气质量 m', fontsize=12)
ax2.set_ylabel('ln(IN / sin(a))', fontsize=12)
ax2.set_title(f'最优拟合结果 (R² = {best_result["r2"]:.6f})', fontsize=14)
ax2.legend()
ax2.grid(True, alpha=0.3)

# 图3：不同剔除方案的R²变化
remove_counts = []
r2_values = []
u_values = []

for result in results_fitting:
    if 'n_removed' in result:
        remove_counts.append(result['n_removed'])
        r2_values.append(result['r2'])
        u_values.append(result['u'])

# 按剔除数量排序
sorted_indices = np.argsort(remove_counts)
remove_counts_sorted = [remove_counts[i] for i in sorted_indices]
r2_sorted = [r2_values[i] for i in sorted_indices]
u_sorted = [u_values[i] for i in sorted_indices]

ax3.plot(remove_counts_sorted, r2_sorted, 'bo-', linewidth=2, markersize=8)
ax3.axhline(y=r2_full, color='red', linestyle='--', alpha=0.7, label=f'全部数据 R²={r2_full:.6f}')
ax3.axvline(x=best_result.get('n_removed', 0), color='green', linestyle='--', alpha=0.7, label=f'最优剔除数={best_result.get("n_removed", 0)}')
ax3.set_xlabel('剔除前后数据对数', fontsize=12)
ax3.set_ylabel('R²', fontsize=12)
ax3.set_title('不同剔除方案下的 R² 变化（对称剔除）', fontsize=14)
ax3.legend()
ax3.grid(True, alpha=0.3)

# 图4：最优拟合的残差分布
residuals_best = best_ln - np.polyval(best_coeff, best_m)
ax4.scatter(best_m, residuals_best, color='purple', s=50, alpha=0.6)
ax4.axhline(y=0, color='red', linestyle='--', linewidth=2)
ax4.set_xlabel('大气质量 m', fontsize=12)
ax4.set_ylabel('残差', fontsize=12)
ax4.set_title(f'最优拟合残差分布 (标准差: {np.std(residuals_best):.6f})', fontsize=14)
ax4.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# ========== 保存结果到文件 ==========
import os
current_dir = os.getcwd()
file_path = os.path.join(current_dir, 'summary_table_with_optimization.txt')

with open(file_path, 'w', encoding='utf-8') as f:
    f.write("太阳位置、ln(IN/sin(a))及大气质量m计算结果汇总表（含数据剔除优化）\n")
    f.write("="*120 + "\n")
    f.write(f"计算日期: 2023-05-23\n")
    f.write(f"计算地点: 纬度 30.35°, 经度 114.19°\n")
    f.write(f"时间范围: 6:00 - 19:00 (每30分钟一次)\n")
    f.write("="*120 + "\n\n")
    
    f.write(f"{'序号':<6} {'时间':<10} {'高度角(°)':<12} {'方位角(°)':<12} {'sin(a)':<12} {'IN':<10} {'ln(IN/sin(a))':<18} {'m':<12}\n")
    f.write("-"*120 + "\n")
    
    for i, result in enumerate(results):
        time_str = result['time'].strftime('%H:%M')
        ln_display = f"{result['ln_value']:.6f}" if result['ln_value'] is not None else "无法计算"
        m_display = f"{result['m']:.6f}" if result['m'] is not None else "无法计算"
        f.write(f"{i+1:<6} {time_str:<10} {result['altitude']:<12.4f} {result['azimuth']:<12.4f} {result['sin_a']:<12.6f} {result['IN']:<10} {ln_display:<18} {m_display:<12}\n")
    
    # 添加拟合优化结果
    f.write("\n" + "="*120 + "\n")
    f.write("数据剔除优化拟合结果\n")
    f.write("="*120 + "\n\n")
    
    f.write("【全部数据拟合】\n")
    f.write(f"数据点数: {n_total}\n")
    f.write(f"u = {u_full:.10f}\n")
    f.write(f"R² = {r2_full:.8f}\n\n")
    
    f.write("【最优拟合结果】\n")
    f.write(f"最佳剔除方案: {best_result['type']}\n")
    f.write(f"使用数据点数: {best_result['n']}\n")
    f.write(f"拟合得到的 u = {best_result['u']:.10f}\n")
    f.write(f"拟合优度 R² = {best_result['r2']:.8f}\n")
    f.write(f"拟合直线方程: ln(IN/sin(a)) = {a_fit:.8f} + ({b_fit:.8f}) * m\n")
    f.write(f"拟合得到的 ln(1334) = {a_fit:.8f} (理论值: {math.log(1334):.8f})\n\n")
    
    f.write("【各剔除方案详细结果】\n")
    f.write("-"*80 + "\n")
    f.write(f"{'方案':<25} {'数据点数':<10} {'u值':<18} {'R²':<12}\n")
    f.write("-"*80 + "\n")
    
    for result in results_fitting:
        f.write(f"{result['type']:<25} {result['n']:<10} {result['u']:<18.10f} {result['r2']:<12.8f}\n")
    
    # 添加统计信息
    f.write("\n" + "="*120 + "\n")
    f.write("统计信息:\n")
    valid_ln = [r['ln_value'] for r in results if r['ln_value'] is not None]
    valid_m = [r['m'] for r in results if r['m'] is not None]
    
    if valid_ln:
        f.write(f"ln(IN/sin(a)) 有效数据点数: {len(valid_ln)}/{len(results)}\n")
        f.write(f"ln(IN/sin(a)) 最大值: {max(valid_ln):.6f}\n")
        f.write(f"ln(IN/sin(a)) 最小值: {min(valid_ln):.6f}\n")
        f.write(f"ln(IN/sin(a)) 平均值: {sum(valid_ln)/len(valid_ln):.6f}\n")
    
    if valid_m:
        f.write(f"\n大气质量 m 有效数据点数: {len(valid_m)}/{len(results)}\n")
        f.write(f"大气质量 m 最大值: {max(valid_m):.6f}\n")
        f.write(f"大气质量 m 最小值: {min(valid_m):.6f}\n")
        f.write(f"大气质量 m 平均值: {sum(valid_m)/len(valid_m):.6f}\n")

print("\n" + "="*120)
print(f"完整结果（含数据剔除优化）已保存到: {file_path}")
print("="*120)

# ========== 计算 IP 最大值 ==========
print("\n" + "="*120)
print("计算不同倾角 b 下的 IP 最大值")
print("="*120)

# 固定参数
u = 0.5424363799

# 已知 I0 数据（12个月）
I0_data = [1405,1394,1378,1353,1334,1316,1308,1315,1330,1350,1372,1392]

# b 取值
b_values = [20, 40, 60]

# 存储结果
IP_results = {}

for b in b_values:

    print(f"\n===== b = {b}° =====")

    max_IP = -1
    max_info = None

    # 遍历12组 I0
    for month_idx, I0 in enumerate(I0_data):

        # 遍历所有时间点
        for result in results:

            a = result['altitude']   # 太阳高度角
            f = result['azimuth']    # 太阳方位角
            m = result['m']

            # 太阳在地平线以下时跳过
            if a <= 0 or m is None:
                continue

            # 转弧度
            a_rad = math.radians(a)
            b_rad = math.radians(b)
            f_rad = math.radians(f)

            # 计算 IN
            IN = I0 * math.exp(-u * m) * math.sin(a_rad)

            # 计算 cos(y)
            cos_y = (
                math.sin(a_rad) * math.sin(b_rad)
                - math.cos(a_rad) * math.cos(b_rad) * math.cos(f_rad)
            )

            # 计算 IP
            IP = IN * cos_y

            # 更新最大值
            if IP > max_IP:
                max_IP = IP
                max_info = {
                    'month': month_idx + 1,
                    'time': result['time'].strftime('%H:%M'),
                    'a': a,
                    'f': f,
                    'm': m,
                    'I0': I0,
                    'IN': IN,
                    'cos_y': cos_y,
                    'IP': IP
                }

    IP_results[b] = max_info

    # 输出结果
    print(f"最大 IP = {max_info['IP']:.6f}")
    print(f"对应月份 = {max_info['month']}")
    print(f"对应时间 = {max_info['time']}")
    print(f"I0 = {max_info['I0']}")
    print(f"太阳高度角 a = {max_info['a']:.4f}°")
    print(f"太阳方位角 f = {max_info['f']:.4f}°")
    print(f"大气质量 m = {max_info['m']:.6f}")
    print(f"IN = {max_info['IN']:.6f}")
    print(f"cos(y) = {max_info['cos_y']:.6f}")

# ========== 汇总 ==========
print("\n" + "="*120)
print("最终结果汇总")
print("="*120)

for b in b_values:
    info = IP_results[b]

    print(
        f"b={b:2d}° : "
        f"最大IP={info['IP']:.6f}, "
        f"月份={info['month']}, "
        f"时间={info['time']}"
    )

# ========== 计算积分 E = ∫ IP * dt ==========
print("\n" + "="*120)
print("计算积分 E = ∫ IP * dt (时间范围: 6:00 - 12:00)")
print("="*120)

# 固定参数
u = 0.5424363799  # 拟合得到的 u 值
A = 1  # 面积 A = 1
dt_seconds = 30 * 60  # 30分钟 = 1800秒

# 时间范围：只计算 6:00 到 12:00 的数据
start_hour = 6
end_hour = 12

print(f"\n计算参数:")
print(f"  u = {u}")
print(f"  A = {A}")
print(f"  时间间隔 dt = {dt_seconds} 秒")
print(f"  时间范围: {start_hour}:00 - {end_hour}:00")

# 存储每个 b 的积分结果
integral_results = {}

for b in b_values:
    print(f"\n{'='*60}")
    print(f"b = {b}°")
    print(f"{'='*60}")
    
    # 初始化总积分
    total_E = 0
    
    # 存储每个时间点的详细数据
    time_data = []
    
    # 遍历所有时间点（按时间顺序）
    for i, result in enumerate(results):
        current_time = result['time']
        current_hour = current_time.hour
        
        # 只计算 6:00 到 12:00 之间的时间点（包括12:00）
        if current_hour < start_hour or current_hour > end_hour:
            continue
        
        a = result['altitude']   # 太阳高度角
        f = result['azimuth']    # 太阳方位角
        m = result['m']
        
        # 太阳在地平线以下时跳过
        if a <= 0 or m is None:
            print(f"  {current_time.strftime('%H:%M')}: 太阳在地平线以下，跳过")
            continue
        
        # 转换角度为弧度
        a_rad = math.radians(a)
        b_rad = math.radians(b)
        f_rad = math.radians(f)
        
        # 计算 IN = I0 * exp(-u * m) * sin(a)
        # 注意：这里 I0 需要根据月份确定，由于积分是从6:00到12:00，
        # 我们使用对应日期的 I0 值（5月23日对应的 I0 需要插值或取最接近的月份）
        # 5月23日最接近5月份，I0_5月 = 1334
        I0_current = 1334  # 5月份对应的 I0 值
        
        # 计算 IN
        IN = I0_current * math.exp(-u * m) * math.sin(a_rad)
        
        # 计算 cos(y)
        cos_y = (math.sin(a_rad) * math.sin(b_rad) - 
                 math.cos(a_rad) * math.cos(b_rad) * math.cos(f_rad))
        
        # 只有当 cos_y > 0 时才计算 IP（太阳光能照射到倾斜面）
        if cos_y <= 0:
            print(f"  {current_time.strftime('%H:%M')}: cos(y) = {cos_y:.6f} ≤ 0，跳过")
            continue
        
        # 计算 IP
        IP = IN * cos_y
        
        # 累加积分：E = Σ IP * dt * A
        dE = IP * dt_seconds * A
        total_E += dE
        
        # 记录详细数据
        time_data.append({
            'time': current_time,
            'a': a,
            'f': f,
            'm': m,
            'sin_a': math.sin(a_rad),
            'IN': IN,
            'cos_y': cos_y,
            'IP': IP,
            'dE': dE
        })
        
        print(f"  {current_time.strftime('%H:%M')}: "
              f"a={a:6.2f}°, f={f:6.2f}°, "
              f"IN={IN:8.4f}, cos(y)={cos_y:8.6f}, "
              f"IP={IP:8.4f}, dE={dE:10.2f}")
    
    # 存储积分结果
    integral_results[b] = {
        'total_E': total_E,
        'time_data': time_data,
        'point_count': len(time_data)
    }
    
    print(f"\n  {'─'*50}")
    print(f"  积分结果汇总:")
    print(f"    有效计算点数: {len(time_data)}")
    print(f"    总积分 E = {total_E:.6f} (J/m² 或 Wh 取决于单位)")
    
    # 如果需要转换为不同的单位
    total_E_Wh = total_E / 3600  # 转换为瓦时 (1 Wh = 3600 J)
    print(f"    总积分 E = {total_E_Wh:.6f} Wh/m²")

# ========== 输出最终汇总表格 ==========
print("\n" + "="*120)
print("最终积分结果汇总 (时间范围: 6:00 - 12:00)")
print("="*120)
print(f"{'b角度(°)':<12} {'总积分 E (J)':<20} {'总积分 E (Wh)':<20} {'有效点数':<12} {'最大IP位置':<20}")
print("-"*120)

for b in b_values:
    result = integral_results[b]
    total_E_J = result['total_E']
    total_E_Wh = total_E_J / 3600
    point_count = result['point_count']
    
    # 找出IP最大的时间点
    if result['time_data']:
        max_ip_point = max(result['time_data'], key=lambda x: x['IP'])
        max_ip_time = max_ip_point['time'].strftime('%H:%M')
        max_ip_value = max_ip_point['IP']
        max_ip_info = f"{max_ip_time} (IP={max_ip_value:.4f})"
    else:
        max_ip_info = "无有效数据"
    
    print(f"{b:<12} {total_E_J:<20.6f} {total_E_Wh:<20.6f} {point_count:<12} {max_ip_info:<20}")

# ========== 绘制积分结果图 ==========
fig2, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(14, 12))

# 颜色方案
colors = ['red', 'green', 'blue']
markers = ['o', 's', '^']

for idx, b in enumerate(b_values):
    result = integral_results[b]
    time_data = result['time_data']
    
    if time_data:
        # 提取时间点和 IP 值
        times = [d['time'].strftime('%H:%M') for d in time_data]
        ip_values = [d['IP'] for d in time_data]
        
        # 图1：IP 随时间变化
        ax1.plot(times, ip_values, color=colors[idx], marker=markers[idx], 
                linewidth=2, markersize=6, label=f'b={b}°')
        
        # 图2：累积积分曲线
        cumulative_E = []
        cum_sum = 0
        for d in time_data:
            cum_sum += d['dE']
            cumulative_E.append(cum_sum)
        ax2.plot(times, cumulative_E, color=colors[idx], marker=markers[idx],
                linewidth=2, markersize=6, label=f'b={b}°')
        
        # 图3：IP * cos(y) 各项贡献
        in_values = [d['IN'] for d in time_data]
        cos_y_values = [d['cos_y'] for d in time_data]
        ax3.plot(times, in_values, color=colors[idx], linestyle='-', 
                linewidth=1.5, alpha=0.7, label=f'IN (b={b}°)')
        ax3.plot(times, cos_y_values, color=colors[idx], linestyle='--', 
                linewidth=1.5, alpha=0.7, label=f'cos(y) (b={b}°)')

# 图1设置
ax1.set_xlabel('时间', fontsize=12)
ax1.set_ylabel('IP (W/m²)', fontsize=12)
ax1.set_title('不同倾角 b 下 IP 随时间变化 (6:00-12:00)', fontsize=14)
ax1.legend()
ax1.grid(True, alpha=0.3)
ax1.tick_params(axis='x', rotation=45)

# 图2设置
ax2.set_xlabel('时间', fontsize=12)
ax2.set_ylabel('累积积分 E (J/m²)', fontsize=12)
ax2.set_title('不同倾角 b 下累积积分曲线', fontsize=14)
ax2.legend()
ax2.grid(True, alpha=0.3)
ax2.tick_params(axis='x', rotation=45)

# 图3设置
ax3.set_xlabel('时间', fontsize=12)
ax3.set_ylabel('数值', fontsize=12)
ax3.set_title('IN 和 cos(y) 随时间变化', fontsize=14)
ax3.legend()
ax3.grid(True, alpha=0.3)
ax3.tick_params(axis='x', rotation=45)

plt.tight_layout()
plt.show()

# ========== 保存积分结果到文件 ==========
file_path_integral = os.path.join(current_dir, 'integral_results.txt')

with open(file_path_integral, 'w', encoding='utf-8') as f:
    f.write("太阳辐射积分计算结果 (6:00 - 12:00)\n")
    f.write("="*120 + "\n")
    f.write(f"计算日期: 2023-05-23\n")
    f.write(f"计算地点: 纬度 30.35°, 经度 114.19°\n")
    f.write(f"固定参数: u = {u}, A = {A}\n")
    f.write(f"时间间隔: dt = {dt_seconds} 秒\n")
    f.write("="*120 + "\n\n")
    
    for b in b_values:
        result = integral_results[b]
        f.write(f"\n{'='*60}\n")
        f.write(f"b = {b}°\n")
        f.write(f"{'='*60}\n")
        f.write(f"总积分 E = {result['total_E']:.8f} J/m²\n")
        f.write(f"总积分 E = {result['total_E']/3600:.8f} Wh/m²\n")
        f.write(f"有效数据点数: {result['point_count']}\n\n")
        
        f.write(f"{'时间':<12} {'高度角(°)':<12} {'方位角(°)':<12} {'IN':<15} {'cos(y)':<15} {'IP':<15} {'dE':<15}\n")
        f.write("-"*100 + "\n")
        
        for d in result['time_data']:
            f.write(f"{d['time'].strftime('%H:%M'):<12} "
                   f"{d['a']:<12.4f} "
                   f"{d['f']:<12.4f} "
                   f"{d['IN']:<15.6f} "
                   f"{d['cos_y']:<15.6f} "
                   f"{d['IP']:<15.6f} "
                   f"{d['dE']:<15.2f}\n")
    
    # 汇总表格
    f.write("\n" + "="*120 + "\n")
    f.write("积分结果汇总表\n")
    f.write("="*120 + "\n")
    f.write(f"{'b角度(°)':<12} {'总积分 E (J/m²)':<20} {'总积分 E (Wh/m²)':<20} {'有效点数':<12}\n")
    f.write("-"*120 + "\n")
    
    for b in b_values:
        result = integral_results[b]
        f.write(f"{b:<12} {result['total_E']:<20.8f} {result['total_E']/3600:<20.8f} {result['point_count']:<12}\n")

print("\n" + "="*120)
print(f"积分结果已保存到: {file_path_integral}")
print("="*120)

# ========== 输出最终结论 ==========
print("\n" + "="*120)
print("【最终结论】")
print("="*120)

# 找出积分最大的 b 值
max_E_b = max(integral_results.items(), key=lambda x: x[1]['total_E'])
print(f"在 b = {max_E_b[0]}° 时，积分 E 最大，值为 {max_E_b[1]['total_E']:.6f} J/m²")
print(f"即 {max_E_b[1]['total_E']/3600:.6f} Wh/m²")

print("\n各倾角积分对比:")
for b in b_values:
    result = integral_results[b]
    print(f"  b = {b:2d}°: E = {result['total_E']:10.4f} J/m² = {result['total_E']/3600:8.4f} Wh/m²")