#include <iostream>
#include <cstring>

// ==================== PROTOTYPE ====================
class Ngay {
private:
    int _ngay, _thang, _nam;
    bool laNamNhuan(const int& nam) const;
    int soNgayTrongThang(const int& thang, const int& nam) const;
    void chuanHoa();
public:
    Ngay();
    Ngay(const int& ngay);
    Ngay(const int& ngay, const int& thang, const int& nam);
    Ngay(const char* s);
    ~Ngay();
    void xuatNgay() const;
};

// ==================== MAIN ====================
int main() {
    Ngay n1; // 1/1/1
    n1.xuatNgay();
    std::cout << '\n';

    Ngay n2(2, 10, 2024); // 2/10/2024
    n2.xuatNgay();
    std::cout << '\n';

    Ngay n3(-100, 16, 1990); // 10/3/1991
    n3.xuatNgay();
    std::cout << '\n';

    Ngay n4(1403); // 3/11/4
    n4.xuatNgay();
    std::cout << '\n';

    Ngay n5("12-12-2012"); // 12/12/2012
    n5.xuatNgay();
    std::cout << '\n';

    return 0;
}

// ==================== IMPLEMENTATION ====================
Ngay::Ngay() : _ngay(1), _thang(1), _nam(1) {}

Ngay::Ngay(const int& ngay) : _ngay(abs(ngay)), _thang(1), _nam(1) {
    chuanHoa();
}

Ngay::Ngay(const int& ngay, const int& thang, const int& nam) : _ngay(abs(ngay)), _thang(abs(thang)), _nam(abs(nam)) {
    chuanHoa();
}

Ngay::Ngay(const char* s) {
    char* buffer = new char[strlen(s) + 1];     // "12-12-2012\0"
    strcpy(buffer, s);

    char* token = strtok(buffer, "-/");
    _ngay = token ? atoi(token) : 1;

    token = strtok(nullptr, "-/");
    _thang = token ? atoi(token) : 1;

    token = strtok(nullptr, "-/");
    _nam = token ? atoi(token) : 1;

    delete[] buffer;
    chuanHoa();
}

Ngay::~Ngay() {

}

void Ngay::xuatNgay() const {
    std::cout << _ngay << '/' << _thang << '/' << _nam << "\n";
}

void Ngay::chuanHoa() {
    _ngay = abs(_ngay);
    _thang = abs(_thang);
    _nam = abs(_nam);

    // Xử lý ngày dư thừa
    while (_ngay > soNgayTrongThang(_thang, _nam)) {
        _ngay -= soNgayTrongThang(_thang, _nam);
        _thang++;
        if (_thang > 12) {
            _thang = 1;
            _nam++;
        }
    }

    // Xử lý tháng dư thừa  
    while (_thang > 12) {
        _thang -= 12;
        _nam++;
    }
}

int Ngay::soNgayTrongThang(const int& thang, const int& nam) const {
    if (thang == 2) {
        return laNamNhuan(nam) ? 29 : 28;
    }

    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }

    return 31;
}

bool Ngay::laNamNhuan(const int& nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}