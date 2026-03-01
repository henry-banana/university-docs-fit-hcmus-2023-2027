#include <iostream>

class SoPhuc {
private:
    int _thuc, _ao;
    static int _sl;
public:
    SoPhuc();
    SoPhuc(const int& th, const int& a);
    SoPhuc(const SoPhuc& sp);
    ~SoPhuc();
    SoPhuc Cong(const SoPhuc& sp) const;
    static int SoLuongSP();
};

int SoPhuc::_sl = 0;

int main() {
    SoPhuc sp1;
    SoPhuc sp2(5, 10);
    SoPhuc sp3(sp1);
    SoPhuc sp4 = sp2.Cong(sp1);
    
    std::cout << SoPhuc::SoLuongSP() << "\n";
    
    {
        SoPhuc sp5;
        SoPhuc sp6 = sp2.Cong(sp4);
        std::cout << SoPhuc::SoLuongSP() << "\n";
    }

    std::cout << sp4.SoLuongSP() << "\n";
    std::cout << SoPhuc::SoLuongSP() << "\n";
    
    return 0;
}

SoPhuc::SoPhuc() : _thuc(0), _ao(0) {
    _sl++;
}

SoPhuc::SoPhuc(const int& th, const int& a) : _thuc(th), _ao(a) {
    _sl++;
}

SoPhuc::SoPhuc(const SoPhuc& sp) : _thuc(sp._thuc), _ao(sp._ao) {
    _sl++;
}

SoPhuc::~SoPhuc() {
    _sl--;
}

SoPhuc SoPhuc::Cong(const SoPhuc& sp) const {
    return SoPhuc(_thuc + sp._thuc, _ao + sp._ao);
}

int SoPhuc::SoLuongSP() {
    return _sl;
}