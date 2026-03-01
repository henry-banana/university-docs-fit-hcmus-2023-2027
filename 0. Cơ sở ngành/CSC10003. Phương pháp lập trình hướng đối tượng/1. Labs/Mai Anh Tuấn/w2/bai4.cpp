#include <iostream>
#include <cstring>

class SoNguyenLon {
private:
    int _size;
    char* _a;

    static SoNguyenLon _snl_max;
    void CapNhatSNLMax();
public:
    SoNguyenLon();
    SoNguyenLon(const char* str);
    SoNguyenLon(const int& x);
    SoNguyenLon(const int& n, const int& x);
    ~SoNguyenLon();

    void In(std::ostream& os) const;
    SoNguyenLon Tru(const SoNguyenLon& snl) const;
    SoNguyenLon Cong(const int& x) const;
	SoNguyenLon(const SoNguyenLon& other);
    SoNguyenLon operator=(const SoNguyenLon& snl);
    bool operator>(const SoNguyenLon& snl) const;

    static SoNguyenLon HieuVoiHangSo(const int& x, const SoNguyenLon& snl);
    static SoNguyenLon SNLMax();
};

// ===============================

SoNguyenLon SoNguyenLon::_snl_max;

int main() {
    SoNguyenLon snl1;
    SoNguyenLon snl2("1234567");
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3.Tru(snl2);
    SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
    SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);

    snl1.In(std::cout);
    std::cout << "\n";

    snl2.In(std::cout);
    std::cout << "\n";

    snl3.In(std::cout);
    std::cout << "\n";

    snl4.In(std::cout);
    std::cout << "\n";

    snl5.In(std::cout);
    std::cout << "\n";

    snl6.In(std::cout);
    std::cout << "\n";

    snl7.In(std::cout);
    std::cout << "\n";

    std::cout << "\nSoNguyenLon Max:" << "\n";
    SoNguyenLon::SNLMax().In(std::cout);
    std::cout << "\n";

    return 0;
}

// ===============================
SoNguyenLon::SoNguyenLon(const SoNguyenLon& other) {
    _size = other._size;
    _a = new char[_size];
    strcpy(_a, other._a);
}

bool SoNguyenLon::operator>(const SoNguyenLon& snl) const {
    if (strlen(_a) > strlen(snl._a)) {
        return true;
    }

    if (strlen(_a) == strlen(snl._a)) {
        if (strcmp(_a, snl._a) > 0) {
            return true;
        }
    }

    return false;
}

void SoNguyenLon::CapNhatSNLMax() {
    if (*this > _snl_max) {
        _snl_max = *this;
    }
}

SoNguyenLon::SoNguyenLon() {
    _size = 2;
    _a = new char[_size];
    strcpy(_a, "0");
    CapNhatSNLMax();
}

SoNguyenLon::SoNguyenLon(const char* str) {
    _size = strlen(str) + 1;
    _a = new char[_size];
    strcpy(_a, str);
    CapNhatSNLMax();
}

SoNguyenLon::SoNguyenLon(const int& x) {
    _size = 0;
    int temp = x;

    while (temp > 0) {
        temp /= 10;
        _size++;
    }

    _a = new char[_size + 1];
    temp = x;

    for (int i = _size - 1; i >= 0; i--) {
        _a[i] = temp % 10 + '0';
        temp /= 10;
    }

    _a[_size] = '\0';
    CapNhatSNLMax();
}

SoNguyenLon::SoNguyenLon(const int& x, const int& n) {
    if (n <= 0 || x < 0 || x > 9) {
        _size = 2;
        _a = new char[_size];
        strcpy(_a, "0");
    }
    else {
        _size = std::min(n, 100) + 1;
        _a = new char[_size];
        for (int i = 0; i < _size - 1; i++) {
            _a[i] = x + '0';
        }
        _a[_size - 1] = '\0';
    }
    CapNhatSNLMax();
}

SoNguyenLon::~SoNguyenLon() {
    if (_a) {
        delete[] _a;
    }
    _size = 0;
}

void SoNguyenLon::In(std::ostream& os) const {
    os << _a;
}
SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon& snl) const {
    if (snl > *this) {
        return SoNguyenLon("0");
    }

    int n = strlen(_a);
    int m = strlen(snl._a);
    int k = n > m ? n : m;
    char* a = new char[k + 1];
    int i = n - 1;
    int j = m - 1;
    int t = 0;

    for (int l = k - 1; l >= 0; l--) {
        int x = i >= 0 ? _a[i] - '0' : 0;
        int y = j >= 0 ? snl._a[j] - '0' : 0;
        int z = x - y - t;
        if (z < 0) {
            z += 10;
            t = 1;
        }
        else {
            t = 0;
        }
        a[l] = z + '0';
        i--;
        j--;
    }

    a[k] = '\0';
    SoNguyenLon snl1(a);
    delete[] a;
    return snl1;
}
SoNguyenLon SoNguyenLon::Cong(const int& x) const {
    int n = strlen(_a);
    int k = n > 1 ? n : 1;
    char* a = new char[k + 1];
    int i = n - 1;
    int t = x;

    for (int l = k - 1; l >= 0; l--) {
        int z = i >= 0 ? _a[i] - '0' + t : t;
        a[l] = z % 10 + '0';
        t = z / 10;
        i--;
    }

    a[k] = '\0';
    SoNguyenLon snl1(a);
    delete[] a;

    snl1.CapNhatSNLMax();
    return snl1;
}
SoNguyenLon SoNguyenLon::operator=(const SoNguyenLon& snl) {
	if (this == &snl) {
		return *this;
	}
	if (_a) {
		delete[] _a;
	}
	_size = snl._size;
	_a = new char[_size];
	strcpy(_a, snl._a);
	return *this;
}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(const int& x, const SoNguyenLon& snl) {
    SoNguyenLon snl1(x);
    return snl1.Tru(snl);
}

SoNguyenLon SoNguyenLon::SNLMax() {
    return _snl_max;
}