from scipy.integrate import quad
import numpy as np


def f(r_):
    return np.sqrt((r_ * r) / (2 * g * r_earth**2 * (r - r_)))


r_earth = 6.377 * 10**6  # м
r = 60.27 * r_earth  # м
g = 9.81  # м/с^2
k = g * (r_earth**2)  # коэффициент пропорциональности

t, err = quad(f, r_earth, r)

print(f"Время падения тела = {(t/3600):.0f} часов")
