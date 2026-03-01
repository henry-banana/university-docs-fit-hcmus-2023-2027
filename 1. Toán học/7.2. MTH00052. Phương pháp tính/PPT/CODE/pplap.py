import numpy as np

def fixed_point_iteration(f, phi, x0, tol=1e-3, max_iter=100):
    x = x0
    print(f"{'Iter':<5}{'x_new':<12}{'f(x_new)':<12}")
    for i in range(max_iter):
        x_new = phi(x)
        print(f"{i:<5}{x_new:<12.4f}{f(x_new):<12.4f}")
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    return x

def f(x):
    return np.log(x - 1) + np.cos(x - 1)

def phi(x):
    return np.exp(np.cos(x - 1)) + 1

x0 = 1.5
tolerance = 1e-3

root = fixed_point_iteration(f, phi, x0, tol=tolerance)

