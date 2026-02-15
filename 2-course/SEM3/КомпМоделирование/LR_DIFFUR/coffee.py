import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt


def dTdt(t, T):
    return -r * (T - Ts)


Ts = 22  # температура среды, градусы
T0 = 83  # начальная температура кофе
r = 0.0373  # коэфф. остывания
T_comfort = 50

t_span = (0, 120)
t_points = np.linspace(0, 120, 10**6)

solution = solve_ivp(dTdt, t_span, [T0], t_eval=t_points)

for i in range(len(solution.t)):
    if solution.y[0][i] <= T_comfort:
        print(f"Комфортная температура кофе: {T_comfort} градусов")
        print(
            f"Кофе остыл до {solution.y[0][i]:.4f} град. за {solution.t[i]:.1f} минут"
        )
        break


X = solution.t
Y = solution.y[0]

plt.title("Процесс остывания кофе")
plt.xlabel("t, м")
plt.ylabel("T, градусы")
plt.grid(True, alpha=0.5)

plt.plot(X, Y)

plt.show()
