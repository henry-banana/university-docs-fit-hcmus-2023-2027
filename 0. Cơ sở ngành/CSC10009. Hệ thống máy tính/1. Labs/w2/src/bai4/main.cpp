#include <iostream>
#include <iomanip>

int main() {
    // 1. Chuyển đổi float -> int -> float
    float f1 = 3.14159f;
    int i1 = (int)(f1);
    float f1_converted = (float)(i1);
    std::cout << "1. Chuyen doi float -> int -> float: " << std::fixed << std::setprecision(5) << f1 << " -> " << i1 << " -> " << f1_converted << " (Kết quả như ban đầu? " << (f1 == f1_converted ? "true" : "false") << ")\n";

    // 2. Chuyển đổi int -> float -> int
    int i2 = 123456789;
    float f2 = (float)(i2);
    int i2_converted = (int)(f2);
    std::cout << "2. Chuyen doi int -> float -> int: " << i2 << " -> " << f2 << " -> " << i2_converted << " (Kết quả như ban đầu? " << (i2 == i2_converted ? "true" : "false") << ")\n";

    // 3. Phép cộng số chấm động có tính kết hợp?
    float x = 1.0e20f, y = -1.0e20f, z = 1.0f;
    bool associative = ((x + y) + z) == (x + (y + z));
    std::cout << "3. Phep cong dau cham dong? ((x + y) + z) == (x + (y + z)): " << std::boolalpha << associative << "\n";

    // 4. i = (int) (3.14159 * f)
    float f4 = 2.0f;
    int i4 = (int)(3.14159 * f4);
    std::cout << "4. i = (int) (3.14159 * f): " << i4 << "\n";

    // 5. f = f + (float) i
    float f5 = 2.5f;
    int i5 = 3;
    f5 = f5 + (float)(i5);
    std::cout << "5. f = f + (float) i: " << f5 << "\n";

    // 6. if (i == (int)((float) i)) { printf("true"); }
    int i6 = 123456789;
    if (i6 == (int)((float)(i6))) {
        std::cout << "6. i = (int)((float) i): true\n";
    } else {
        std::cout << "6. i = (int)((float) i): false\n";
    }

    // 7. if (i == (int)((double) i)) { printf("true"); }
    int i7 = 123456789;
    if (i7 == (int)(static_cast<double>(i7))) {
        std::cout << "7. i = (int)((double) i): true\n";
    } else {
        std::cout << "7. i = (int)((double) i): false\n";
    }

    // 8. if (f == (float)((int) f)) { printf("true"); }
    float f8 = 3.5f;
    if (f8 == (float)((int)(f8))) {
        std::cout << "8. f = (float)((int) f): true\n";
    } else {
        std::cout << "8. f = (float)((int) f): false\n";
    }

    // 9. if (f == (double)((int) f)) { printf("true"); }
    float f9 = 3.5f;
    if (f9 == static_cast<double>((int)(f9))) {
        std::cout << "9. f = (double)((int) f): true\n";
    } else {
        std::cout << "9. f = (double)((int) f): false\n";
    }

    return 0;
}