#include <iostream>
#include <cstring>

class CString {
private:
    char *_mang;

public:
    CString();
    CString(const char *);
    CString(const CString &);
    ~CString();

    char& operator[](const int &);
    CString& operator=(const CString &);
    friend std::ostream& operator<<(std::ostream &, const CString &);
};

// ===================================

int main() {
    const int iN = 2;
    CString cs1("cs1_content");
    std::cout << "cs2(cs1)" << "\n";
    CString cs2(cs1);
    cs2[iN] = '2';
    std::cout << "cs3 = cs1" << "\n";
    CString cs3 = cs1;
    cs3[iN] = '3';
    std::cout << cs1 << "\n" << cs2 << "\n" << cs3 << "\n";
    cs3 = cs2;
    std::cout << cs3 << "\n";
    return 0;
}

// ===================================
CString::CString() {
    _mang = nullptr;
}

CString::~CString() {
    if (_mang) {
        delete[] _mang;
    }
}

CString::CString(const char *str) {
    int len = strlen(str);
    _mang = new char[len + 1];
    strcpy_s(_mang, len + 1, str);
}

CString::CString(const CString &cs) : CString(cs._mang) {
    std::cout << "The copy constructor was called " << "\n";
}

CString &CString::operator=(const CString &cs) {
    std::cout << "The operator= was called" << "\n";
    
    if (_mang) {
        delete[] _mang;
    }

    int len = strlen(cs._mang) + 1;
    _mang = new char[len];
    strcpy_s(_mang, len, cs._mang);
    return *this;
}

char &CString::operator[](const int &i) {
    int len = strlen(_mang);
    if (i < 0 || i >= len) {
        throw std::out_of_range("out of range");
    }

    return _mang[i];
}

std::ostream &operator<<(std::ostream &os, const CString &cs) {
    os << cs._mang;
    return os;
}