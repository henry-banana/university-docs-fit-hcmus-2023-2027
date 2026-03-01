#include <iostream>

class Ngay {
private:
    int _ngay, _thang, _nam;
    static int arrNgayCuaThang[][13];
    static bool laNamNhuan(const int& nam);    
public:
    Ngay();
    Ngay(const int& ngay);
    ~Ngay();
    void Xuat(std::ostream& os);
};

// ======================================================================

int main() {
    Ngay n1;
    Ngay n2(1000);
    Ngay n3(2000);
    Ngay n4(3000);
    Ngay n5(5000);

    n1.Xuat(std::cout); std::cout << "\n";
    n2.Xuat(std::cout); std::cout << "\n";
    n3.Xuat(std::cout); std::cout << "\n";
    n4.Xuat(std::cout); std::cout << "\n";
    n5.Xuat(std::cout); std::cout << "\n";

    return 0;
}

// ======================================================================
Ngay::Ngay() : _ngay(1), _thang(1), _nam(1) {}

Ngay::Ngay(const int& ngay) : _ngay(ngay >= 0 ? ngay : -ngay), _thang(1), _nam(1) {
    if (_ngay == 0) {
        _ngay = 1;
        return;
    }

    int idx_nam = laNamNhuan(_nam);
    while (_ngay > arrNgayCuaThang[idx_nam][_thang]) {
        _ngay -= arrNgayCuaThang[idx_nam][_thang];
        _thang++;
        if (_thang > 12) {
            _thang = 1;
            _nam++;
            idx_nam = laNamNhuan(_nam);
        }
    }
}

Ngay::~Ngay() {}

bool Ngay::laNamNhuan(const int& nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

void Ngay::Xuat(std::ostream& os) {
    os << _ngay << "-" << _thang << "-" << _nam;
}

int Ngay::arrNgayCuaThang[][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};