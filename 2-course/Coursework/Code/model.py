import numpy as np

from config import (
    WIDTH,
    HEIGHT,
    EMPTY,
    TREE,
    FIRE_1,
    FIRE_2,
    FIRE_3,
    BURNT,
    FIREBREAK,
    SPARK,
)

FIRE_STATES = [FIRE_1, FIRE_2, FIRE_3]


# -------------------------
# Создание территории
# -------------------------
def create_grid(params):
    grid = np.full((HEIGHT, WIDTH), EMPTY)

    for i in range(HEIGHT):
        for j in range(WIDTH):
            if np.random.random() < params["forest_density"]:
                grid[i, j] = TREE

    return grid


# -------------------------
# Получение вектора ветра
# -------------------------
def get_wind_vector(params):
    wind_vectors = {
        "up": (-1, 0),
        "down": (1, 0),
        "left": (0, -1),
        "right": (0, 1),
    }

    return wind_vectors[params["wind_direction"]]


# -------------------------
# Учет направления ветра
# -------------------------
def apply_wind(probability, spread_direction, params):
    wind_vector = get_wind_vector(params)

    # Если огонь распространяется по ветру
    if spread_direction == wind_vector:
        probability *= 1 + params["wind_strength"]

    # Если огонь распространяется против ветра
    elif spread_direction == (-wind_vector[0], -wind_vector[1]):
        probability *= 1 - params["wind_strength"]

    return min(probability, 1.0)


# -------------------------
# Расчет вероятности загорания клетки
# -------------------------
def get_ignition_probability(grid, i, j, params):
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

    # Проверка соседей по вертикали и горизонтали
    for di, dj in straight_directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] in FIRE_STATES:
                spread_direction = (i - ni, j - nj)

                current_probability = params["fire_probability"]
                current_probability = apply_wind(
                    current_probability,
                    spread_direction,
                    params,
                )

                probability = max(probability, current_probability)

    # Проверка соседей по диагонали
    for di, dj in diagonal_directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
            if grid[ni, nj] in FIRE_STATES:
                spread_direction = (i - ni, j - nj)

                current_probability = (
                    params["fire_probability"] * params["diagonal_factor"]
                )

                current_probability = apply_wind(
                    current_probability,
                    spread_direction,
                    params,
                )

                probability = max(probability, current_probability)

    # Влажность уменьшает вероятность загорания
    probability *= 1 - params["humidity"]

    return probability


# -------------------------
# Перенос искры ветром
# -------------------------
def try_create_spark(grid, new_grid, i, j, params):

    if params["wind_strength"] < 0.3:
        return new_grid

    di, dj = get_wind_vector(params)

    max_distance = params["max_spark_distance"]

    # Искра летит минимум на 2 клетки
    distance = np.random.randint(2, max_distance + 1)

    target_i = i + di * distance
    target_j = j + dj * distance

    # Если искра улетела за границы поля
    if not (0 <= target_i < HEIGHT and 0 <= target_j < WIDTH):
        return new_grid

    # Искра может попасть только на дерево
    if grid[target_i, target_j] != TREE:
        return new_grid

    probability = params["spark_probability"]

    # Искра летит по направлению ветра
    spread_direction = (di, dj)
    probability = apply_wind(probability, spread_direction, params)

    # Влажность уменьшает вероятность успешного переноса искры
    probability *= 1 - params["humidity"]

    probability = min(probability, 1.0)

    if np.random.random() < probability:
        new_grid[target_i, target_j] = SPARK

    return new_grid


# -------------------------
# Один шаг моделирования
# -------------------------
def update_grid(grid, params):
    new_grid = grid.copy()

    for i in range(HEIGHT):
        for j in range(WIDTH):

            if grid[i, j] == FIRE_1:
                # Горящая клетка может создать искру по направлению ветра
                new_grid = try_create_spark(grid, new_grid, i, j, params)

                # После шага горения клетка становится сгоревшей
                new_grid[i, j] = FIRE_2

            elif grid[i, j] == FIRE_2:
                # Горящая клетка может создать искру по направлению ветра
                new_grid = try_create_spark(grid, new_grid, i, j, params)

                # После шага горения клетка становится сгоревшей
                new_grid[i, j] = FIRE_3

            elif grid[i, j] == FIRE_3:
                # Горящая клетка может создать искру по направлению ветра
                new_grid = try_create_spark(grid, new_grid, i, j, params)

                # После шага горения клетка становится сгоревшей
                new_grid[i, j] = BURNT

            elif grid[i, j] == SPARK:
                # Искра на следующем шаге становится новым очагом пожара
                new_grid[i, j] = FIRE_1

            elif grid[i, j] == TREE:
                ignition_probability = get_ignition_probability(grid, i, j, params)

                if np.random.random() < ignition_probability:
                    new_grid[i, j] = FIRE_1

    return new_grid


# -------------------------
# Проверка наличия огня
# -------------------------
def has_fire(grid):
    return np.any(np.isin(grid, FIRE_STATES)) or np.any(grid == SPARK)


# -------------------------
# Поджог клетки
# -------------------------
def ignite_dot(grid, i=None, j=None):
    # Если координаты не переданы, выбирается случайное дерево
    if i is None or j is None or i < 0 or j < 0 or i >= HEIGHT or j >= WIDTH:
        while np.any(grid == TREE):
            i = np.random.randint(0, HEIGHT)
            j = np.random.randint(0, WIDTH)

            if grid[i, j] == TREE:
                grid[i, j] = FIRE_1
                return grid

    # Если координаты переданы, поджигается выбранная клетка
    else:
        if grid[i, j] == TREE:
            grid[i, j] = FIRE_1

    return grid


# -------------------------
# Рисование противопожарного разрыва
# -------------------------
def draw_firebreak(grid, i, j, brush_size):
    for di in range(-brush_size, brush_size + 1):
        for dj in range(-brush_size, brush_size + 1):
            ni = i + di
            nj = j + dj

            if 0 <= ni < HEIGHT and 0 <= nj < WIDTH:
                grid[ni, nj] = FIREBREAK

    return grid
