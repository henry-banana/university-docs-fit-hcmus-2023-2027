#include "Hinh.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Hinh2D::xuatThongTin(std::ostream& os) const {
    os << std::fixed << std::setprecision(2); 
    os << getTenHinh() << " [P = " << tinhChuVi()
        << ", S = " << tinhDienTich() << "]";
}

void Hinh3D::xuatThongTin(std::ostream& os) const {
    os << std::fixed << std::setprecision(2); 
    os << getTenHinh() << " [Sxq = " << tinhDienTichXungQuanh()
        << ", V = " << tinhTheTich() << "]";
}

std::ostream& operator<<(std::ostream& os, const Hinh& h) {
    h.xuatThongTin(os);
    return os;
}