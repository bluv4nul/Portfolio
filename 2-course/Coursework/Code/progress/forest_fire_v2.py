"""
Версия 2 — добавлена вероятность распространения огня.
Также используется соседство Мура: учитываются прямые и диагональные соседи.
Для диагональных соседей вероятность распространения уменьшается с помощью коэффициента DIAGONAL_FACTOR.
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

FIRE_PROBABILITY = 0.5
DIAGONAL_FACTOR = 0.7

colors = ["white", "green", "orange", "black"]
cmap = ListedColormap(colors)


def create_grid():
    grid = np.full((HEIGHT, WIDTH), TREE)
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
                probability = max(probability, FIRE_PROBABILITY)

    for di, dj in diagonal_directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] == FIRE:
                probability = max(probability, FIRE_PROBABILITY * DIAGONAL_FACTOR)

    return probability


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
