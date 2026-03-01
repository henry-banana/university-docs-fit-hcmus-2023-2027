import numpy as np  # Import numpy for mathematical operations

# Định nghĩa hàm f(x)
def f(x):
    return np.log(x - 1) + np.cos(x - 1)

# Khoảng ban đầu [a, b] và độ chính xác mong muốn
a = 1.1
b = 2
delta_f = 1e-3

# In ra tiêu đề của bảng
print(f"{'STT':<5}{'a':<12}{'b':<12}{'c':<12}{'f(c)':<12}{'f(a)*f(c)':<12}")

# Bắt đầu lặp
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