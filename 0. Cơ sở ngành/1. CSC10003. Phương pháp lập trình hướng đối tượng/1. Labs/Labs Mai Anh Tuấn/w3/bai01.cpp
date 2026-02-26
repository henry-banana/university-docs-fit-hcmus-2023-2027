#include <iostream>

class SoPhuc {
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int&, const int&);

    SoPhuc operator+(const int&);
    void operator<<(std::ostream&);
};

// =======================================================

int main() {
    SoPhuc sp1(3, 5);
    SoPhuc sp2 = sp1.operator+(10);
    SoPhuc sp3 = sp1 + 10;
    
    sp1.operator<<(std::cout);
    std::cout << "\n";

    sp2.operator<<(std::cout);
    std::cout << "\n";
    
    sp3.operator<<(std::cout);
    std::cout << "\n";
    
    return 0;
}

// =======================================================

SoPhuc::SoPhuc() : _ao(0), _thuc(0) {}

SoPhuc::SoPhuc(const int &t, const int &a) : _ao(a), _thuc(t) {}

SoPhuc SoPhuc::operator+(const int &n) {
    SoPhuc rt = *this;
    rt._thuc += n;
    return rt;
}

void SoPhuc::operator<<(std::ostream& os) {
    os << _thuc; 
    if (_ao != 0) {
        os << ((_ao > 0) ? " + " : " - ") << _ao << "i"; 
    }
}