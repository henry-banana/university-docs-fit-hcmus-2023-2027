#include "HinhChuNhat.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os, const IHinhHocPhang& hhp) {
    hhp.xuatThongTin(os);
    return os;
}

HinhChuNhat::HinhChuNhat(double dai, double rong) : _chieuDai(dai), _chieuRong(rong) {}

double HinhChuNhat::tinhDienTich() const {
    return _chieuDai * _chieuRong;
}

double HinhChuNhat::tinhChuVi() const {
    return 2 * (_chieuDai + _chieuRong);
}

void HinhChuNhat::xuatThongTin(std::ostream& os) const {
    os << "HinhChuNhat: chieuDai=" << _chieuDai << ", chieuRong=" << _chieuRong
       << ", DienTich=" << tinhDienTich() << ", ChuVi=" << tinhChuVi();
}

const HinhHocPhangType HinhChuNhat::layLoaiHinh() const {
    return HINH_CHU_NHAT;
}

std::istream& operator>>(std::istream& is, HinhChuNhat& hcn) {
    char comma;
    is >> hcn._chieuDai >> comma >> hcn._chieuRong;
    if (is.fail() || comma != ',') {
        is.clear();
        hcn._chieuDai = 0;
        hcn._chieuRong = 0;
        is.setstate(std::ios_base::failbit);
    }
    return is;
}

HinhChuNhat* HinhChuNhat::createFromStream(std::istream& is) {
    HinhChuNhat* hcn = new HinhChuNhat();
    if (is >> *hcn) {
        return hcn;
    }
    delete hcn;
    return nullptr;
}