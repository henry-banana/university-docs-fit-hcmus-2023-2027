#include "main.h"

// ============================= MAIN ===============================
int main() {
    
    cout << "Chuong trinh chuyen doi so nguyen X 4 bytes thanh day bit nhi phan va nguoc lai\n";
    
    bool isEnterNumber32bit = isEnterInt32bit();
    string line = enterValue(isEnterNumber32bit);
    
    if (isEnterNumber32bit) {
        string binary_arr = convertInt32bitToBinaryBitArray(line);
        cout << std::format("Day bit nhi phan cua {} la: {}\n",
            line, binary_arr);
        }
    
    else {
        int32_t num = convertBinaryArrayToInt32bit(line);
        cout << std::format("So nguyen 4 bytes cua day bit {} la: {}\n",
        line, num);
    }
    
    return 0;
}
// ==================================================================

bool checkInt32bit(const string& x) {
    regex int32bit_check("^-?\\d{1,10}$");  //Kiểm tra xem chuỗi có bắt đầu bằng dấu - (nếu có) và theo sau là 1 đến 10 chữ số hay không
    if (!std::regex_match(x, int32bit_check)) {
        return false;
    }

    int64_t value = std::stoll(x); // Để kiểm tra có vượt ngoài vùng của số int 32bit hay không, nên dùng 64 bit
    return value >= INT32_MIN && value <= INT32_MAX;
}

bool checkBinaryArray(const string& a) {
    regex binary_check(R"(^[01]{1,32}$)");
    return std::regex_match(a, binary_check);
}

string convertInt32bitToBinaryBitArray(const string& x) {
    int32_t num = std::stoi(x);
    string result(32, '0');

    for (int i = result.size() - 1; i >= 0; --i) {
        result[i] = (num & 1) + '0';
        num >>= 1;
    }

    return result;
}

int32_t convertBinaryArrayToInt32bit(const string& a) {
    int64_t num = 0,
            size = a.size();

    bool isNegative = (a[0] == '1');

    for (int i = 0; i < size; ++i) {
        num = (num << 1) | (a[i] - '0');
    }
    
    if (isNegative) {
        num -= (int64_t(1) << size);
    }
    
    
    return int64_t(num);
}

bool isEnterInt32bit() {
    string input = "";
    bool loop = false;

    do {
        loop = false;
        cout << "Chon 0 de chuyen doi so nguyen 4 bytes thanh day bit\nChon 1 de chuyen doi day 32bit thanh so nguyen\n";
        cout << "Nhap: ";

        if (!getline(cin, input)) {
            if (cin.eof()) {  
                cout << "\nThoat chuong trinh!\n";
                exit(0);
            }
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Loi nhap du lieu, vui long thu lai!\n";
            loop = true;
            continue;
        }

        if ((input != "0") 
            && (input != "1")) {
            loop = true;
            cout << "Khong hop le, vui long chon lai!\n";
        }
    } while (loop);

    return (input == "0");
}

string enterValue(const bool& isEnterNumber32bit) {
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
            bool found = isEnterNumber32bit ? checkInt32bit(buffer) : checkBinaryArray(buffer);
            
            if (!found) {
                cout << "Du lieu khong hop le\n";
                cout << "Vui long nhap du lieu hop le (So nguyen 4 bytes hoac day nhi phan 32bit)\n\n";
                needReenter = true;
            } 
        }
    } while (needReenter);
    
    if (!isEnterNumber32bit) {
        buffer = string(32 - buffer.size(), '0') + buffer;
    }

    return buffer;
}
