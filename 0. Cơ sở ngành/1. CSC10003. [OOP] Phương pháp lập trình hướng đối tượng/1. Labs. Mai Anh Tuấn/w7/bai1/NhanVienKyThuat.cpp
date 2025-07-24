#include "NhanVienKyThuat.h"
#include <cstring>

NhanVienKyThuat::NhanVienKyThuat() : NhanVien(), _chung_chi_nganh(nullptr), _so_luong_sang_kien(0) {}

NhanVienKyThuat::NhanVienKyThuat(const char* ho_ten, const char* dia_chi, const char* chung_chi, int so_sang_kien)
    : NhanVien(ho_ten, dia_chi), _so_luong_sang_kien(so_sang_kien) {
    _chung_chi_nganh = new char[strlen(chung_chi) + 1];
    strcpy(_chung_chi_nganh, chung_chi);
}

NhanVienKyThuat::NhanVienKyThuat(const NhanVienKyThuat& nv) : NhanVien(nv), _so_luong_sang_kien(nv._so_luong_sang_kien) {
    if (nv._chung_chi_nganh) {
        _chung_chi_nganh = new char[strlen(nv._chung_chi_nganh) + 1];
        strcpy(_chung_chi_nganh, nv._chung_chi_nganh);
    } else {
        _chung_chi_nganh = nullptr;
    }
}

NhanVienKyThuat& NhanVienKyThuat::operator=(const NhanVienKyThuat& nv) {
    if (this != &nv) {
        NhanVien::operator=(nv);
        
        delete[] _chung_chi_nganh;
        
        if (nv._chung_chi_nganh) {
            _chung_chi_nganh = new char[strlen(nv._chung_chi_nganh) + 1];
            strcpy(_chung_chi_nganh, nv._chung_chi_nganh);
        } else {
            _chung_chi_nganh = nullptr;
        }
        
        _so_luong_sang_kien = nv._so_luong_sang_kien;
    }
    return *this;
}

NhanVienKyThuat::~NhanVienKyThuat() {
    delete[] _chung_chi_nganh;
}

const char* NhanVienKyThuat::chungChiNganh() const {
    return _chung_chi_nganh;
}

int NhanVienKyThuat::soLuongSangKien() const {
    return _so_luong_sang_kien;
}

void NhanVienKyThuat::setChungChiNganh(const char* chung_chi) {
    delete[] _chung_chi_nganh;
    _chung_chi_nganh = new char[strlen(chung_chi) + 1];
    strcpy(_chung_chi_nganh, chung_chi);
}

void NhanVienKyThuat::setSoLuongSangKien(int so_sang_kien) {
    _so_luong_sang_kien = so_sang_kien;
}

bool NhanVienKyThuat::isXuatSac() const {
    return _so_luong_sang_kien >= 6;
}

std::istream& operator>>(std::istream& is, NhanVienKyThuat& nv) {
    char ho_ten[100];
    char dia_chi[100];
    char chung_chi[100];
    int so_sang_kien;
    
    // nvkt: Ho Ten (Dia Chi) [Chung Chi] <So Sang Kien>
    // "nvkt: "
    is.ignore(6);
    
    // ...'('
    int i = 0;
    char c;
    while (is.get(c) && c != '(') {
        ho_ten[i++] = c;
    }
    ho_ten[i-1] = '\0'; // khoang trang
    
    // ')'
    i = 0;
    while (is.get(c) && c != ')') {
        dia_chi[i++] = c;
    }
    dia_chi[i] = '\0';
    
    // " ["
    is.ignore(2);
    
    //  ']'
    i = 0;
    while (is.get(c) && c != ']') {
        chung_chi[i++] = c;
    }
    chung_chi[i] = '\0';
    
    // Skip " <"
    is.ignore(2);
    
    // Read so_sang_kien
    is >> so_sang_kien;
    
    // Skip ">"
    is.ignore(1);
    
    nv.setHoTen(ho_ten);
    nv.setDiaChi(dia_chi);
    nv.setChungChiNganh(chung_chi);
    nv.setSoLuongSangKien(so_sang_kien);
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const NhanVienKyThuat& nv) {
    os << "nvkt: " << nv.hoTen() << " (" << nv.diaChi() << ") [" 
       << nv.chungChiNganh() << "] <" << nv.soLuongSangKien() << ">";
    return os;
}