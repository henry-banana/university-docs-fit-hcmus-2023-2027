# 23120264 - Nguyễn Phúc Hoàng

import numpy as np
import matplotlib.pyplot as plt

print("EX04")
#a
print("a")
def TiepTuyen(f, df, x0, delta_f):
    x = x0
    iteration = 0
    x_values = [x]    
    f_values = [f(x)] 

    while abs(f(x)) > delta_f:
        x = x - f(x) / df(x) 
        iteration += 1
        x_values.append(x)
        f_values.append(f(x))

    return x, iteration, x_values, f_values

#b
def TiepTuyen(f, df, x0, delta_f):
    x = x0
    iteration = 0
    x_values = [x]  
    f_values = [f(x)] 

    while abs(f(x)) > delta_f:
        x = x - f(x) / df(x)  
        iteration += 1
        x_values.append(x)
        f_values.append(f(x))

    print(f"{'Iteration':<10} {'x':<15} {'f(x)':<15}")
    for i in range(len(x_values)):
        print(f"{i:<10} {x_values[i]:<15.6f} {f_values[i]:<15.6f}")

    x_range = np.linspace(min(x_values) - 1, max(x_values) + 1, 400)
    y_range = f(x_range)

    plt.plot(x_range, y_range, label='f(x)')
    plt.axhline(0, color='black',linewidth=0.5)
    plt.scatter(x_values, f_values, color='red', zorder=5, label="Các điểm tính toán")
    plt.title("Đồ thị của hàm f(x) và nghiệm phương trình")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.legend()
    plt.grid(True)
    plt.show()

    return x, iteration, x_values, f_values

#c
def f(x):
  return x**2 - np.sin(x) - 50

def f_prime(x):
  return 2*x - np.cos(x)
x0 = 2
delta_f = 1e-3

TiepTuyen(f, f_prime, x0, delta_f)

#d
def f(x):
    return x**3 - 6*x**2 + 2*x + 25
def f_prime(x):
  return 3*x**2 - 12*x + 2
x0 = 4
delta_f = 1e-3

TiepTuyen(f, f_prime, x0, delta_f)

#Ex05
print('(+)EX05')
def f(x):
    return x + np.log(x + 2) - 10
def f_prime(x):
  return 1 + 1/(x + 2)

#a
x0 = 7
delta_f = 1e-3
TiepTuyen(f, f_prime, x0, delta_f)

#b
x0 = 9
delta_f = 2*1e-3
TiepTuyen(f, f_prime, x0, delta_f)

#c
x0 = 5
delta_f = 5*1e-3
TiepTuyen(f, f_prime, x0, delta_f)

#d
x0 = 3
delta_f = 5*1e-3
TiepTuyen(f, f_prime, x0, delta_f)

#Ex06
print('(+)EX06')
#a, b

def CatTuyen(f, a, b, delta_f):
    print("STT\t$a$\t$b$\t$c$\t$f(c)$\t$|f(c)| \leq \Delta f$\t$\delta c$")
    n = 1
    x_values = []  # Lưu các giá trị c
    f_values = []  # Lưu các giá trị f(c)

    while True:
        # Tính điểm c sử dụng công thức tiếp tuyến Newton-Raphson
        c = a - f(a) * (b - a) / (f(b) - f(a))
        fc = f(c)
        delta_c = np.abs(c - a)

        # Lưu giá trị c và f(c) để vẽ đồ thị sau
        x_values.append(c)
        f_values.append(fc)

        # In ra bảng giá trị
        print(f"{n}\t{a:.6f}\t{b:.6f}\t{c:.6f}\t{fc:.6f}\t{np.abs(fc) <= delta_f}\t{delta_c:.6f}")

        # Kiểm tra điều kiện dừng
        if np.abs(fc) <= delta_f:
            break

        # Cập nhật lại cận a hoặc b
        if f(a) * fc < 0:
            b = c
        else:
            a = c

        n += 1

    # Vẽ đồ thị của hàm f(x) và các giá trị c tính được
    x_range = np.linspace(min(x_values) - 1, max(x_values) + 1, 400)
    y_range = f(x_range)

    plt.plot(x_range, y_range, label='f(x)')
    plt.axhline(0, color='black', linewidth=0.5)
    plt.scatter(x_values, f_values, color='red', zorder=5, label="Các điểm tính toán")
    plt.title("Đồ thị của hàm f(x) và nghiệm phương trình")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.legend()
    plt.grid(True)
    plt.show()

    return c, n, x_values, f_values


#Ex07
print('(+)EX07')
def f(x):
    return 2**x + 3**x - 10*x - 30
#a
a = -5
b = -3
delta_f = 1e-3
CatTuyen(f, a, b, delta_f)

#b
a = -4
b = -2
delta_f = 2*1e-3
CatTuyen(f, a, b, delta_f)

#c
a = 2
b = 4
delta_f = 3*1e-3
CatTuyen(f, a, b, delta_f)

#d
a = 2
b = 4
delta_f = 3*1e-3
CatTuyen(f, a, b, delta_f)

#Ex08
print('(+)EX08')
delta_f = 1e-9
#a
def f(x):
    return np.e**x + 2**(-x) + 2*np.cos(x) - 6  
def f_prime(x):
  return np.e**x - 2**(-x)*np.log(2) - 2*np.sin(x)

TiepTuyen(f, f_prime, 1.5, delta_f)
CatTuyen(f, 1, 2, delta_f)

# b
def f(x):
    return np.log(x - 1) + np.cos(x - 1)

def f_prime(x):
    return 1/(x - 1) - np.sin(x - 1)


TiepTuyen(f, f_prime, 1.3, delta_f)
CatTuyen(f, 1.1, 1.5, delta_f)

#c
def f(x):
    return (x - 2)**2 - np.log(x) 
def f_prime(x):
    return 2*(x - 2) - 1/x

TiepTuyen(f, f_prime, 1.5, delta_f)
CatTuyen(f, 1, 2, delta_f)

#d
def f(x):
    return np.sin(x) - np.exp(-x)
def f_prime(x):
    return -np.sin(x) + np.exp(-x)

TiepTuyen(f, f_prime, 0.8, delta_f)
CatTuyen(f, 0, 1, 1e-3)

#Bai 9
def w(x):
    L = 600
    E = 50000
    I = 30000
    (2.5/(120 * E * L * I))*(-x**5 + 2*(L**2) * (x**3) - (L**4)*x)
def f(x):
    L = 600
    E = 50000
    I = 30000
    (2.5/(120 * E * L * I))*(-5*x**4 + 6*(L**2) * (x**2) - (L**4))

def f_prime(x):
    L = 600
    E = 50000
    I = 30000
    (2.5/(120 * E * L * I))*(-20*x**3 + 12*(L**2) * (x))

TiepTuyen(f, f_prime, 600, delta_f)