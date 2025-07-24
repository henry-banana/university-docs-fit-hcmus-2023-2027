#include <iostream>
#include <iomanip>
// ================== PROTOTYPE ==================
class ThoiGian {
private:
    int _gio, _phut, _giay;
    void chuanHoa();
public:
    ThoiGian();
    ThoiGian(const int& giay);
    ThoiGian(const int& phut, const int& giay);
    ThoiGian(const int& gio, const int& phut, const int& giay);
    ~ThoiGian();

    ThoiGian(const ThoiGian& tg);
    ThoiGian& operator=(const ThoiGian& tg);

    friend ThoiGian operator+(const ThoiGian& tg1, const ThoiGian& tg2);
    friend ThoiGian operator+(const int& giay, const ThoiGian& tg);

    friend ThoiGian operator-(const ThoiGian& tg1, const ThoiGian& tg2);
    friend ThoiGian operator-(const int& giay, const ThoiGian& tg2);

    friend bool operator<=(const ThoiGian& tg1, const ThoiGian& tg2);
    friend bool operator<=(const int& giay, const ThoiGian& tg2);

    friend std::ostream& operator<<(std::ostream& os, const ThoiGian& tg);
};


// ================== MAIN ==================
int main() {
    ThoiGian tg1; // 00:00:00
    ThoiGian tg2(1212); // 00:20:12
    ThoiGian tg3(125, 45); // 02:05:45
    ThoiGian tg4(12, 239, -78); // 16:00:18
    ThoiGian tg5 = tg2 + tg3; // 02:25:57
    ThoiGian tg6 = 5000 + tg2; // 01:43:32
    ThoiGian tg7 = tg4 - tg6; // 14:16:46
    ThoiGian tg8 = 12300 - tg4; // 00:00:00
    ThoiGian tg9, tg10;

    if (tg8 <= tg3) {
        tg9 = tg1 + tg2 + 36000; // 10:20:12
    }

    if (12345 <= tg5) {
        tg10 = tg5 + 12345; // 05:51:42
    }

    std::cout << tg1 << "\n" << tg2 << "\n" << tg3 << "\n" << tg4 << "\n";
    std::cout << tg5 << "\n" << tg6 << "\n" << tg7 << "\n" << tg8 << "\n";
    std::cout << tg9 << "\n" << tg10 << "\n";

    return 0;
}

// ================== IMPLEMENTATION ==================
ThoiGian::ThoiGian(const ThoiGian& tg) : _gio(tg._gio), _phut(tg._phut), _giay(tg._giay) {}

ThoiGian& ThoiGian::operator=(const ThoiGian& tg) {
    if (this != &tg) {
        _gio = tg._gio;
        _phut = tg._phut;
        _giay = tg._giay;
    }
    return *this;
}

ThoiGian operator+(const ThoiGian& tg1, const ThoiGian& tg2) {
    ThoiGian tg3;
    tg3._gio = tg1._gio + tg2._gio;
    tg3._phut = tg1._phut + tg2._phut;
    tg3._giay = tg1._giay + tg2._giay;
    tg3.chuanHoa();

    return tg3;
}

ThoiGian operator+(const int& giay, const ThoiGian& tg) {
    ThoiGian tg1(giay);
    ThoiGian tg2 = tg1 + tg;

    return tg2;
}


ThoiGian operator-(const ThoiGian& tg1, const ThoiGian& tg2) {
    ThoiGian tg3;
    
    if (tg1 <= tg2) {
		return tg3;
    }

    tg3._gio = tg1._gio - tg2._gio;
    tg3._phut = tg1._phut - tg2._phut;
    tg3._giay = tg1._giay - tg2._giay;
    tg3.chuanHoa();

    return tg3;
}

ThoiGian operator-(const int& giay, const ThoiGian& tg2) {
    ThoiGian tg1(giay);
    ThoiGian res = tg1 - tg2;

    return res;
}


bool operator<=(const ThoiGian& tg1, const ThoiGian& tg2) {
    if (tg1._gio < tg2._gio) return true;
    if (tg1._gio > tg2._gio) return false;
    if (tg1._phut < tg2._phut) return true;
    if (tg1._phut > tg2._phut) return false;
    if (tg1._giay <= tg2._giay) return true;

    return false;
}

bool operator<=(const int& giay, const ThoiGian& tg2) {
    ThoiGian tg1(giay);
    
	return tg1 <= tg2;
}

ThoiGian::ThoiGian() : _gio(0), _phut(0), _giay(0) {}

ThoiGian::ThoiGian(const int& giay) : _gio(0), _phut(0), _giay(giay <= 0 ? 0 : giay) {
    chuanHoa();
}

ThoiGian::ThoiGian(const int& phut, const int& giay) : _gio(0), _phut(abs(phut)), _giay(abs(giay)) {
    chuanHoa();
}

ThoiGian::ThoiGian(const int& gio, const int& phut, const int& giay) : _gio(abs(gio)), _phut(abs(phut)), _giay(abs(giay)) {
    chuanHoa();
}

ThoiGian::~ThoiGian() {

}

void ThoiGian::chuanHoa() {
    _giay = abs(_giay);
    _phut = abs(_phut);
    _gio = abs(_gio);

    _phut += _giay / 60;
    _giay %= 60;
    _gio += _phut / 60;
    _phut %= 60;
}

std::ostream& operator<<(std::ostream& os, const ThoiGian& tg) {
    os << std::setw(2) << std::setfill('0') << tg._gio << ":"
        << std::setw(2) << std::setfill('0') << tg._phut << ":"
        << std::setw(2) << std::setfill('0') << tg._giay << "\n";

    return os;
}