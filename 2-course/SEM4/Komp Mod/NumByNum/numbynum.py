import math


# Метод «цифра за цифрой» для вычисления sin и cos
def numberByNumber(angle_degrees, n=32, digits=6):
    # Исходный вектор
    x0 = 1.0
    y0 = 0.0

    # Перевод угла в радианы
    a10 = math.radians(angle_degrees)

    # Таблица углов поворота
    q = [0.0] * (n + 1)

    # Коэффициенты масштабирования
    k1 = 1.0
    k2 = k1

    # Вычисление масштабирования
    for i in range(2, n):
        p = 2.0
        l1 = 2 * (i - 2)

        for l in range(0, l1 + 1):
            p = p * 0.5

        k2 = k2 * (1 + p)
        k1 = k1 * (1 + 1 / (math.exp((2 * (i - 2)) * math.log(2))))

    k2 = math.sqrt(k2)
    k1 = math.sqrt(k1)
    k3 = 1 / k2

    # Заполнение массива q
    q[1] = math.pi / 2

    for i in range(2, n):
        p = 2.0

        for l in range(0, (i - 2) + 1):
            p = p * 0.5

        q[i] = math.atan(p)

    # Масштабирование вектора
    x0 = x0 * k3
    y0 = y0 * k3

    # Начальный поворот
    if a10 > 0:
        x = -y0
        y = x0
        a1 = a10 - q[1]
    else:
        x = y0
        y = -x0
        a1 = a10 + q[1]

    # Основной итерационный процесс
    for i in range(2, n + 1):
        p = 2.0

        for l in range(0, (i - 2) + 1):
            p = p * 0.5

        x1 = x

        if a1 > 0:
            x = x - y * p
            y = y + x1 * p
            a1 = a1 - q[i]
        else:
            x = x + y * p
            y = y - x1 * p
            a1 = a1 + q[i]

    # Возврат округленных значений
    sin_a = round(y, digits)
    cos_a = round(x, digits)

    return sin_a, cos_a


sin_a, cos_a = numberByNumber(0)
print("Угол 0°:   sin =", sin_a, "cos =", cos_a)

sin_a, cos_a = numberByNumber(30)
print("Угол 30°:  sin =", sin_a, "cos =", cos_a)

sin_a, cos_a = numberByNumber(45)
print("Угол 45°:  sin =", sin_a, "cos =", cos_a)

sin_a, cos_a = numberByNumber(60)
print("Угол 60°:  sin =", sin_a, "cos =", cos_a)

sin_a, cos_a = numberByNumber(90)
print("Угол 90°:  sin =", sin_a, "cos =", cos_a)
