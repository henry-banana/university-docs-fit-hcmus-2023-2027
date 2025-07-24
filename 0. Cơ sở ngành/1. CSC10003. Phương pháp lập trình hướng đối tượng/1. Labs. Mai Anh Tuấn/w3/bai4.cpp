#include <iostream>

class Ngay {
private:
    int _ngay, _thang, _nam;
    void chuanHoa();

    static int arrNgayCuaThang[][13];
    static bool laNamNhuan(const int& nam);    
public:
    Ngay();
    Ngay(const int& ngay);
    Ngay(const int& ngay, const int& thang, const int& nam);
    ~Ngay();

    friend Ngay operator+(const Ngay& n1, const Ngay& n2);
    friend Ngay operator+(const Ngay& n1, const int& n2);
    friend Ngay operator+(const int& n1, const Ngay& n2);

    friend Ngay operator-(const Ngay& n1, const Ngay& n2);
    friend Ngay operator-(const Ngay& n1, const int& n2);
    friend Ngay operator-(const int& n1, const Ngay& n2);

    friend bool operator>(const Ngay& n1, const Ngay& n2);
    
    friend std::ostream& operator<<(std::ostream& os, const Ngay& n);
};

// ======================================================================

int main() {
    Ngay n1; // 1/1/1

    Ngay n2(2, 10, 2014); // 2/10/2014

    Ngay n3(-10, 16, 2000); // 10/04/2001

    Ngay n4(1000); // 27/9/3

    Ngay n5 = n2 + n3; // 12/2/4016

    Ngay n6 = n1 + 5000; // 10/10/15

    Ngay n7 = 1234 + n4; // 14/2/7

    Ngay n8 = 190 + n6 + n7; // 2/7/23

    Ngay n9 = n8 - n6; // 1/9/7

    Ngay n10 = 12000 - n9; // 9/2/26
    
    if (n10 > n6) {
        n10 = n2 - 1000 + n6;
    }

    std::cout << n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n";

    std::cout << n5 << "\n" << n6 << "\n" << n7 << "\n" << n8 << "\n";

    std::cout << n9 << "\n" << n10 << "\n";

    return 0;
}

// ======================================================================
std::ostream& operator<<(std::ostream& os, const Ngay& n) {
    os << n._ngay << "/" << n._thang << "/" << n._nam;
    return os;
}

bool operator>(const Ngay& n1, const Ngay& n2) {
    if (n1._nam > n2._nam) {
        return true;
    } else if (n1._nam == n2._nam) {
        if (n1._thang > n2._thang) {
            return true;
        } else if (n1._thang == n2._thang) {
            return n1._ngay > n2._ngay;
        }
    }

    return false;
}

Ngay operator+(const Ngay& n1, const Ngay& n2) {
    Ngay res(n1._ngay + n2._ngay, n1._thang + n2._thang, n1._nam + n2._nam);
    res.chuanHoa();
    return res;
}

Ngay operator+(const Ngay& n1, const int& n2) {
    Ngay res(n1._ngay + n2, n1._thang, n1._nam);
    res.chuanHoa();
    return res;
}

Ngay operator+(const int& n1, const Ngay& n2) {
    Ngay res(n1 + n2._ngay, n2._thang, n2._nam);
    res.chuanHoa();
    return res;
}

Ngay operator-(const Ngay& n1, const Ngay& n2) {
    Ngay res(n1._ngay - n2._ngay, n1._thang - n2._thang, n1._nam - n2._nam);
    res.chuanHoa();
    return res;
}

Ngay operator-(const Ngay& n1, const int& n2) {
    Ngay res(n1._ngay - n2, n1._thang, n1._nam);
    res.chuanHoa();
    return res;
}

Ngay operator-(const int& n1, const Ngay& n2) {
    Ngay res(n1 - n2._ngay, n2._thang, n2._nam);
    res.chuanHoa();
    return res;
}


Ngay::Ngay() : _ngay(1), _thang(1), _nam(1) {}

Ngay::Ngay(const int& ngay) : _ngay(ngay >= 0 ? ngay : -ngay), _thang(1), _nam(1) {
    if (_ngay == 0) {
        _ngay = 1;
    }

    chuanHoa();
}

Ngay::Ngay(const int& ngay, const int& thang, const int& nam) : _ngay(abs(ngay)), _thang(abs(thang)), _nam(abs(nam)) {
    chuanHoa();
}

Ngay::~Ngay() {}

bool Ngay::laNamNhuan(const int& nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int Ngay::arrNgayCuaThang[][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void Ngay::chuanHoa() {
    _ngay = abs(_ngay);
    _thang = abs(_thang);
    _nam = abs(_nam);

    if (_ngay == 0) {
        _ngay = 1;
    }

    if (_thang == 0) {
        _thang = 1;
    }

    if (_nam == 0) {
        _nam = 1;
    }

    int la_nam_nhuan = Ngay::laNamNhuan(_nam);

    while (_thang > 12) {
        _thang -= 12;
        _nam++;
    }

    while (_ngay > arrNgayCuaThang[la_nam_nhuan][_thang]) {
        _ngay -= arrNgayCuaThang[la_nam_nhuan][_thang];
        _thang++;
        if (_thang > 12) {
            _thang = 1;
            _nam++;
        }
    }

    while (_thang > 12) {
        _thang -= 12;
        _nam++;
    }
}