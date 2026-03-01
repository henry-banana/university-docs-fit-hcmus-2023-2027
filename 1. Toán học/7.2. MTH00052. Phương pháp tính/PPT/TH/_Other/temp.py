import numpy as np
import matplotlib.pyplot as plt



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