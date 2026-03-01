#include "main.h"

// ============================= MAIN ===============================
int main() {
    
    cout << "Chuong trinh tinh +, -, *, / cua 2 day bit duoc nhap vao\n";

    string str1 = enterValue();
    string str2 = enterValue();

    cout << format (
        "Phep cong cua 2 day bit {} ({}) va {} ({}) la\n{} ({})",
        str1, convertToNumber(str1),
        str2, convertToNumber(str2),
        addition(str1, str2), convertToNumber(addition(str1, str2))
    ) << "\n\n";
    
    cout << format (
        "Phep tru cua 2 day bit {} ({}) va {} ({}) la\n{} ({})",
        str1, convertToNumber(str1),
        str2, convertToNumber(str2),
        subtraction(str1, str2), convertToNumber(subtraction(str1, str2))
    ) << "\n\n";
    
    cout << format (
        "Phep nhan cua 2 day bit {} ({}) va {} ({}) la\n{} ({})",
        str1, convertToNumber(str1),
        str2, convertToNumber(str2),
        multiplication(str1, str2), convertToNumber(multiplication(str1, str2))
    ) << "\n\n";

    auto [Q, A] = division(str1, str2);
    if (Q == "00000000" && A == "00000000") {
        cout << "Phep chia khong thuc hien duoc vi chia cho 0.\n";
    } else {
        cout << format (
            "Phep chia cua 2 day bit {} ({}) va {} ({}) la\nPhan thuong: {} ({})\nPhan du: {} ({})",
            str1, convertToNumber(str1),
            str2, convertToNumber(str2),
            Q, convertToNumber(Q),
            A, convertToNumber(A)
        ) << "\n\n";
    }

    return 0;
}
// ==================================================================

string enterValue() {
    string buffer = "";
    bool needReenter = false;
    
    do {
        needReenter = false;
        cout << "Nhap du lieu: ";
        if (!getline(cin, buffer)) {
            if (cin.eof()) {  
                cout << "\nThoat chuong trinh!\n";
                exit(0);
            }
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Loi nhap du lieu, vui long thu lai!\n";
            needReenter = true;
            continue;
        }
        
        if (buffer.length() == 0) {
            cout << "Du lieu khong the bo trong\n";
            cout << "Vui long nhap lai\n\n";
            needReenter = true;
        } else {
            bool found = check8bitStr(buffer);
            
            if (!found) {
                cout << "Du lieu khong hop le\n";
                cout << "Vui long nhap du lieu hop le (Day nhi phan 8bit)\n\n";
                needReenter = true;
            } 
        }
    } while (needReenter);
    
    return string(8 - buffer.length(), '0') + buffer;
}

bool check8bitStr(const string& str) {
    regex binary_check(R"(^[01]{1,8}$)");
    return std::regex_match(str, binary_check);
}

int convertToNumber(const string& str) {
    int num = 0;
    int size = str.size();

    bool isNegative = (str[0] == '1');

    for (int i = 0; i < size; ++i) {
        num = (num << 1) | (str[i] - '0');
    }

    if (isNegative) {
        num -= (1 << size);
    }

    return num;
}

string convertToBinary(const int& num) {
    string result(8, '0');
    int temp = num;

    for (int i = 7; i >= 0; --i) {
        result[i] = (temp & 1) + '0';
        temp >>= 1;
    }

    return result;
}

string addition(const string& str1, const string& str2) {
    string result = "00000000";
    int carry = 0;

    for (int i = 7; i >= 0; --i) {
        int bit1 = str1[i] - '0';
        int bit2 = str2[i] - '0';
        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    return result;
}

string subtraction(const string& str1, const string& str2) {
    return addition(str1, convertToBinary(-convertToNumber(str2)));
}

string multiplication(const string& str1, const string& str2) {
    // thuat toan booth
    int k = 8;
    string A(8, '0');
    string Q = str2;
    int Q_1 = 0;
    string M = str1;

    while (k > 0) {
        if (Q[7] == '0' && Q_1 == 1) {
            A = addition(A, M);
        } else if (Q[7] == '1' && Q_1 == 0) {
            A = subtraction(A, M);
        }

        Q_1 = Q[7] - '0';
        Q = A[7] + Q.substr(0, 7);
        A = A[0] + A.substr(0, 7);
        --k;
    }

    return A + Q;
}

std::pair<string, string> division(const string& str1, const string& str2) {
    if (str2 == "00000000") {
        cout << "Loi: Khong the chia cho 0\n";
        return {"00000000", "00000000"};
    }

    string A(8, '0');
    bool symbol1 = (str1[0] == '1'),
         symbol2 = (str2[0] == '1');
    string Q = symbol1 ? convertToBinary(-convertToNumber(str1)) : str1;
    string M = symbol2 ? convertToBinary(-convertToNumber(str2)) : str2;
    int k = 8;

    while (k > 0) {
        A = A.substr(1, 7) + Q[0];
        Q = Q.substr(1, 7) + '0';
        A = subtraction(A, M);

        if (A[0] == '1') {
            Q[7] = '0';
            A = addition(A, M);
        } else {
            Q[7] = '1';
        }
        k--;
    }

    if (symbol1 != symbol2) {
        Q = convertToBinary(-convertToNumber(Q));
    }

    if (symbol1) {
        A = convertToBinary(-convertToNumber(A));
    }

    return {Q, A};
}