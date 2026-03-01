import numpy as np

#bai 1
def Lap(A, B, tolerance):

    tolerance = 1e-3
    max_iterations = 100

    X = np.zeros_like(B)
    for _ in range(max_iterations):
        X_new = np.zeros_like(X)
        for i in range(len(A)):
            sum1 = sum(A[i][j] * X[j] for j in range(len(A)) if j != i)
            X_new[i] = (B[i] - sum1) / A[i][i]
        if np.linalg.norm(X_new - X, ord=np.inf) < tolerance:
            break
        X = X_new
    print("Nghiệm của hệ phương trình:", X)

def Seidel(A, B, tolerance) :
        max_iterations = 100
        X = np.zeros_like(B)
        for _ in range(max_iterations):
            X_new = np.copy(X)
            for i in range(len(A)):
                sum1 = sum(A[i][j] * X_new[j] for j in range(len(A)) if j != i)
                X_new[i] = (B[i] - sum1) / A[i][i]

            if np.linalg.norm(X_new - X, ord=np.inf) < tolerance:
                break
            X = X_new
        print("Nghiệm của hệ phương trình:", X)  

#bai 3
A = np.array([[5, 1, 1],
                [1, 10, 1],
                [1, 1, 20]], 
                dtype=float)
B = np.array([7, 12, 22], dtype=float)
tolerance = 1e-3
Lap(A, B, tolerance)
Seidel(A, B, tolerance)


#Bai4
A = np.array([[6, 2, 2, 1, 2],
                [1, 9, 1, 2, 1],
                [1, 3, 10, 1, 2],
                [1,1,4,8,3],
                [1, 2, 2, 3,9]], 
                dtype=float)
B = np.array([9, 1, -12, -12, 5], dtype=float)
tolerance = 1e-3
Lap(A, B, tolerance)
Seidel(A, B, tolerance)