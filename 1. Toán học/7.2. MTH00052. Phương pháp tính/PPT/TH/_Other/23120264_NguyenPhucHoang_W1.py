# 23120264 - Nguyễn Phúc Hoàng

import numpy as np
import matplotlib.pyplot as plt
import sympy as sp

# Bài 13
print("\n--- BÀI 13 ---")

# Tính A
A = 2**3 - ((1+2)*(2+3))/(3+4) + (np.sqrt(2) / (3**(1/4)))
print(f"A = {A:.4f}")

# Tính B
B = np.sin(np.pi/3) - 2 * np.cos(np.pi/4) + (3 * np.tan(np.pi/6)) / (2 - (1/np.tan(5*np.pi/6)))
print(f"B = {B:.4f}")

# Tính C
C = np.exp(-np.sqrt(2)) - np.log(3/2) + np.log(np.e + 2)
print(f"C = {C:.4f}")

# Tính D
D = (2*A + 3*B) / (C**2 - 2*C)
print(f"D = {D:.4f}")

# Bài 14

print("\n--- BÀI 14 ---")

a, b, c = 2, 3, 1

# Câu a
res_A = (b + np.sqrt(b*b - 4*a*c)) / (2 * a)
print(f"A = {res_A:.4f}")

# Câu b
vector_B = np.array([
    a * np.sin(b) * np.cos(c),
    a * np.sin(b) * np.sin(c),
    a * np.cos(b),
    0
])
print(f"B = {vector_B}")

# Câu c
vector_C = np.array([
    (a + b) / (a + b + c),
    (a - b + c) / (a + b + c),
    (c**2 - a * b) / (a + b + c),
    1 / (a + b + c)
])
print(f"C = {vector_C}")

# Câu d
vector_D = res_A * vector_B - vector_C
print(f"D = {vector_D}")

# Bài 15

print("\n--- BÀI 15 ---")

def ham_so(x):
    return x * np.sin(x)

# Giá trị tại x = 1 và x = 3
x1, x3 = 1, 3
f1, f3 = ham_so(x1), ham_so(x3)

print(f"f(1) = {f1:.4f}")
print(f"f(3) = {f3:.4f}")

# Vẽ đồ thị
x_values = np.linspace(-2, 4, 100)
y_values = [ham_so(x) for x in x_values]

plt.plot(x_values, y_values, label="f(x) = x*sin(x)", color="b")
plt.scatter([x1, x3], [f1, f3], color="r", label="f(1) và f(3)")
plt.axhline(0, color="black", linewidth=0.5)
plt.axvline(0, color="black", linewidth=0.5)
plt.xlabel("x")
plt.ylabel("f(x)")
plt.legend()
plt.title("Đồ thị hàm số f(x) = x*sin(x)")
plt.grid()
plt.show()

# Bài 16

print("\n--- BÀI 16 ---")

def ham_hai_bien(x, y):
    return np.abs(x) + 2 * np.abs(y)

# Giá trị tại (1,2) và (sqrt(2), e^(-1))
value_1 = ham_hai_bien(1, 2)
value_2 = ham_hai_bien(np.sqrt(2), np.exp(-1))

print(f"f(1,2) = {value_1}")
print(f"f(sqrt(2), e^(-1)) = {value_2}")

# Bài 17

print("\n--- BÀI 17 ---")

x = sp.symbols('x')
ham_f = x**2 + 2*x - 4

# Đạo hàm
dao_ham_f = sp.diff(ham_f, x)
print(f"Đạo hàm f'(x) = {dao_ham_f}")

# Tích phân bất định
tich_phan_f = sp.integrate(ham_f, x)
print(f"Tích phân bất định f(x)dx = {tich_phan_f}")

# Tích phân xác định từ 0 đến 1
tich_phan_xac_dinh = sp.integrate(ham_f, (x, 0, 1))
print(f"Tích phân xác định [0,1] f(x)dx = {tich_phan_xac_dinh}")

# BÀI 18: GIẢI PHƯƠNG TRÌNH

print("\n--- BÀI 18 ---")

def giai_phuong_trinh_bac_hai(a, b, c):
    nghiem = sp.solve(a*x**2 + b*x + c, x)
    return nghiem

nghiem_pt = giai_phuong_trinh_bac_hai(2, -3, 1)
print(f"Nghiệm phương trình 2x^2 - 3x + 1 = 0 là: {nghiem_pt}")

# BÀI 19: TÌM CỰC TRỊ HÀM SỐ

print("\n--- BÀI 19 ---")

ham_g = x**3 - 6*x
cuc_tri = sp.solve(sp.diff(ham_g, x), x)
print(f"Các điểm cực trị của hàm số f(x) = x^3 - 6x là: {cuc_tri}")

# BÀI 20: ĐẠO HÀM RIÊNG CẤP HAI

print("\n--- BÀI 20 ---")

x, y = sp.symbols('x y')
ham_hai_bien = (x / y) * sp.sin(y / x)

# Đạo hàm riêng cấp hai
dao_ham_xy = sp.diff(ham_hai_bien, x, y)
dao_ham_yx = sp.diff(ham_hai_bien, y, x)

print(f"f_xy = {dao_ham_xy}")
print(f"f_yx = {dao_ham_yx}")

# Kiểm tra định lý Schwarz
if sp.simplify(dao_ham_xy - dao_ham_yx) == 0:
    print("Hàm số thỏa mãn định lý Schwarz: f_xy = f_yx")
else:
    print("Hàm số không thỏa mãn định lý Schwarz: f_xy ≠ f_yx")