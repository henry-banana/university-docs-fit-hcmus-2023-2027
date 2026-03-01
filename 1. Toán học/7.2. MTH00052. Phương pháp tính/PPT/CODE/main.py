import numpy as np

# Hàm chính
def f(x):
    return np.log(x**2 + 1) - x**3 + np.cos(x)

# Hàm phi
def phi(x):
    return (np.log(x**2 + 1) + np.cos(x)) ** (1 / 3)

# Đạo hàm
def f_prime(x):
    return (2 * x) / (x ** 2 + 1) - 3 * (x ** 2) - np.sin(x)

# Cận
a = 1
b = 2
tolerance = 1e-3
x0 = 1.5

def bisection_method(f, a, b, tol=tolerance, max_iter=100):
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

print("PHƯƠNG PHÁP CHIA ĐÔI")
root = bisection_method(f, a, b, tol=tolerance)
print("\n\n")

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

print("PHƯƠNG PHÁP LẶP")
root = fixed_point_iteration(f, phi, x0)
print("\n\n")

def pptieptuyen(f, f_prime, x0, delta_f = tolerance):
    n = 1
    while n < 100:
        fn = f(x0)
        f_prime_n = f_prime(x0)
        xn = x0 - fn / f_prime_n
        delta_xn = np.abs(xn - x0)
        print(f"{n:<5}{xn:<12.4f}{fn:<12.4f}")
        if np.abs(fn) <= delta_f:
            break
        x0 = xn
        n += 1

print("PHƯƠNG PHÁP TIẾP TUYẾN")
root = pptieptuyen(f, f_prime, x0)
print("\n\n")

def ppdaycung(f, a, b, delta_f = tolerance):
    n = 1
    while n < 100:
        c = a - f(a) * (b - a) / (f(b) - f(a))  # Tính giá trị c
        fc = f(c)  # Giá trị của f(c)
        delta_c = np.abs(c - a)  # Sai số giữa c và a

        # In thông tin của bước lặp hiện tại
        print(f"{n:<5}{a:<12.4f}{b:<12.4f}{c:<12.4f}{fc:<12.4f}{f(a) * fc:<12.4f}")

        # Kiểm tra điều kiện dừng
        if np.abs(fc) <= delta_f:
            break

        # Cập nhật khoảng [a, b]
        if f(a) * fc < 0:
            b = c
        else:
            a = c

        n += 1  # Tăng số bước lặp

print("PHƯƠNG PHÁP DÂY CUNG")
root = ppdaycung(f, a, b)
print("\n\n")