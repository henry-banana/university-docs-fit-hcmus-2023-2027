#include "NhanVien.h"

NhanVien::NhanVien() {
    _hoTen = "";
    _diaChi = "";
}

NhanVien::NhanVien(const std::string& ht, const std::string& dc) {
    _hoTen = ht;
    _diaChi = dc;
}

NhanVien::~NhanVien() {}

std::ostream& operator<<(std::ostream& os, const NhanVien& nv) {
    os << nv._hoTen << " (" << nv._diaChi << ")";
    return os;
}