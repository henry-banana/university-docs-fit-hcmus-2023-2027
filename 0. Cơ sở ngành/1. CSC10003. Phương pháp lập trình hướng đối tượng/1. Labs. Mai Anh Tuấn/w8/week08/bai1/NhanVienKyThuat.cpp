#include "NhanVienKyThuat.h"

NhanVienKyThuat::NhanVienKyThuat() : NhanVien() {
    _chungChiNganh = "";
}

NhanVienKyThuat::NhanVienKyThuat(const std::string& ht, const std::string& dc, const std::string& cc) : NhanVien(ht, dc) {
    _chungChiNganh = cc;
}

NhanVienKyThuat::~NhanVienKyThuat() {}

std::ostream& operator<<(std::ostream& os, const NhanVienKyThuat& nvkt) {
    // lam sao de xuat thong tin private o trong class NhanVien?
    // Giai phap la up-cast doi tuong nvkt sang kieu NhanVien de goi operator<< cua lop NhanVien:
    os << static_cast<NhanVien>(nvkt); // Goi operator<< cua lop cha NhanVien
    os << " [" << nvkt._chungChiNganh << "]"; // Xuat them thong tin cua lop con
    return os;
}