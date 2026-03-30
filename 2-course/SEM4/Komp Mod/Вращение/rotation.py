from math import sqrt

# A = [[5, 7, 6, 5], [7, 10, 8, 7], [6, 8, 10, 9], [5, 7, 9, 10]]
# B = [23, 32, 33, 31]

A = [[4, 2, -1, 3], [3, 6, 2, -1], [2, -1, 5, 4], [1, 3, 2, 7]]

B = [6, 5, 24, 12]


def printMatrix(A):
    print("---------Матрица А---------\n")

    for i in range(len(A)):
        for j in range(len(A[i])):
            if j == len(A):
                print("B: ", round(A[i][j], 1), end=" ")
            else:
                print(round(float(A[i][j]), 1), end=" | ")
        print("\n")

    print("---------------------------")


def rotation(A, B) -> list:

    n = len(A) - 1
    for i in range(len(A)):
        A[i].append(B[i])

    # Прямой ход
    for i in range(0, n):
        for k in range(i + 1, n + 1):
            c = A[i][i] / sqrt(A[i][i] ** 2 + A[k][i] ** 2)
            s = A[k][i] / sqrt(A[i][i] ** 2 + A[k][i] ** 2)
            for j in range(i, n + 2):
                p = A[i][j]
                A[i][j] = A[i][j] * c + A[k][j] * s
                A[k][j] = -p * s + A[k][j] * c
            A[k][i] = 0

    # Обратный ход
    X = [0] * (n + 1)
    X[n] = A[n][n + 1] / A[n][n]
    for i in range(n - 1, -1, -1):
        s = 0
        for j in range(i + 1, n + 1):
            s += A[i][j] * X[j]
        X[i] = (A[i][n + 1] - s) / A[i][i]

    return X


X = rotation(A, B)
for x in X:
    print(round(x, 1))
