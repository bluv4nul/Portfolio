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


def GaussJordan(A=None, B=None):
    if A is None or B is None:
        raise ValueError("A and B must be matrix")

    n = len(A)

    for i in range(len(A)):
        A[i].append(B[i])

    for i in range(0, n):
        for k in range(0, n):
            if k != i:
                a_ki = A[k][i] / A[i][i]
                for j in range(i, n + 1):
                    A[k][j] = A[k][j] - a_ki * A[i][j]

    printMatrix(A)

    X = [0] * n

    for i in range(0, n):
        X[i] = A[i][n] / A[i][i]

    return X


X = GaussJordan(A, B)
for x in X:
    print(round(x, ndigits=1), end="\t")
