import numpy as np

def bisection_method(f, a, b, tol=1e-3, max_iter=100):
    if f(a) * f(b) >= 0:
        print("Phương pháp chia đôi không áp dụng được vì f(a) và f(b) cùng dấu.")
        return None
    
    iter_count = 0
    print(f"{'k':<5}{'a':<12}{'b':<12}{'c':<12}{'f(c)':<12}")
    while (b - a) / 2.0 > tol and iter_count < max_iter:
        iter_count += 1
        midpoint = (a + b) / 2.0
        print(f"{iter_count:<5}{a:<12.4f}{b:<12.4f}{midpoint:<12.4f}{f(midpoint):<12.4f}{f(midpoint)*f(a):<12.4f}")
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return (a + b) / 2.0

def f(x):
    return 5 * (2 * np.pi - 4 * np.arcsin(x) - (x / 2) * (4 - x ** 2)) - 30

a = 0.01
b = 0.05
tolerance = 1e-3
root = bisection_method(f, a, b, tol=tolerance)
if root is not None:
    print(f"Nghiệm của phương trình là: {root}")
else:
    print("Không tìm thấy nghiệm trong khoảng đã cho.")