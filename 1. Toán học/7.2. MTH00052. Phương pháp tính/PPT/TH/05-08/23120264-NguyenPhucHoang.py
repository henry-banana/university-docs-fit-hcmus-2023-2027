import numpy as np

print('Bai 1')
print('---------------------------------------------')
x = np.array([2, 4, 7, 8]) 
y = np.array([2.2, 1.8, 2.7, 3.1]) 

n = len(x) - 1 

h = np.diff(x) 

A = np.zeros((n - 1, n - 1)) 
b = np.zeros(n - 1) 

for i in range(1, n): 
    A[i - 1, i - 1] = 2 * (h[i - 1] + h[i])  # Phần tử đường chéo 
    if i - 1 > 0: 
        A[i - 1, i - 2] = h[i - 1]  # Phần tử dưới đường chéo 
    if i < n - 1: 
        A[i - 1, i] = h[i]  # Phần tử trên đường chéo 
 
     
    b[i - 1] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]) 
 
c = np.zeros(n + 1) 
c[1:n] = np.linalg.solve(A, b) 
 
b = np.zeros(n) 
d = np.zeros(n) 
 
for i in range(n): 
    b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2 * c[i] + c[i + 1]) / 3 
    d[i] = (c[i + 1] - c[i]) / (3 * h[i]) 
 
def spline_interpolate(x_query): 
    for i in range(n): 
        if x[i] <= x_query <= x[i + 1]: 
            dx = x_query - x[i] 
            return y[i] + b[i] * dx + c[i] * dx**2 + d[i] * dx**3 
    return None   
 
x_values = [3, 7.5] 
y_values = [spline_interpolate(xq) for xq in x_values] 
 
for xi, yi in zip(x_values, y_values): 
    print(f"f({xi}) = {yi:.4f}")
print('---------------------------------------------')
print('Bai 2')
x = np.array([2.2, 3.6, 4.9, 5.2, 5.7, 6.4]) 
y = np.array([1.4, 3.2, 5.1, 4.4, 3.9, 3.2])

n = len(x) - 1 
 
h = np.diff(x) 
 
A = np.zeros((n - 1, n - 1)) 
b = np.zeros(n - 1) 
 
for i in range(1, n): 
    A[i - 1, i - 1] = 2 * (h[i - 1] + h[i])  # Phần tử đường chéo 
    if i - 1 > 0: 
        A[i - 1, i - 2] = h[i - 1]  # Phần tử dưới đường chéo 
    if i < n - 1: 
        A[i - 1, i] = h[i]  # Phần tử trên đường chéo 
 
     
    b[i - 1] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1]) 
 
c = np.zeros(n + 1) 
c[1:n] = np.linalg.solve(A, b) 
 
b = np.zeros(n) 
d = np.zeros(n) 
 
for i in range(n): 
    b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2 * c[i] + c[i + 1]) / 3 
    d[i] = (c[i + 1] - c[i]) / (3 * h[i])  
 
x_values = [4, 5.5] 
y_values = [spline_interpolate(xq) for xq in x_values] 
 
for xi, yi in zip(x_values, y_values): 
    print(f"f({xi}) = {yi:.4f}")
print('---------------------------------------------')
print('Bai 3')
x = np.array([2, 4, 7, 8.5, 9.5, 11]) 
y = np.array([2.2, 4.2, 6.8, 8.1, 9.7, 10.5]) 
 
n = len(x) 
X = np.vstack((x, np.ones(n))).T  # Ma trận thiết kế [[x, 1]] 
a, b = np.linalg.lstsq(X, y, rcond=None)[0]  # Giải phương trình X * [a, b] = y 
x_query = 6 
y_query = a * x_query + b 
 
print(f"Hàm hồi quy: R(x) = {a:.4f}x + {b:.4f}") 
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')
print('Bai 4')
x = np.array([1, 2.1, 2.9, 3.8, 5, 6.2]) 
y = np.array([3.021, 4.219, 5.018, 5.986, 7.139, 8.138]) 
 
n = len(x) 
X = np.vstack((x, np.ones(n))).T  # Ma trận thiết kế [[x, 1]] 
a, b = np.linalg.lstsq(X, y, rcond=None)[0]  # Giải phương trình X * [a, b] = y 
x_query = 4.5 
y_query = a * x_query + b 
 
print(f"Hàm hồi quy: R(x) = {a:.4f}x + {b:.4f}") 
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')
print('Bai 5')
x = np.array([1, 1.6, 2.1, 3, 3.3, 3.7, 4.1, 4.9, 6.2]) 
y = np.array([1.1, 2.2, 3.5, 4.9, 7.2, 7.8, 7.9, 8.5, 10]) 
 
n = len(x) 
X = np.vstack((x, np.ones(n))).T  # Ma trận thiết kế [[x, 1]] 
a, b = np.linalg.lstsq(X, y, rcond=None)[0]  # Giải phương trình X * [a, b] = y 
x_query = 3.5 
y_query = a * x_query + b 
 
print(f"Hàm hồi quy: R(x) = {a:.4f}x + {b:.4f}") 
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')

#####################################################
def exp_regression(x, k, a):                              #
    return a * np.exp(k * x)                        #
#####################################################

print('Bai 6')
x = np.array([1.1, 3.2, 5.1, 7.7, 9.6, 12.2])
y = np.array([3.1, 29.9, 65.7, 100.4, 195.7, 300.4])

y_log = np.log(y)

n = len(x)
X = np.vstack((x, np.ones(n))).T

k, ln_a = np.linalg.lstsq(X, y_log, rcond=None)[0]

a = np.exp(ln_a)

x_query = 8.5
y_query = exp_regression(x_query, k, a)

print(f"Hàm hồi quy: R(x) = {a:.4f} * e^({k:.4f} * x)")
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')
print('Bai 7')
x = np.array([2, 4, 7, 8.5, 9.5, 11])
y = np.array([2.2, 2.5, 2.7, 3.1, 3.2, 3.5])

y_log = np.log(y)

n = len(x)
X = np.vstack((x, np.ones(n))).T

k, ln_a = np.linalg.lstsq(X, y_log, rcond=None)[0]

a = np.exp(ln_a)

x_query = 7.7
y_query = exp_regression(x_query, k, a)

print(f"Hàm hồi quy: R(x) = {a:.4f} * e^({k:.4f} * x)")
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')
print('Bai 8')
x = np.array([3, 3.4, 4.1, 4.3, 4.7, 5.3, 6, 6.4, 5])
y = np.array([1.23, 1.4, 1.69, 1.79, 2.13, 2.52, 2.45, 2.97, 3.44])

y_log = np.log(y)

n = len(x)
X = np.vstack((x, np.ones(n))).T

k, ln_a = np.linalg.lstsq(X, y_log, rcond=None)[0]

a = np.exp(ln_a)

x_query = 5
y_query = exp_regression(x_query, k, a)

print(f"Hàm hồi quy: R(x) = {a:.4f} * e^({k:.4f} * x)")
print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")
print('---------------------------------------------')
print('Bai 9')
def least_squares(x, y):
    n = len(x)
    X = np.vstack((x, np.ones(n))).T
    
    a, b = np.linalg.lstsq(X, y, rcond=None)[0]
    
    return a, b

def predict(x_query, a, b):
    return a * x_query + b

def printResult(x, y, x_query):
    a, b = least_squares(x, y)

    y_query = predict(x_query, a, b)

    print(f"Hàm hồi quy: R(x) = {a:.4f}x + {b:.4f}")
    print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")

# Bai 3:
print('Bai 9 - Bai 3')
x3 = np.array([2, 4, 7, 8.5, 9.5, 11]) 
y3 = np.array([2.2, 4.2, 6.8, 8.1, 9.7, 10.5])

x_query3 = 6
printResult(x3, y3, x_query3)

# Bai 4:
print('Bai 9 - Bai 4')
x4 = np.array([1, 2.1, 2.9, 3.8, 5, 6.2]) 
y4 = np.array([3.021, 4.219, 5.018, 5.986, 7.139, 8.138]) 

x_query4 = 4.5
printResult(x4, y4, x_query4)

# Bai 5:
print('Bai 9 - Bai 5')
x5 = np.array([1, 1.6, 2.1, 3, 3.3, 3.7, 4.1, 4.9, 6.2]) 
y5 = np.array([1.1, 2.2, 3.5, 4.9, 7.2, 7.8, 7.9, 8.5, 10]) 
 
x_query5 = 3.5
printResult(x5, y5, x_query5)
print('---------------------------------------------')
# Bai 10:
print('Bai 10')
def least_squares_1(x, y):
    y_log = np.log(y)

    n = len(x)
    X = np.vstack((x, np.ones(n))).T

    k, ln_a = np.linalg.lstsq(X, y_log, rcond=None)[0]

    a = np.exp(ln_a)
    
    return a, k

def printResult_1(x, y, x_query):
    a, k = least_squares_1(x, y)

    y_query = exp_regression(x_query, k, a)

    print(f"Hàm hồi quy: R(x) = {a:.4f} * e^({k:.4f} * x)")
    print(f"Giá trị nội suy tại x = {x_query}: f({x_query}) = {y_query:.4f}")

# Bai 6:
print('Bai 10 - Bai 6')
x6 = np.array([1.1, 3.2, 5.1, 7.7, 9.6, 12.2])
y6 = np.array([3.1, 29.9, 65.7, 100.4, 195.7, 300.4])

x_query6 = 8.5
printResult_1(x6, y6, x_query6)

# Bai 7:
print('Bai 10 - Bai 7')
x7 = np.array([2, 4, 7, 8.5, 9.5, 11])
y7 = np.array([2.2, 2.5, 2.7, 3.1, 3.2, 3.5]) 

x_query7 = 7.7
printResult_1(x7, y7, x_query7)

# Bai 8:
print('Bai 10 - Bai 8')
x8 = np.array([3, 3.4, 4.1, 4.3, 4.7, 5.3, 6, 6.4, 5])
y8 = np.array([1.23, 1.4, 1.69, 1.79, 2.13, 2.52, 2.45, 2.97, 3.44])
 
x_query8 = 5
printResult_1(x8, y8, x_query8)
print('---------------------------------------------')
# Bai 13:
print("Bài 13:")
def spline(x, y, x_query):
    n = len(x) - 1
    h = np.diff(x)
    A = np.zeros((n - 1, n - 1))
    b = np.zeros(n - 1)
    for i in range(1, n):
        A[i - 1, i - 1] = 2 * (h[i - 1] + h[i]) 
        if i - 1 > 0:
            A[i - 1, i - 2] = h[i - 1] 
        if i < n - 1:
            A[i - 1, i] = h[i] 

        b[i - 1] = 3 * ((y[i + 1] - y[i]) / h[i] - (y[i] - y[i - 1]) / h[i - 1])
    c = np.zeros(n + 1)
    c[1:n] = np.linalg.solve(A, b)

    b = np.zeros(n)
    d = np.zeros(n)

    for i in range(n):
        b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (2 * c[i] + c[i + 1]) / 3
        d[i] = (c[i + 1] - c[i]) / (3 * h[i])
    def spline_interpolate(x_query):
        for i in range(n):
            if x[i] <= x_query <= x[i + 1]:
                dx = x_query - x[i]
                return y[i] + b[i] * dx + c[i] * dx**2 + d[i] * dx**3
        return None

    y_query = [spline_interpolate(xq) for xq in x_query]

    return y_query

print("Giải lại bài 1:")
x = np.array([2, 4, 7, 8])
y = np.array([2.2, 1.8, 2.7, 3.1])
x_query = np.array([3, 7.5])
y_query = spline(x, y, x_query)

for xi, yi in zip(x_query, y_query):
    print(f"f({xi}) = {yi:.4f}")

print("Giải lại bài 2:")
x = np.array([2.2, 3.6, 4.9, 5.2, 5.7, 6.4])
y = np.array([1.4, 3.2, 5.1, 4.4, 3.9, 3.2])
x_query = np.array([4, 5.5])
y_query = spline(x, y, x_query)

for xi, yi in zip(x_query, y_query):
    print(f"f({xi}) = {yi:.4f}")