#include <iostream>

class SoPhuc {
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int&);
    SoPhuc(const int&, const int&);

    SoPhuc operator+(const SoPhuc&);
    void operator<<(std::ostream&);
};

// =======================================================

int main() {
    SoPhuc sp1(3, 5);
    SoPhuc sp3 = sp1 + 10;
    
    sp1.operator<<(std::cout);
    std::cout << "\n";
    
    sp3.operator<<(std::cout);
    std::cout << "\n";
    
    return 0;
}

// =======================================================

SoPhuc::SoPhuc() {
    _thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int &t) : SoPhuc() {
    std::cout << "Using...\n";
    _thuc = t;
}

SoPhuc::SoPhuc(const int &t, const int &a) {
    _thuc = t;
    _ao = a;
}

SoPhuc SoPhuc::operator+(const SoPhuc &sp) {
    SoPhuc rt = *this;
    rt._thuc += sp._thuc;
    rt._ao += sp._ao;
    return rt;
}

void SoPhuc::operator<<(std::ostream& os) {
    os << _thuc;
    if (_ao != 0) { 
        os << ((_ao > 0) ? " + " : " - ") << abs(_ao) << "i"; 
    }
}