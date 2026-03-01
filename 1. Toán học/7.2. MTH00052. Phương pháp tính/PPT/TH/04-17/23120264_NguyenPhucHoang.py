import numpy as np
import math
import matplotlib.pyplot as plt

xx = np.array([1, 2.2, 3.1, 4])  
yy = np.array([1.678, 3.267, 2.198, 3.787])
x_c = 2.5 
# Exercise 10

X = np.vander(xx, increasing=True)

A = np.linalg.solve(X, yy)

def poly_interpolation(x, coeffs):
    return sum(c * x**i for i, c in enumerate(coeffs))


y_c = poly_interpolation(x_c, A)

print(f"Approximate value of y at x = {x_c} is: {y_c}")

x_vals = np.linspace(min(xx), max(xx), 100)
y_vals = np.array([poly_interpolation(x, A) for x in x_vals])
plt.figure(figsize=(8, 6))
plt.plot(x_vals, y_vals, label="General Polynomial Interpolation", color='b', linestyle='-', linewidth=2)
plt.scatter(xx, yy, color='red', zorder=5, label="Data Points", s=100, edgecolor='black')
plt.title("General Polynomial Interpolation and Data Points", fontsize=14)
plt.xlabel("x values", fontsize=12)
plt.ylabel("y values", fontsize=12)
plt.legend()
plt.grid(True)
plt.show()


# Exercise 11
def lagrange_basis(x, i, xx):
    L = 1
    for j in range(len(xx)):
        if j != i:
            L *= (x - xx[j]) / (xx[i] - xx[j])
    return L
def lagrange_interpolation(x, xx, yy):
    n = len(xx)
    P = 0
    for i in range(n):
        P += yy[i] * lagrange_basis(x, i, xx)
    return P


y_ck = lagrange_interpolation(x_c, xx, yy)
print(f"Approximate value of y at x = {x_c} is: {y_ck}")

x_vals = np.linspace(min(xx), max(xx), 100)

y_vals = np.array([lagrange_interpolation(x, xx, yy) for x in x_vals])

plt.figure(figsize=(8, 6))
plt.plot(x_vals, y_vals, label="Lagrange Polynomial Interpolation", color='b', linestyle='-', linewidth=2)
plt.scatter(xx, yy, color='red', zorder=5, label="Data Points", s=100, edgecolor='black')
plt.title("Lagrange Polynomial Interpolation and Data Points", fontsize=14)
plt.xlabel("x values", fontsize=12)
plt.ylabel("y values", fontsize=12)
plt.legend()
plt.grid(True)
plt.show()

# Exercise 12
def finite_differences(xx, yy):
    n = len(xx)
    diff = np.zeros((n, n)) 
    diff[:, 0] = yy  

    for j in range(1, n):
        for i in range(n - j):
            diff[i, j] = diff[i + 1, j - 1] - diff[i, j - 1]
    
    return diff

def lagrange_polynomial(x_0, xx, diff):
    n = len(xx)
    result = diff[0, 0]  

    product = 1
    for i in range(1, n):
        product *= (x_0 - xx[i - 1])
        result += diff[0, i] * product / math.factorial(i)

    return result

diff = finite_differences(xx, yy)
y_0 = lagrange_polynomial(x_c, xx, diff)
print(f"Approximate value of y at x = {x_c} is: {y_0}")
x_vals = np.linspace(min(xx), max(xx), 100)
y_vals = np.array([lagrange_polynomial(x, xx, diff) for x in x_vals])
plt.figure(figsize=(8, 6))
plt.plot(x_vals, y_vals, label="Polynomial Interpolation", color='b', linestyle='-', linewidth=2)
plt.scatter(xx, yy, color='red', zorder=5, label="Data Points", s=100, edgecolor='black')
plt.title("Polynomial Interpolation and Data Points", fontsize=14)
plt.xlabel("x values", fontsize=12)
plt.ylabel("y values", fontsize=12)
plt.legend()
plt.grid(True)
plt.show()

# Exercise 13
xx13 = np.array([3.2, -2.5, -1.7, -0.8, 0.3, 1.5 ])  
yy13 = np.array([8.982, -5.831, -4.261, -1.837, -3.298, -0.249])
x_c131 = -2
x_c132 = 0
y_c131 = poly_interpolation(x_c131, A)
print(f"Approximate value of y at x = {x_c131} is: {y_c131}")
y_c132 = poly_interpolation(x_c132, A)
print(f"Approximate value of y at x = {x_c132} is: {y_c132}")
# Exercise 14
y_ck = lagrange_interpolation(x_c131, xx13, yy13)
print(f"Approximate value of y at x = {x_c131} is: {y_ck}")
y_ck = lagrange_interpolation(x_c132, xx13, yy13)
print(f"Approximate value of y at x = {x_c132} is: {y_ck}")
# Exercise 15
diff = finite_differences(xx13, yy13)
y_151 = lagrange_polynomial(x_c131, xx13, diff)
print(f"Approximate value of y at x = {x_c131} is: {y_151}")
diff = finite_differences(xx13, yy13)
y_01 = lagrange_polynomial(x_c132, xx13, diff)
print(f"Approximate value of y at x = {x_c132} is: {y_01}")

