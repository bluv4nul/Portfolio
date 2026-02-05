import numpy as np
from scipy.integrate import solve_ivp


def dIdt(t, I):
    return (E - R * I) / L


E = 300  # Напряжение, вольт
R = 150  # Сопротивление, Ом
L = 30  # Коэффициент самоиндукции, Гн
I_lim = E / R  # Предельный ток
I_target = 0.99 * I_lim


t_span = (0, 2)
t_points = np.linspace(0, 2, 10**6)
I0 = [0]


solution = solve_ivp(dIdt, t_span, I0, t_eval=t_points)

target_time = None
for i in range(len(solution.t)):
    if solution.y[0][i] >= I_target:
        target_time = solution.t[i]
        break

print(f"\nТок достиг 99% от предельного значения за {target_time:.4f} секунд")
print(f"При t = {target_time:.6f} с, I = {solution.y[0][i]:.6f} А")
