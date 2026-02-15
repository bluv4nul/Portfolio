import numpy as np
from scipy.integrate import solve_ivp


# 1. Задаем правило: как меняется система
def dNdt(t, N):
    return k * N  # "скорость распада = k * текущее количество"


# 2. Параметры
k = np.log(0.5) / 4  # коэффициент
t_span = (0, 20)  # от скольки до скольки часов решаем
N0 = [1]  # начальное количество = 1
t_points = list(range(0, 20 + 1, 2))  # в какие моменты записываем значения

# 3. Решаем
solution = solve_ivp(dNdt, t_span, N0, t_eval=t_points)

# 4. Смотрим результаты
# solution.t - массив времени
# solution.y[0] - массив значений N в эти моменты
for i in range(len(solution.t)):
    print(f"t: {solution.t[i]}, N:{solution.y[0][i]:.3f}")


# Зависимость: Количество лекарства уменьшается экспоненциально с периодом полураспада 4 часа.
