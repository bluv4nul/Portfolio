A = [[5, 7, 6, 5], [7, 10, 8, 7], [6, 8, 10, 9], [5, 7, 9, 10]]
B = [23, 32, 33, 31]

def Gauss_row_pivot(A=None, B=None):
    if A is None or B is None:
        raise ValueError("A and B must be matrix")

    n = len(A)

    # 1. Формируем расширенную матрицу [A | B]
    for i in range(n):
        A[i].append(B[i])

    # 2. Массив для отслеживания перестановки столбцов (перенумерация переменных)
    col_index = list(range(n))

    # 3. Прямой ход метода Гаусса
    for i in range(n - 1):

        # 3.1 Поиск максимального по модулю элемента в текущей строке
        max_col = i
        for j in range(i + 1, n):
            if abs(A[i][j]) > abs(A[i][max_col]):
                max_col = j

        # 3.2 Перестановка столбцов (если найден элемент больше диагонального)
        if max_col != i:
            for k in range(n):
                A[k][i], A[k][max_col] = A[k][max_col], A[k][i]

            # фиксируем изменение порядка переменных
            col_index[i], col_index[max_col] = col_index[max_col], col_index[i]

        # 3.3 Обнуление элементов под главным элементом
        for k in range(i + 1, n):
            factor = A[k][i] / A[i][i]  # коэффициент исключения
            for j in range(i, n + 1):
                A[k][j] -= factor * A[i][j]

    # 4. Обратный ход (нахождение неизвестных)
    X = [0] * n
    for i in range(n - 1, -1, -1):
        s = A[i][n]
        for j in range(i + 1, n):
            s -= A[i][j] * X[j]
        X[i] = s / A[i][i]

    # 5. Возвращаем переменные в исходном порядке
    result = [0] * n
    for i in range(n):
        result[col_index[i]] = X[i]

    return result

def Gauss_column_pivot(A=None, B=None):
    if A is None or B is None:
        raise ValueError("A and B must be matrix")

    n = len(A)

    # 1. Формируем расширенную матрицу
    for i in range(n):
        A[i].append(B[i])

    # 2. Прямой ход
    for i in range(n - 1):

        # 2.1 Поиск максимального элемента в текущем столбце
        max_row = i
        for k in range(i + 1, n):
            if abs(A[k][i]) > abs(A[max_row][i]):
                max_row = k

        # 2.2 Перестановка строк
        if max_row != i:
            A[i], A[max_row] = A[max_row], A[i]

        # 2.3 Обнуление элементов ниже главного
        for k in range(i + 1, n):
            factor = A[k][i] / A[i][i]
            for j in range(i, n + 1):
                A[k][j] -= factor * A[i][j]

    # 3. Обратный ход
    X = [0] * n
    for i in range(n - 1, -1, -1):
        s = A[i][n]
        for j in range(i + 1, n):
            s -= A[i][j] * X[j]
        X[i] = s / A[i][i]

    return X

def Gauss_full_pivot(A=None, B=None):
    if A is None or B is None:
        raise ValueError("A and B must be matrix")

    n = len(A)

    # 1. Формируем расширенную матрицу
    for i in range(n):
        A[i].append(B[i])

    # 2. Массив для отслеживания перестановки столбцов
    col_index = list(range(n))

    # 3. Прямой ход
    for i in range(n - 1):

        # 3.1 Поиск максимального элемента во всей оставшейся подматрице
        max_row = i
        max_col = i
        max_val = abs(A[i][i])

        for r in range(i, n):
            for c in range(i, n):
                if abs(A[r][c]) > max_val:
                    max_val = abs(A[r][c])
                    max_row = r
                    max_col = c

        # 3.2 Перестановка строк
        if max_row != i:
            A[i], A[max_row] = A[max_row], A[i]

        # 3.3 Перестановка столбцов
        if max_col != i:
            for r in range(n):
                A[r][i], A[r][max_col] = A[r][max_col], A[r][i]

            col_index[i], col_index[max_col] = col_index[max_col], col_index[i]

        # 3.4 Обнуление элементов ниже диагонали
        for k in range(i + 1, n):
            factor = A[k][i] / A[i][i]
            for j in range(i, n + 1):
                A[k][j] -= factor * A[i][j]

    # 4. Обратный ход
    X = [0] * n
    for i in range(n - 1, -1, -1):
        s = A[i][n]
        for j in range(i + 1, n):
            s -= A[i][j] * X[j]
        X[i] = s / A[i][i]

    # 5. Возвращаем правильный порядок переменных
    result = [0] * n
    for i in range(n):
        result[col_index[i]] = X[i]

    return result

print("Результат метода Гаусса с выбором главного элемента по строке:")
print(Gauss_row_pivot(A, B))
print("Результат метода Гаусса с выбором главного элемента по столбцу:")
print(Gauss_column_pivot(A, B))
print("Результат метода Гаусса с полным выбором главного элемента:")
print(Gauss_full_pivot(A, B))