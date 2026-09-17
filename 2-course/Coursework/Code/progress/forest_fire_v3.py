"""
Версия 3 — вероятностная модель распространения лесного пожара
с учётом параметров среды.

В модели используется двумерный клеточный автомат.
Каждая клетка может быть пустой, деревом, горящей или сгоревшей.

Добавленные параметры:
- плотность леса: задаёт долю клеток, занятых деревьями;
- влажность: уменьшает вероятность возгорания;
- ветер: изменяет вероятность распространения огня в зависимости от направления;
- диагональное распространение: учитывается с пониженной вероятностью.

Огонь распространяется вероятностно: дерево загорается только в том случае,
если рядом есть горящая клетка и случайное число меньше рассчитанной вероятности возгорания.
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap

WIDTH = 150
HEIGHT = 150

EMPTY = 0
TREE = 1
FIRE = 2
BURNT = 3

FIRE_PROBABILITY = 0.55
DIAGONAL_FACTOR = 0.7

FOREST_DENSITY = 0.85
HUMIDITY = 0.1
WIND_DIRECTION = "down"
WIND_STRENGTH = 0.4


colors = ["darkgoldenrod", "darkgreen", "red", "dimgrey"]
cmap = ListedColormap(colors)


def create_grid():
    grid = np.full((HEIGHT, WIDTH), EMPTY)
    for i in range(HEIGHT):
        for j in range(WIDTH):
            if np.random.random() < FOREST_DENSITY:
                grid[i, j] = TREE
    return grid


def ignite_center(grid):
    grid[HEIGHT // 2, WIDTH // 2] = FIRE
    return grid


def get_ignition_probability(grid, i, j):
    probability = 0.0

    straight_directions = [
        (-1, 0),
        (1, 0),
        (0, -1),
        (0, 1),
    ]

    diagonal_directions = [
        (-1, -1),
        (-1, 1),
        (1, -1),
        (1, 1),
    ]

    for di, dj in straight_directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] == FIRE:
                spread_direction = (i - ni, j - nj)
                current_probability = FIRE_PROBABILITY
                current_probability = apply_wind(current_probability, spread_direction)

                probability = max(probability, current_probability)

    for di, dj in diagonal_directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] == FIRE:
                spread_direction = (i - ni, j - nj)
                current_probability = FIRE_PROBABILITY * DIAGONAL_FACTOR
                current_probability = apply_wind(current_probability, spread_direction)

                probability = max(probability, current_probability)

    probability *= 1 - HUMIDITY

    return probability


def apply_wind(probability, spread_direction):
    wind_vectors = {
        "up": (-1, 0),
        "down": (1, 0),
        "left": (0, -1),
        "right": (0, 1),
    }

    wind_vector = wind_vectors[WIND_DIRECTION]

    if spread_direction == wind_vector:
        probability *= 1 + WIND_STRENGTH

    elif spread_direction == (-wind_vector[0], -wind_vector[1]):
        probability *= 1 - WIND_STRENGTH

    return min(probability, 1.0)


def update_grid(grid):
    new_grid = grid.copy()

    for i in range(HEIGHT):
        for j in range(WIDTH):

            if grid[i, j] == FIRE:
                new_grid[i, j] = BURNT

            elif grid[i, j] == TREE:
                ignition_probability = get_ignition_probability(grid, i, j)

                if np.random.random() < ignition_probability:
                    new_grid[i, j] = FIRE

    return new_grid


def has_fire(grid):
    return np.any(grid == FIRE)


grid = create_grid()
grid = ignite_center(grid)

plt.ion()

fig, ax = plt.subplots(figsize=(8, 8))
image = ax.imshow(grid, cmap=cmap, vmin=0, vmax=3, interpolation="nearest")
ax.axis("off")

step = 0

while has_fire(grid):
    image.set_data(grid)
    ax.set_title(f"Fire Simulation — Step {step}")

    plt.pause(0.05)

    grid = update_grid(grid)
    step += 1

image.set_data(grid)
ax.set_title(f"Fire Simulation — Finished at step {step}")
plt.pause(0.5)

plt.ioff()
plt.show()
