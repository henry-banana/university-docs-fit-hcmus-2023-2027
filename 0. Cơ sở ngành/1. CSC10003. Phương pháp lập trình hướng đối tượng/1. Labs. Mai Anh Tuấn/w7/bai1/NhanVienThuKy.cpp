#include "NhanVienThuKy.h"
#include <cstring>

NhanVienThuKy::NhanVienThuKy() : NhanVien(), _chung_chi_ngoai_ngu(nullptr), _so_luong_bao_cao(0) {}

NhanVienThuKy::NhanVienThuKy(const char* ho_ten, const char* dia_chi, const char* chung_chi, int so_bao_cao)
    : NhanVien(ho_ten, dia_chi), _so_luong_bao_cao(so_bao_cao) {
    _chung_chi_ngoai_ngu = new char[strlen(chung_chi) + 1];
    strcpy(_chung_chi_ngoai_ngu, chung_chi);
}

NhanVienThuKy::NhanVienThuKy(const NhanVienThuKy& nv) : NhanVien(nv), _so_luong_bao_cao(nv._so_luong_bao_cao) {
    if (nv._chung_chi_ngoai_ngu) {
        _chung_chi_ngoai_ngu = new char[strlen(nv._chung_chi_ngoai_ngu) + 1];
        strcpy(_chung_chi_ngoai_ngu, nv._chung_chi_ngoai_ngu);
    } else {
        _chung_chi_ngoai_ngu = nullptr;
    }
}

NhanVienThuKy& NhanVienThuKy::operator=(const NhanVienThuKy& nv) {
    if (this != &nv) {
        NhanVien::operator=(nv);
        
        delete[] _chung_chi_ngoai_ngu;
        
        if (nv._chung_chi_ngoai_ngu) {
            _chung_chi_ngoai_ngu = new char[strlen(nv._chung_chi_ngoai_ngu) + 1];
            strcpy(_chung_chi_ngoai_ngu, nv._chung_chi_ngoai_ngu);
        } else {
            _chung_chi_ngoai_ngu = nullptr;
        }
        
        _so_luong_bao_cao = nv._so_luong_bao_cao;
    }
    return *this;
}

NhanVienThuKy::~NhanVienThuKy() {
    delete[] _chung_chi_ngoai_ngu;
}

const char* NhanVienThuKy::chungChiNgoaiNgu() const {
    return _chung_chi_ngoai_ngu;
}

int NhanVienThuKy::soLuongBaoCao() const {
    return _so_luong_bao_cao;
}
void NhanVienThuKy::setChungChiNgoaiNgu(const char* chung_chi) {
    delete[] _chung_chi_ngoai_ngu;
    _chung_chi_ngoai_ngu = new char[strlen(chung_chi) + 1];
    strcpy(_chung_chi_ngoai_ngu, chung_chi);
}

void NhanVienThuKy::setSoLuongBaoCao(int so_bao_cao) {
    _so_luong_bao_cao = so_bao_cao;
}

bool NhanVienThuKy::isXuatSac() const {
    return _so_luong_bao_cao >= 12;
}

std::istream& operator>>(std::istream& is, NhanVienThuKy& nv) {
    char ho_ten[100];
    char dia_chi[100];
    char chung_chi[100];
    int so_bao_cao;
    
    // Format: nvtk: Ho Ten (Dia Chi) [Chung Chi] <So Bao Cao>
    // Skip "nvtk: "
    is.ignore(6);
    
    // Read ho_ten until '('
    int i = 0;
    char c;
    while (is.get(c) && c != '(') {
        ho_ten[i++] = c;
    }
    ho_ten[i-1] = '\0'; // Remove space before '('
    
    // Read dia_chi until ')'
    i = 0;
    while (is.get(c) && c != ')') {
        dia_chi[i++] = c;
    }
    dia_chi[i] = '\0';
    
    // Skip " ["
    is.ignore(2);
    
    // Read chung_chi until ']'
    i = 0;
    while (is.get(c) && c != ']') {
        chung_chi[i++] = c;
    }
    chung_chi[i] = '\0';
    
    // Skip " <"
    is.ignore(2);
    
    // Read so_bao_cao
    is >> so_bao_cao;
    
    // Skip ">"
    is.ignore(1);
    
    nv.setHoTen(ho_ten);
    nv.setDiaChi(dia_chi);
    nv.setChungChiNgoaiNgu(chung_chi);
    nv.setSoLuongBaoCao(so_bao_cao);
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const NhanVienThuKy& nv) {
    os << "nvtk: " << nv.hoTen() << " (" << nv.diaChi() << ") [" 
       << nv.chungChiNgoaiNgu() << "] <" << nv.soLuongBaoCao() << ">";
    return os;
}