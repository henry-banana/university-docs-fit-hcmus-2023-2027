#include <iostream>

class SoPhuc {
private:
    int _thuc, _ao;
public:
    SoPhuc();
    SoPhuc(const int&);
    SoPhuc(const int&, const int&);

    friend SoPhuc operator+(const int&, const SoPhuc&);
    friend std::ostream& operator<<(std::ostream&, const SoPhuc&);
};

// =======================================================

int main() {
    SoPhuc sp1(3, 5);
    SoPhuc sp2 = 10 + sp1;

    std::cout << sp1 << "\n";
    std::cout << sp2 << "\n";

    return 0;
}

// =======================================================

SoPhuc::SoPhuc(): _thuc(0), _ao(0) {}

SoPhuc::SoPhuc(const int& t) : SoPhuc() {
    _thuc = t;
}

SoPhuc::SoPhuc(const int& t, const int& a) : _thuc(t), _ao(a) {}

SoPhuc operator+(const int& n, const SoPhuc& sp) {
    SoPhuc spR(n);
    spR._thuc += sp._thuc;
    spR._ao += sp._ao;
    return spR;
}

std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    os << sp._thuc;

    if (sp._ao != 0) {
        os << ((sp._ao > 0) ? " + " : " - ") << abs(sp._ao) << "i";
    }

    return os;
}