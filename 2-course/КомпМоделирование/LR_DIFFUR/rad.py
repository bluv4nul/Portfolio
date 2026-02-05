import numpy as np
from scipy.integrate import solve_ivp


# 1. Задаем правило: как меняется система
def dmdt(t, m):
    return -k * m


# 2. Параметры
k = 0.00044
t_span = (0, 200)
m0 = [1]

# 3. Решаем
solution = solve_ivp(dmdt, t_span, m0, t_eval=[0, 200])

m200 = solution.y[0][1]

percent_decayed = (1 - m200) * 100
percent_remaining = m200 * 100

print(f"Начальная масса(в долях): 1, Масса через 200 лет: {m200:.4f}")
print(f"Распадется: {percent_decayed:.2f}%, Останется: {percent_remaining:.2f}%")
