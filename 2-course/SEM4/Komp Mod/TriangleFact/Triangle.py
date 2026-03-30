#A = [[5, 7, 6, 5], [7, 10, 8, 7], [6, 8, 10, 9], [5, 7, 9, 10]]
#B = [23, 32, 33, 31]

A = [[4, 2, -1, 3], [3, 6, 2, -1], [2, -1, 5, 4], [1, 3, 2, 7]]
B = [6, 5, 24, 12]


def printMatrix(A):
    print("---------Матрица---------\n")

    for i in range(len(A)):
        for j in range(len(A[i])):
            if j == len(A):
                print("B: ", round(A[i][j], 1), end=" ")
            else:
                print(round(float(A[i][j]), 1), end=" | ")
        print("\n")

    print("---------------------------")


def printArray(A):
    print("-------------Массив-------------")
    for a in A:
        print(round(a, 2), end="\t")
    print("\n-------------------------------")


def TriangleFactorization(A=None, B=None):

    if A is None or B is None:
        raise ValueError(
            "Метод принимает на вход две матрицы. Введите правильные данные."
        )

    n = len(A)

    # Подготовка
    R = [[0] * n for _ in range(n)]
    L = [[0] * n for _ in range(n)]

    for i in range(0, n):
        R[i][i] = 1
        L[i][0] = A[i][0]
    for j in range(1, n):
        R[0][j] = A[0][j] / L[0][0]


    # Главный цикл
    for i in range(1, n):
        term = 0
        for j in range(0, i):
            term += L[i][j] * R[j][i]
        L[i][i] = A[i][i] - term
        
        for t in range(i + 1, n):
            sum_l = 0
            sum_r = 0
            for j in range(0, i):
                sum_l += L[t][j] * R[j][i]
                sum_r += L[i][j] * R[j][t]
            L[t][i] = A[t][i] - sum_l
            R[i][t] = (A[i][t] - sum_r) / L[i][i]

    Z = [0] * n
    Z[0] = B[0] / L[0][0]
    for i in range(1, n):
        sum = 0
        for k in range(0, i):
            sum += L[i][k] * Z[k]
        Z[i] = (B[i] - sum) / L[i][i]

    X = [0] * n
    X[n - 1] = Z[n - 1]
    for i in range(n - 2, -1, -1):
        sum = 0
        for j in range(i + 1, n):
            sum += R[i][j] * X[j]
        X[i] = Z[i] - sum

    return X


X = TriangleFactorization(A=A, B=B)
for x in X:
    print(round(x, ndigits=1), end="\t")
