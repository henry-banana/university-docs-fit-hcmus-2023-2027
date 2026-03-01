import numpy as np  

print("Bài 1:")
def f(x, y):
    return x + y

x0, y0 = 0, 1
x_end = 0.4
delta_y = 0.001

h = 0.1
x_values = [x0]
y_values = [y0]

while x_values[-1] < x_end:
    x_n = x_values[-1]
    y_n = y_values[-1]
    
    y_star = y_n + h * f(x_n, y_n)

    y_next = y_n + (h / 2) * (f(x_n, y_n) + f(x_n + h, y_star))
    error = abs((y_next - y_n) / y_next)
    # if error > delta_y: # Nếu sai số lớn hơn mức cho phép, giảm bước
    #     h /= 2
    #     continue

    x_values.append(x_n + h)
    y_values.append(y_next)

    # if error < delta_y / 10:
    #     h *= 2
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.4f}, y = {y_i:.6f}")

print("Bài 2:")
def f(x, y):
    return 2 * x * x + y

x0, y0 = 0, 1
x_end = 0.5
delta_y = 0.001

h = 0.1
x_values = [x0]
y_values = [y0]

while x_values[-1] < x_end:
    x_n = x_values[-1]
    y_n = y_values[-1]
    
    y_star = y_n + h * f(x_n, y_n)

    y_next = y_n + (h / 2) * (f(x_n, y_n) + f(x_n + h, y_star))
    error = abs((y_next - y_n) / y_next)
    # if error > delta_y: # Nếu sai số lớn hơn mức cho phép, giảm bước
    #     h /= 2
    #     continue

    x_values.append(x_n + h)
    y_values.append(y_next)

    # if error < delta_y / 10:
    #     h *= 2
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.4f}, y = {y_i:.6f}")

print("Bài 3:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1
x_values = np.arange(x0, x_end + h, h)
y_values = np.zeros_like(x_values)
y_values[0] = y0 # Giá trị ban đầu
for i in range(len(x_values) - 1):
    y_values[i + 1] = y_values[i] + h * f(x_values[i], y_values[i])
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Bài 4:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1
x_values = np.arange(x0, x_end + h, h)
y_values = np.zeros_like(x_values)
y_values[0] = y0 # Giá trị ban đầu
for i in range(len(x_values) - 1):
    y_values[i + 1] = y_values[i] + h * f(x_values[i], y_values[i])
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Bài 5:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1
x_values = np.arange(x0, x_end + h, h)
y_values = np.zeros_like(x_values)
y_values[0] = y0
for i in range(len(x_values) - 1):
    x_i, y_i = x_values[i], y_values[i]

    k1 = h * f(x_i, y_i)
    k2 = h * f(x_i + h/2, y_i + k1/2)
    k3 = h * f(x_i + h/2, y_i + k2/2)
    k4 = h * f(x_i + h, y_i + k3)

    y_values[i + 1] = y_i + (k1 + 2*k2 + 2*k3 + k4) / 6
print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)

print("Bài 6:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1
x_values = np.arange(x0, x_end + h, h)
y_values = np.zeros_like(x_values)
y_values[0] = y0
for i in range(len(x_values) - 1):
    x_i, y_i = x_values[i], y_values[i]

    k1 = h * f(x_i, y_i)
    k2 = h * f(x_i + h/2, y_i + k1/2)
    k3 = h * f(x_i + h/2, y_i + k2/2)
    k4 = h * f(x_i + h, y_i + k3)

    y_values[i + 1] = y_i + (k1 + 2*k2 + 2*k3 + k4) / 6

print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)

print("Bài 7:")
def pplap(f, x0, y0, x_end, delta_y, h):
    x_values = [x0]
    y_values = [y0]

    while x_values[-1] < x_end:
        x_n = x_values[-1]
        y_n = y_values[-1]
        
        y_star = y_n + h * f(x_n, y_n)

        y_next = y_n + (h / 2) * (f(x_n, y_n) + f(x_n + h, y_star))
        error = abs((y_next - y_n) / y_next)
        # if error > delta_y: # Nếu sai số lớn hơn mức cho phép, giảm bước
        #     h /= 2
        #     continue

        x_values.append(x_n + h)
        y_values.append(y_next)

        # if error < delta_y / 10:
        #     h *= 2
    return x_values, y_values

print("Giải lại bài 1:")
def f(x, y):
    return x + y

x0, y0 = 0, 1
x_end = 0.4
delta_y = 0.001
h = 0.1

x_values, y_values = pplap(f, x0, y0, x_end, delta_y, h)
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.4f}, y = {y_i:.6f}")

print("Giải lại bài 2:")
def f(x, y):
    return 2 * x * x + y

x0, y0 = 0, 1
x_end = 0.5
delta_y = 0.001
h = 0.1

x_values, y_values = pplap(f, x0, y0, x_end, delta_y, h)
for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.4f}, y = {y_i:.6f}")

print("Bài 8:")

def euler(f, x0, y0, x_end, h):
    x_values = np.arange(x0, x_end + h, h)
    y_values = np.zeros_like(x_values)
    y_values[0] = y0 # Giá trị ban đầu
    for i in range(len(x_values) - 1):
        y_values[i + 1] = y_values[i] + h * f(x_values[i], y_values[i])
    return x_values, y_values

print("Giải lại bài 3:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1

x_values, y_values = euler(f, x0, y0, x_end, h)

for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Giải lại bài 4:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1

x_values, y_values = euler(f, x0, y0, x_end, h)

for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Bài 9:")

def euler_cai_tien(f, x0, y0, x_end, h):
    x_values = np.arange(x0, x_end + h, h)
    y_values = np.zeros_like(x_values)
    y_values[0] = y0  # Giá trị ban đầu
    
    for i in range(len(x_values) - 1):
        x_n = x_values[i]
        y_n = y_values[i]
        
        # Dự đoán bước tiếp theo (Euler)
        y_star = y_n + h * f(x_n, y_n)
        
        # Điều chỉnh bước tiếp theo bằng cách tính trung bình độ dốc
        y_values[i + 1] = y_n + (h / 2) * (f(x_n, y_n) + f(x_n + h, y_star))
        
    return x_values, y_values

print("Giải lại bài 3:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1

x_values, y_values = euler_cai_tien(f, x0, y0, x_end, h)

for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Giải lại bài 4:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1

x_values, y_values = euler_cai_tien(f, x0, y0, x_end, h)

for x_i, y_i in zip(x_values, y_values):
    print(f"x = {x_i:.2f}, y = {y_i:.6f}")

print("Bài 10:")

def runge_kutta_b2(f, x0, y0, x_end, h):
    x_values = np.arange(x0, x_end + h, h)
    y_values = np.zeros_like(x_values)
    y_values[0] = y0
    
    for i in range(len(x_values) - 1):
        x_i, y_i = x_values[i], y_values[i]

        # Tính k1 và k2 theo công thức Runge-Kutta bậc 2
        k1 = h * f(x_i, y_i)
        k2 = h * f(x_i + h, y_i + k1)

        # Cập nhật giá trị y
        y_values[i + 1] = y_i + (k1 + k2) / 2
    
    return x_values, y_values

print("Giải lại bài 5:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1
x_values, y_values = runge_kutta_b2(f, x0, y0, x_end, h)
print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)

print("Giải lại bài 6:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1
x_values, y_values = runge_kutta_b2(f, x0, y0, x_end, h)
print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)


print("Bài 11:")

def runge_kutta_b3(f, x0, y0, x_end, h):
    x_values = np.arange(x0, x_end + h, h)
    y_values = np.zeros_like(x_values)
    y_values[0] = y0
    
    for i in range(len(x_values) - 1):
        x_i, y_i = x_values[i], y_values[i]

        k1 = h * f(x_i, y_i)
        k2 = h * f(x_i + h / 2, y_i + k1 / 2)
        k3 = h * f(x_i + h, y_i - k1 + 2 * k2)

        y_values[i + 1] = y_i + (k1 + 4 * k2 + k3) / 6
    
    return x_values, y_values

print("Giải lại bài 5:")
def f(x, y):
    return x + y
x0, y0 = 0, 1
x_end = 0.4
h = 0.1
x_values, y_values = runge_kutta_b3(f, x0, y0, x_end, h)
print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)

print("Giải lại bài 6:")
def f(x, y):
    return 2 * x * x + y
x0, y0 = 0, 1
x_end = 0.5
h = 0.1
x_values, y_values = runge_kutta_b3(f, x0, y0, x_end, h)
print("Bảng giá trị x và y tính theo phương pháp Runge-Kutta bậc 4:")
print("x:", x_values)
print("y:", y_values)