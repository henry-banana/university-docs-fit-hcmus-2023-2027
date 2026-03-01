import numpy as np

def f(x):
    return (40 * x - (x ** 2) / 2 + 10) * np.sin(1 + x / 20) - 400

def f_prime(x):
    return (40 - x) * np.sin(1 + x / 20) - 400 + (40 * x - (x ** 2) / 2 + 10)  * np.cos(1 + x / 20) * 1 / 20

x0 = 11.5
delta_f = 1e-3
print(f"{'STT':<5}{'xn':<12}{'f(xn)':<12}")
n = 1

while True:
    fn = f(x0)
    f_prime_n = f_prime(x0)
    xn = x0 - fn / f_prime_n
    delta_xn = np.abs(xn - x0)
    print(f"{n:<5}{xn:<12.4f}{fn:<12.4f}")
    if np.abs(fn) <= delta_f:
        break
    x0 = xn
    n += 1