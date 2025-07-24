#include <iostream>
#include <string>
#include <limits>

std::string toBinaryString(unsigned int value, int length) {
    std::string result(length, '0');

    for (int i = length - 1; i >= 0; --i) {
        result[i] = (value & 1) + '0';
        value >>= 1;
    }

    return result;
}

void dumpFloat(float *p) {
    unsigned int *i = (unsigned int *)p;
    unsigned int sign = (*i >> 31) & 1;          // Trích xuất bit dấu
    unsigned int exponent = (*i >> 23) & ((1 << 8) - 1);     // Trích xuất 8 bit phần mũ - 11111111 sẽ bằng 2^8 - 1 nên công thức sẽ là (1 << số bit muôn tíc) - 1
    unsigned int significand = *i & ((1 << 23) - 1);      // Trích xuất 23 bit phần trị

    std::string signStr = toBinaryString(sign, 1);
    std::string exponentStr = toBinaryString(exponent, 8);
    std::string significandStr = toBinaryString(significand, 23);

    std::cout << "Dau: " << signStr << "\n";
    std::cout << "Phan mu: " << exponentStr << "\n";
    std::cout << "Phan tri: " << significandStr << "\n";
    std::cout << "Bieu dien nhi phan:\n" << signStr << "\n" << exponentStr << "\n" << significandStr << "\n";
}

bool isValidFloatInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    float value;
    while (true) {
        std::cout << "Nhap vao so cham dong (32-bit): ";
        std::cin >> value;

        if (isValidFloatInput()) {
            break;
        } else {
            std::cout << "Gia tri nhap vao khong hop le. Vui long nhap lai!\n";
        }
    }

    dumpFloat(&value);

    return 0;
}