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

    CString &operator++();
    CString operator++(int);
    char &operator[](const int &);
    CString &operator=(const CString &);
    friend std::ostream &operator<<(std::ostream &, const CString &);
};

// ===================================

int main() {
    const int iN = 2;
    CString cs1("cs1_content");
    std::cout << cs1 << "\n";
    std::cout << "cs1++: " << cs1++ << "\n" << cs1 << "\n";
    std::cout << "++ ++cs1: " << ++ ++cs1 << "\n" << cs1 << "\n";
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

CString::CString(const CString &cs) : CString(cs._mang) {}

CString &CString::operator=(const CString &cs) {
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

CString &CString::operator++() {
    if (_mang) {
        int len = strlen(_mang);
        _mang[len - 1]++;
    }

    return *this;
}

CString CString::operator++(int) {
    CString temp = *this;

    if (_mang != nullptr) { 
        int len = strlen(_mang);
        _mang[len - 1]++;
    }

    return temp;
}

std::ostream &operator<<(std::ostream &os, const CString &cs) {
    if (cs._mang)
        os << cs._mang;
    return os;
}