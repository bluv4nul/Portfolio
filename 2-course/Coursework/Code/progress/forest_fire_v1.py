"""
Версия 1 - пожар из центра, дискретное распрстранение, соседи только сверху, снизу справа и слева.
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

FIRE_PROBABILITY = 0.3

colors = ["white", "green", "orange", "black"]
cmap = ListedColormap(colors)


def create_grid():
    grid = np.full((HEIGHT, WIDTH), TREE)
    return grid


def ignite_center(grid):
    grid[HEIGHT // 2, WIDTH // 2] = FIRE
    return grid


def has_fire_neighbor(grid, i, j):
    directions = [
        (-1, 0),
        (1, 0),
        (0, -1),
        (0, 1),
    ]

    for di, dj in directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] == FIRE:
                return True

    return False


def update_grid(grid):
    new_grid = grid.copy()

    for i in range(HEIGHT):
        for j in range(WIDTH):
            if grid[i, j] == FIRE:
                new_grid[i, j] = BURNT

            elif grid[i, j] == TREE:
                if has_fire_neighbor(grid, i, j):
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
