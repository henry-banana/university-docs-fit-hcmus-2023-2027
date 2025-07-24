#include "HinhTron.h"
#include <cmath>

HinhTron::HinhTron(double bk) : _banKinh(bk) {}

double HinhTron::tinhDienTich() const {
    return PI * _banKinh * _banKinh;
}

double HinhTron::tinhChuVi() const {
    return 2 * PI * _banKinh;
}

void HinhTron::xuatThongTin(std::ostream& os) const {
    os << "HinhTron: banKinh=" << _banKinh
       << ", DienTich=" << tinhDienTich() << ", ChuVi=" << tinhChuVi();
}

const HinhHocPhangType HinhTron::layLoaiHinh() const {
    return HINH_TRON;
}

std::istream& operator>>(std::istream& is, HinhTron& ht) {
    is >> ht._banKinh;
    if (is.fail()) {
        is.clear();
        ht._banKinh = 0;
        is.setstate(std::ios_base::failbit);
    }
    return is;
}

HinhTron* HinhTron::createFromStream(std::istream& is) {
    HinhTron* ht = new HinhTron();
    if (is >> *ht) {
        return ht;
    }
    delete ht;
    return nullptr;
}