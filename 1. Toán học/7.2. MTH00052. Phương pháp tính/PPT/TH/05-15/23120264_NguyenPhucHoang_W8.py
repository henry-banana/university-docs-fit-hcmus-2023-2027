import numpy as np

# Hàm f(x)
def f(x):
    return x**2
#Hàm F(x)
def F(x):
    return x**3*(1/3)

# a. Tính tích phân chính xác 
# Tích phân của f(x) = x^2 từ 1 đến 2
exact_integral = F(2) - F(1)

# b. Phương pháp hình thang với delta_x = 0.05
delta_x = 0.05
x = 1
trapezoidal_integral = 0
while(x <= 2):
    trapezoidal_integral += delta_x*(f(x + delta_x) + f(x))*0.5
    x += delta_x

# c. Phương pháp Simpson 1/3 với delta_x = 0.05
# Phương pháp Simpson yêu cầu số phân mảnh là chẵn, do đó cần điều chỉnh số lượng điểm.
x = 1
simpson_1_3_integral = 0
while(x <= 2):
    simpson_1_3_integral += (delta_x / 6)*(f(x) + 4*f(x + delta_x/2) + f(x + delta_x))
    x += delta_x

# d. Phương pháp Simpson 3/8 với delta_x = 0.05
# Phương pháp Simpson 3/8 yêu cầu số phân mảnh chia 3, cần điều chỉnh n cho phép số điểm chia đều cho 3.
x = 1
simpson_3_8_integral = 0
while(x <= 2):
    simpson_3_8_integral += (delta_x / 8) * (f(x) + 3 * f(x + delta_x / 3) + 3 * f(x + 2 * delta_x / 3) + f(x + delta_x))
    x += delta_x

# In kết quả
print(f"Tích phân chính xác: {exact_integral}")
print(f"Tích phân theo phương pháp hình thang: {trapezoidal_integral}")
print(f"Tích phân theo phương pháp Simpson 1/3: {simpson_1_3_integral}")
print(f"Tích phân theo phương pháp Simpson 3/8: {simpson_3_8_integral}")
