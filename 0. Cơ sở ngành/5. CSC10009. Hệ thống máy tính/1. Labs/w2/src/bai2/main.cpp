#include <iostream>
#include <string>
#include <limits>
#include <regex>

// Hàm kiểm tra xem một chuỗi có chỉ chứa '0' và '1' không
bool isBinaryString(const std::string &str) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}


unsigned int convectFloat(const std::string &binaryString) {
    unsigned int num = 0;
    for (char ch : binaryString) {
        num = (num << 1) | (ch - '0');
    }
    return num;
}

void forceFloat(float *p, char* s) {
    unsigned int num = convectFloat(s);
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

bool checkValid(std::string s) {
    std::regex r("[01]{1}\\s[01]{8}\\s[01]{23}");
    return std::regex_match(s, r);
}

int main() {
    std::string input;
    std::cout << "Nhap vao chuoi nhi phan (dang sign exponent significand): ";
    std::getline(std::cin, input);

    if (!checkValid(input)) {
        std::cout << "Chuoi nhap vao khong hop le!\n";
        return 1;
    }

    float value;
    input = std::regex_replace(input, std::regex("\\s"), "");
    forceFloat(&value, &input[0]);
    printFloatValue(value);

    return 0;
}