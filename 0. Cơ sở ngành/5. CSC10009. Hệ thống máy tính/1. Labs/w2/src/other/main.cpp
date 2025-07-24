#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include <cmath>

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
    unsigned int sign = (*i >> 31) & 1;
    unsigned int exponent = (*i >> 23) & ((1 << 8) - 1);
    unsigned int significand = *i & ((1 << 23) - 1);

    std::string signStr = toBinaryString(sign, 1);
    std::string exponentStr = toBinaryString(exponent, 8);
    std::string significandStr = toBinaryString(significand, 23);

    std::cout << "Dau: " << signStr << "\n";
    std::cout << "Phan mu: " << exponentStr << "\n";
    std::cout << "Phan tri: " << significandStr << "\n";
    std::cout << "Bieu dien nhi phan:\n" << signStr << " " << exponentStr << " " << significandStr << "\n";
}

bool isValidFloatInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

unsigned int binaryStringToUint(const std::string &binaryString) {
    unsigned int num = 0;
    for (char ch : binaryString) {
        num = (num << 1) | (ch - '0');
    }
    return num;
}

void forceFloat(float *p, char* s) {
    unsigned int num = binaryStringToUint(s);
    *(unsigned int *)p = num;
}

void printFloatValue(float value) {
    unsigned int i = *(unsigned int *)&value;
    unsigned int exponent = (i >> 23) & ((1 << 8) - 1);
    unsigned int significand = i & ((1 << 23) - 1);

    if (exponent == 0xFF) {
        if (significand == 0) {
            std::cout << (i >> 31 ? "-∞" : "+∞") << "\n";
        } else {
            std::cout << "NaN" << "\n";
        }
    } else if (exponent == 0) {
        if (significand == 0) {
            std::cout << (i >> 31 ? "-0.0" : "+0.0") << "\n";
        } else {
            std::cout << "Denormalized Number: " << value << "\n";
        }
    } else {
        std::cout << "Normalized Number: " << value << "\n";
    }
}

bool isValidBinaryInput(std::string s) {
    std::regex r("[01]{1}\\s[01]{8}\\s[01]{23}");
    return std::regex_match(s, r);
}

void performFloatOperations(float a, float b) {
    std::cout << "\n=== KET QUA CAC PHEP TOAN ===\n";
    
    // Phép cộng
    float sum = a + b;
    std::cout << "\nPhep cong: " << a << " + " << b << " = " << sum << "\n";
    dumpFloat(&sum);
    
    // Phép trừ
    float diff = a - b;
    std::cout << "\nPhep tru: " << a << " - " << b << " = " << diff << "\n";
    dumpFloat(&diff);
    
    // Phép nhân
    float product = a * b;
    std::cout << "\nPhep nhan: " << a << " * " << b << " = " << product << "\n";
    dumpFloat(&product);
    
    // Phép chia
    if (b != 0.0f) {
        float quotient = a / b;
        std::cout << "\nPhep chia: " << a << " / " << b << " = " << quotient << "\n";
        dumpFloat(&quotient);
    } else {
        std::cout << "\nKhong the thuc hien phep chia vi so chia bang 0\n";
    }
    
    std::cout << "\nSo sanh:\n";
    if (a > b) std::cout << a << " > " << b << "\n";
    else if (a < b) std::cout << a << " < " << b << "\n";
    else std::cout << a << " == " << b << "\n";
}

int main() {
    int choice;
    std::cout << "Chon che do nhap:\n";
    std::cout << "1. Nhap so thap phan\n";
    std::cout << "2. Nhap chuoi nhi phan\n";
    std::cout << "Lua chon cua ban: ";
    std::cin >> choice;
    std::cin.ignore();

    float value1, value2;

    if (choice == 1) {
        while (true) {
            std::cout << "Nhap vao so cham dong thu nhat (32-bit): ";
            std::cin >> value1;

            if (isValidFloatInput()) {
                break;
            } else {
                std::cout << "Gia tri nhap vao khong hop le. Vui long nhap lai!\n";
            }
        }

        while (true) {
            std::cout << "Nhap vao so cham dong thu hai (32-bit): ";
            std::cin >> value2;

            if (isValidFloatInput()) {
                break;
            } else {
                std::cout << "Gia tri nhap vao khong hop le. Vui long nhap lai!\n";
            }
        }
    } else if (choice == 2) {
        std::string input1, input2;
        
        std::cout << "Nhap vao chuoi nhi phan thu nhat (dang sign exponent significand): ";
        std::getline(std::cin, input1);

        if (!isValidBinaryInput(input1)) {
            std::cout << "Chuoi nhap vao khong hop le!\n";
            return 1;
        }

        std::cout << "Nhap vao chuoi nhi phan thu hai (dang sign exponent significand): ";
        std::getline(std::cin, input2);

        if (!isValidBinaryInput(input2)) {
            std::cout << "Chuoi nhap vao khong hop le!\n";
            return 1;
        }

        input1 = std::regex_replace(input1, std::regex("\\s"), "");
        forceFloat(&value1, &input1[0]);
        
        input2 = std::regex_replace(input2, std::regex("\\s"), "");
        forceFloat(&value2, &input2[0]);
    } else {
        std::cout << "Lua chon khong hop le!\n";
        return 1;
    }

    std::cout << "\n=== SO THU NHAT ===\n";
    dumpFloat(&value1);
    printFloatValue(value1);

    std::cout << "\n=== SO THU HAI ===\n";
    dumpFloat(&value2);
    printFloatValue(value2);

    performFloatOperations(value1, value2);

    return 0;
}