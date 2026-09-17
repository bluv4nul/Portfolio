import turtle
import math

# ==============================
# Выбор пресета
# ==============================

print("Фрактальное дерево Пифагора")
print()
print("Выберите вариант построения:")
print("1 — классическое симметричное дерево")
print("2 — наклонённое дерево")
print("3 — плотное цветное дерево")
print("4 — пользовательские параметры")
print()

preset = input("Введите номер варианта: ").strip()


# Значения по умолчанию
size = 100
depth = 8
angle = 45
color_mode = False


if preset == "1":
    # Классический вариант
    size = 100
    depth = 9
    angle = 45
    color_mode = False

elif preset == "2":
    # Асимметричный вариант
    size = 100
    depth = 10
    angle = 35
    color_mode = False

elif preset == "3":
    # Цветной вариант для красивого изображения
    size = 100
    depth = 10
    angle = 40
    color_mode = True

elif preset == "4":
    # Ручной ввод параметров
    try:
        size = float(input("Введите размер основания дерева, например 100: "))
        depth = int(input("Введите глубину рекурсии, например 8 или 10: "))
        angle = float(input("Введите угол наклона в градусах, например 45: "))
    except ValueError:
        print("Ошибка ввода. Используются значения по умолчанию.")
        size = 100
        depth = 8
        angle = 45

    print()
    print("Выберите режим отображения:")
    print("1 — демонстрационный режим")
    print("2 — цветной режим")
    mode = input("Введите номер режима: ").strip()

    color_mode = mode == "2"

else:
    print("Такого варианта нет. Используется классический пресет.")
    size = 100
    depth = 9
    angle = 45
    color_mode = False


# ==============================
# Проверка параметров
# ==============================

if depth < 1:
    print("Глубина не может быть меньше 1. Установлено значение 1.")
    depth = 1

if depth > 12:
    print("Слишком большая глубина. Установлено максимальное значение 12.")
    depth = 12

if angle <= 0 or angle >= 90:
    print("Угол должен быть больше 0 и меньше 90. Используется угол 45.")
    angle = 45

if size <= 0:
    print("Размер должен быть положительным. Используется размер 100.")
    size = 100


# ==============================
# Настройка окна
# ==============================

WINDOW_WIDTH = 1000
WINDOW_HEIGHT = 800

screen = turtle.Screen()
screen.title("Фрактальное дерево Пифагора")
screen.setup(width=WINDOW_WIDTH, height=WINDOW_HEIGHT)

if color_mode:
    screen.bgcolor("lightblue")
else:
    screen.bgcolor("white")

# Отключаем пошаговую анимацию для ускорения
screen.tracer(0)


# ==============================
# Масштабирование
# ==============================

aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT

# Для симметричного дерева можно сделать масштаб крупнее
if 38 <= angle <= 52:
    world_height = size * 4.2
else:
    world_height = size * 5.0

world_width = world_height * aspect_ratio

screen.setworldcoordinates(
    -world_width / 2, -world_height * 0.30, world_width / 2, world_height * 0.80
)


# ==============================
# Настройка черепашек
# ==============================

t = turtle.Turtle()
t.speed(0)
t.hideturtle()

text_turtle = turtle.Turtle()
text_turtle.speed(0)
text_turtle.hideturtle()
text_turtle.penup()


# Цвета от основания к верхним ветвям
colors = [
    "saddlebrown",
    "sienna",
    "peru",
    "darkolivegreen",
    "olivedrab",
    "forestgreen",
    "green",
    "limegreen",
    "yellowgreen",
]


# ==============================
# Функции
# ==============================


def draw_square(square_size, color, line_width):
    """Рисует квадрат и возвращает черепашку назад."""

    start_pos = t.position()
    start_heading = t.heading()

    t.width(line_width)

    if color_mode:
        t.pencolor(color)
        t.fillcolor(color)
        t.begin_fill()
    else:
        t.pencolor("black")

    for _ in range(4):
        t.forward(square_size)
        t.left(90)

    if color_mode:
        t.end_fill()

    t.penup()
    t.setposition(start_pos)
    t.setheading(start_heading)
    t.pendown()


def move_to_top_left(square_size):
    """Переход в верхний левый угол квадрата."""

    t.penup()
    t.left(90)
    t.forward(square_size)
    t.right(90)
    t.pendown()


def draw_tree(square_size, current_depth, angle, max_depth):
    """Рекурсивно строит фрактальное дерево Пифагора."""

    if current_depth == 0:
        return

    start_pos = t.position()
    start_heading = t.heading()

    # Цвет зависит от уровня рекурсии
    color_index = max_depth - current_depth
    color_index = min(color_index, len(colors) - 1)
    color = colors[color_index]

    # В демонстрационном режиме линии тонкие
    if color_mode:
        line_width = max(1, current_depth / 3)
    else:
        line_width = 1

    draw_square(square_size, color, line_width)

    # Последний уровень не разветвляется
    if current_depth == 1:
        t.penup()
        t.setposition(start_pos)
        t.setheading(start_heading)
        t.pendown()
        return

    move_to_top_left(square_size)

    # Размеры дочерних квадратов зависят от угла
    angle_rad = math.radians(angle)

    left_size = square_size * math.cos(angle_rad)
    right_size = square_size * math.sin(angle_rad)

    # Левая ветвь
    t.left(angle)
    draw_tree(left_size, current_depth - 1, angle, max_depth)

    # Правая ветвь
    t.forward(left_size)
    t.right(90)
    draw_tree(right_size, current_depth - 1, angle, max_depth)

    # Возврат в начальное положение ветви
    t.penup()
    t.setposition(start_pos)
    t.setheading(start_heading)
    t.pendown()


def write_info():
    """Выводит параметры построения на экран."""

    if color_mode:
        mode_name = "цветной"
    else:
        mode_name = "демонстрационный"

    # Подпись вынесена в верхнюю левую часть окна
    text_turtle.goto(-world_width / 2 + 20, world_height * 0.70)
    text_turtle.pencolor("black")

    text = (
        "Фрактальное дерево Пифагора\n"
        f"Размер основания: {size}\n"
        f"Глубина рекурсии: {depth}\n"
        f"Угол ветвления: {angle}°\n"
        f"Режим: {mode_name}"
    )

    text_turtle.write(text, align="left", font=("Arial", 12, "normal"))


# ==============================
# Запуск программы
# ==============================

# Начальная позиция основания дерева
t.penup()
t.goto(-size / 2, -world_height * 0.23)
t.setheading(0)
t.pendown()

# Построение фрактала
draw_tree(size, depth, angle, depth)

# Подпись параметров
write_info()

# Отображение результата
screen.update()
turtle.done()
