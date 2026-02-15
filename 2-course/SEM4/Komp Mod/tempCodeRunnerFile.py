X_E = [0.115, 0.120, 0.125, 0.130, 0.135, 0.140]
Y_E = [8.65729, 8.29329, 7.95829, 7.64893, 7.36235, 7.09631]

X_NE =  [0.43, 0.48, 0.55, 0.62, 0.70, 0.75]
Y_NE = [1.63597, 1.73234, 1.87686, 2.03345, 2.22846, 2.35973]

def lagrange(x_arr , y_arr, dot):

    if len(x_arr) != len(y_arr):
        raise ValueError("Неверные данные")
    
    n = len(x_arr)
    result = 0.0

    for i in range(n):
        term = y_arr[i]
        for j in range(n):
            if i != j:
                term *= (dot - x_arr[j])/(x_arr[i]-x_arr[j])

        result+=term
    
    return result
        
    
print("Равностоящие x=138: " + lagrange(X_E, Y_E, 0.138))
print("Равностоящие x=118: " +lagrange(X_E, Y_E, 0.118))
print("Неравностоящие x=0.5: " +lagrange(X_NE, Y_NE, 0.5))

