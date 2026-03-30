A = [[5, 7, 6, 5], [7, 10, 8, 7], [6, 8, 10, 9], [5, 7, 9, 10]]
B = [23, 32, 33, 31]

def Gauss(A=None, B=None):
    if A is None or B is None:
        raise ValueError("A and B must be matrix")

    n = len(A)

    for i in range(len(A)):
        A[i].append(B[i])
    
    for i in range(0, n - 1):
        for k in range(i+1, n):
            A[k][i] = A[k][i] / A[i][i]
        for k in range(i + 1, n):
            a_ki = A[k][i]
            for j in range(i, n + 1):
                A[k][j] = A[k][j] - a_ki * A[i][j]

    X = [0] * n

    X[n-1] = A[n-1][n]/A[n-1][n-1]

    for i in range(n - 2, -1, -1):
        x = A[i][n]
        for j in range(i + 1, n):
            x -= A[i][j] * X[j]
        X[i] = x / A[i][i]

    return X


X = Gauss(A, B)
for x in X:
    print(x, end="\t")