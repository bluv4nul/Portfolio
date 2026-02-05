import numpy as np
from scipy.integrate import solve_ivp


def dvds(s, v):
    return -k * v


v0 = 12
v1 = 11.8
s1 = 1.0

# Из уравнения v1 = v0 * exp(-k * s1)
k = -np.log(v1 / v0) / s1

s_span = (0, 150)
v_start = [v0]
s_points = [150]

solution = solve_ivp(dvds, s_span, v_start, t_eval=s_points)

print(f"Скорость ветра после прохождения 150м = {solution.y[0][-1]:.4f} м/с")
