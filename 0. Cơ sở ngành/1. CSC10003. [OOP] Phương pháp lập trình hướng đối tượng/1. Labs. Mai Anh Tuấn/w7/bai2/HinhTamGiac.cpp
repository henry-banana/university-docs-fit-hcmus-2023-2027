#include "HinhTamGiac.h"

HinhTamGiac::HinhTamGiac(double a, double b, double c) : _a(a), _b(b), _c(c) {}

double HinhTamGiac::tinhDienTich() const {
    double p = (_a + _b + _c) / 2;
    return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}

double HinhTamGiac::tinhChuVi() const {
    return _a + _b + _c;
}

void HinhTamGiac::xuatThongTin(std::ostream& os) const {
    os << "HinhTamGiac: a=" << _a << ", b=" << _b << ", c=" << _c
       << ", DienTich=" << tinhDienTich() << ", ChuVi=" << tinhChuVi();
}

const HinhHocPhangType HinhTamGiac::layLoaiHinh() const {
    return HINH_TAM_GIAC;
}

std::istream& operator>>(std::istream& is, HinhTamGiac& htg) {
    char comma1, comma2;
    is >> htg._a >> comma1 >> htg._b >> comma2 >> htg._c;
    
    if (is.fail() || comma1 != ',' || comma2 != ',') {
        is.clear();
        htg._a = htg._b = htg._c = 0;
        is.setstate(std::ios_base::failbit);
        return is;
    }
    
    if (htg._a + htg._b <= htg._c || htg._a + htg._c <= htg._b || htg._b + htg._c <= htg._a) {
        is.clear();
        htg._a = htg._b = htg._c = 0;
        is.setstate(std::ios_base::failbit);
    }
    
    return is;
}

HinhTamGiac* HinhTamGiac::createFromStream(std::istream& is) {
    HinhTamGiac* htg = new HinhTamGiac();
    if (is >> *htg) {
        return htg;
    }
    delete htg;
    return nullptr;
}