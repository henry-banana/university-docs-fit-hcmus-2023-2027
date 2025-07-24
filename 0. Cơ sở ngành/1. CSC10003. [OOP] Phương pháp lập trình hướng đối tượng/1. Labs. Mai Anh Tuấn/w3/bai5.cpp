#include <iostream>
#include <cstring>

class SoNguyenLon {
private:
    int _size;
    char* _a;

    static SoNguyenLon _snl_max;
    void CapNhatSNLMax();
    void LimitDigits();
public:
    SoNguyenLon();
    SoNguyenLon(const int& x);
    SoNguyenLon(const int& x, const int& size);
    ~SoNguyenLon();

    SoNguyenLon(const SoNguyenLon& snl);
    SoNguyenLon& operator=(const SoNguyenLon& snl);

    bool operator>(const SoNguyenLon& snl) const;

    friend SoNguyenLon operator-(const SoNguyenLon& snl1, const SoNguyenLon& snl2);
    friend SoNguyenLon operator-(const long long s1, const SoNguyenLon& snl2);

    friend SoNguyenLon operator+(const SoNguyenLon& snl1, const SoNguyenLon& s2);
    friend SoNguyenLon operator+(const SoNguyenLon& snl1, const long long s2);

    friend std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl);

    static SoNguyenLon SNLMax();
};

// ===============================

SoNguyenLon SoNguyenLon::_snl_max;

int main() {
    SoNguyenLon snl1;
    SoNguyenLon snl2(1234567);
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 45678910 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;

    std::cout << snl1 << "\n" << snl2 << "\n" << snl3 << "\n";
    std::cout << snl4 << "\n" << snl5 << "\n" << snl6 << "\n";
    std::cout << snl7 << "\n" << "\n";
    std::cout << "SoNguyenLon Max:" << "\n";
    std::cout << SoNguyenLon::SNLMax() << "\n";

    return 0;
}

// ===============================
void SoNguyenLon::LimitDigits() {
    const int MAX_DIGITS = 100;
    int current_length = strlen(_a);
    
    if (current_length > MAX_DIGITS) {
        char* new_a = new char[MAX_DIGITS + 1];
        strncpy(new_a, _a, MAX_DIGITS);
        new_a[MAX_DIGITS] = '\0';
        
        delete[] _a;
        _a = new_a;
        _size = MAX_DIGITS + 1;
    }
}

SoNguyenLon operator-(const SoNguyenLon& snl1, const SoNguyenLon& snl2) {
    SoNguyenLon result;

    if (!(snl1 > snl2)) {
        return result;
    }

    int len1 = strlen(snl1._a);
    int len2 = strlen(snl2._a);
    int len = std::max(len1, len2);
    char* a = new char[len + 1];
    int i = len1 - 1;
    int j = len2 - 1;
    int t = 0;

    for (int l = len - 1; l >= 0; l--) {
        int x = i >= 0 ? snl1._a[i] - '0' : 0;
        int y = j >= 0 ? snl2._a[j] - '0' : 0;
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

    a[len] = '\0';
    result._size = len + 1;

    if (result._a) {
        delete[] result._a;
    }

    result._a = a;
    result.LimitDigits();
    result.CapNhatSNLMax();
    
    return result;
}

SoNguyenLon operator-(const long long s1, const SoNguyenLon& snl2) {
    SoNguyenLon snl1(s1);
    return snl1 - snl2;
}

SoNguyenLon operator+(const SoNguyenLon& snl1, const SoNguyenLon& s2) {
    SoNguyenLon result;

    int len1 = strlen(snl1._a);
    int len2 = strlen(s2._a);
    int len = std::max(len1, len2) + 1;
    char* a = new char[len + 1];
    int i = len1 - 1;
    int j = len2 - 1;
    int t = 0;

    for (int l = len - 1; l >= 0; l--) {
        int x = i >= 0 ? snl1._a[i] - '0' : 0;
        int y = j >= 0 ? s2._a[j] - '0' : 0;
        int z = x + y + t;

        if (z >= 10) {
            z -= 10;
            t = 1;
        }
        else {
            t = 0;
        }

        a[l] = z + '0';
        i--;
        j--;
    }

    a[len] = '\0';


    int start = 0;
    while (a[start] == '0' && start < len - 1) {
        start++;
    }

    result._size = len - start + 1;
    if (result._a) {
        delete[] result._a;
    }

    result._a = new char[result._size];
    strcpy(result._a, a + start);

    delete[] a;
    result._a[result._size - 1] = '\0';
    result.LimitDigits();
    result.CapNhatSNLMax();

    return result;
}

SoNguyenLon operator+(const SoNguyenLon& snl1, const long long s2) {
    SoNguyenLon snl2(s2);
    return snl1 + snl2;
}

std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl) {
    os << snl._a << "\n";
    return os;
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

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
    _size = snl._size;
    _a = new char[_size + 1];
    strcpy(_a, snl._a);
    CapNhatSNLMax();
}

SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl) {
    if (this != &snl) {
        if (_a) {
            delete[] _a;
        }
        _size = snl._size;
        _a = new char[_size + 1];
        strcpy(_a, snl._a);
    }

    return *this;
}

void SoNguyenLon::CapNhatSNLMax() {
    if (*this > _snl_max) {
        _snl_max = *this;
    }
}

SoNguyenLon SoNguyenLon::SNLMax() {
    return _snl_max;
}

SoNguyenLon::~SoNguyenLon() {
    if (_a) {
        delete[] _a;
    }
    _size = 0;
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
    LimitDigits();
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
    LimitDigits();
    CapNhatSNLMax();
}

SoNguyenLon::SoNguyenLon() {
    _size = 2;
    _a = new char[_size];
    strcpy(_a, "0");
    CapNhatSNLMax();
}