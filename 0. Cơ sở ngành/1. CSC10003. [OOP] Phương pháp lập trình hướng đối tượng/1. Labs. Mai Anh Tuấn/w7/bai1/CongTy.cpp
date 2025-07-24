#include "CongTy.h"
#include <fstream>
#include <cstring>

const int CongTy::_INITIAL_SIZE = 5;
const int CongTy::_STEP = 3;

CongTy::CongTy() : _so_luong_nhan_vien(0), _suc_chua(_INITIAL_SIZE) {
    _danh_sach_nhan_vien = new INhanVien*[_suc_chua];
    for (int i = 0; i < _suc_chua; i++) {
        _danh_sach_nhan_vien[i] = nullptr;
    }
}

CongTy::CongTy(const CongTy& other) : _so_luong_nhan_vien(other._so_luong_nhan_vien), _suc_chua(other._suc_chua) {
    _danh_sach_nhan_vien = new INhanVien*[_suc_chua];

    for (int i = 0; i < _suc_chua; ++i) {
        _danh_sach_nhan_vien[i] = nullptr;
    }
    
    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        INhanVien* nv = other._danh_sach_nhan_vien[i];
        
        NhanVienThuKy* nvtk = dynamic_cast<NhanVienThuKy*>(nv);
        if (nvtk) {
            _danh_sach_nhan_vien[i] = new NhanVienThuKy(*nvtk);
            continue;
        }
        
        NhanVienKyThuat* nvkt = dynamic_cast<NhanVienKyThuat*>(nv);
        if (nvkt) {
            _danh_sach_nhan_vien[i] = new NhanVienKyThuat(*nvkt);
            continue;
        }
    }
}

CongTy& CongTy::operator=(const CongTy& other) {
    if (this != &other) {
        for (int i = 0; i < _so_luong_nhan_vien; i++) {
            delete _danh_sach_nhan_vien[i];
        }
        delete[] _danh_sach_nhan_vien;
        
        _so_luong_nhan_vien = other._so_luong_nhan_vien;
        _suc_chua = other._suc_chua;
        
        _danh_sach_nhan_vien = new INhanVien*[_suc_chua];

        for (int i = 0; i < _suc_chua; ++i) {
            _danh_sach_nhan_vien[i] = nullptr;
        }
        
        for (int i = 0; i < _so_luong_nhan_vien; i++) {
            INhanVien* nv = other._danh_sach_nhan_vien[i];
            
            NhanVienThuKy* nvtk = dynamic_cast<NhanVienThuKy*>(nv);
            if (nvtk) {
                _danh_sach_nhan_vien[i] = new NhanVienThuKy(*nvtk);
                continue;
            }
            
            NhanVienKyThuat* nvkt = dynamic_cast<NhanVienKyThuat*>(nv);
            if (nvkt) {
                _danh_sach_nhan_vien[i] = new NhanVienKyThuat(*nvkt);
                continue;
            }
        }
    }
    return *this;
}

CongTy::~CongTy() {
    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        delete _danh_sach_nhan_vien[i];
    }
    delete[] _danh_sach_nhan_vien;
}

void CongTy::themNhanVien(INhanVien* nv) {
    if (!nv) return;

    if (_so_luong_nhan_vien >= _suc_chua) {
        int new_suc_chua = _suc_chua + _STEP;
        INhanVien** new_danh_sach = new INhanVien*[new_suc_chua];

        for (int i = 0; i < _so_luong_nhan_vien; i++) {
            new_danh_sach[i] = _danh_sach_nhan_vien[i];
        }

        for (int i = _so_luong_nhan_vien; i < new_suc_chua; ++i) {
            new_danh_sach[i] = nullptr;
        }

        delete[] _danh_sach_nhan_vien;
        _danh_sach_nhan_vien = new_danh_sach;
        _suc_chua = new_suc_chua;
    } 
    
    _danh_sach_nhan_vien[_so_luong_nhan_vien++] = nv;
}

void CongTy::xuatDanhSachNhanVien(std::ostream& os) const {
    os << "Danh sach nhan vien cong ty:\n";

    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        INhanVien* nv = _danh_sach_nhan_vien[i];

        if (!nv) continue;
        
        NhanVienThuKy* nvtk = dynamic_cast<NhanVienThuKy*>(nv);
        if (nvtk) {
            os << *nvtk << "\n";
            continue;
        }
        
        NhanVienKyThuat* nvkt = dynamic_cast<NhanVienKyThuat*>(nv);
        if (nvkt) {
            os << *nvkt << "\n";
            continue;
        }
    }
}

void CongTy::xuatDanhSachNhanVienXuatSac(std::ostream& os) const {
    os << "Danh sach nhan vien xuat sac:\n";

    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        INhanVien* nv = _danh_sach_nhan_vien[i];

        if (!nv) continue;
        
        if (nv->isXuatSac()) {
            NhanVienThuKy* nvtk = dynamic_cast<NhanVienThuKy*>(nv);
            if (nvtk) {
                os << *nvtk << "\n";
                continue;
            }
            
            NhanVienKyThuat* nvkt = dynamic_cast<NhanVienKyThuat*>(nv);
            if (nvkt) {
                os << *nvkt << "\n";
                continue;
            }
        }
    }
}

bool CongTy::docDuLieu(const char* filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        return false;
    }
    
    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        delete _danh_sach_nhan_vien[i];
        _danh_sach_nhan_vien[i] = nullptr;
    }
    _so_luong_nhan_vien = 0;
    
    ifs >> *this;

    bool status = ifs.eof() || ifs.good();

    ifs.close();

    return status;
}

bool CongTy::ghiDuLieu(const char* filename) const {
    std::ofstream ofs(filename);
    if (!ofs) {
        return false;
    }
    
    for (int i = 0; i < _so_luong_nhan_vien; i++) {
        INhanVien* nv = _danh_sach_nhan_vien[i];

        if (!nv) continue;
        
        NhanVienThuKy* nvtk = dynamic_cast<NhanVienThuKy*>(nv);
        if (nvtk) {
            ofs << *nvtk << "\n";
            continue;
        }
        
        NhanVienKyThuat* nvkt = dynamic_cast<NhanVienKyThuat*>(nv);
        if (nvkt) {
            ofs << *nvkt << "\n";
            continue;
        }
    }
    
    bool status = ofs.good();
    ofs.close();
    return status;
}

std::istream& operator>>(std::istream& is, CongTy& ct) {
    char tag_buffer[6];

    while (is.good() && !is.eof()) {
        char peek_char = is.peek();
        while (peek_char != EOF && (peek_char == ' ' || peek_char == '\t' || peek_char == '\n' || peek_char == '\r')) {
            is.ignore();
            peek_char = is.peek();
        }

        if (is.eof() || !is.good()) break;

        for (int i = 0; i < 5; ++i) {
            if (!is.get(tag_buffer[i])) {
                tag_buffer[i] = '\0';
                goto end_reading_loop;
            }
        }
        tag_buffer[5] = '\0';

        INhanVien* new_nv = nullptr;

        if (strcmp(tag_buffer, "nvkt:") == 0) {
            if (is.peek() == ' ') {
                is.ignore();
            }

            NhanVienKyThuat* nvkt = new NhanVienKyThuat();
            if (is >> *nvkt) {
                new_nv = nvkt;
            } else {
                delete nvkt;
                is.clear();
            }
        } else if (strcmp(tag_buffer, "nvtk:") == 0) {
            if (is.peek() == ' ') { 
                is.ignore();
            }

            NhanVienThuKy* nvtk = new NhanVienThuKy();
            if (is >> *nvtk) {
                new_nv = nvtk;
            } else {
                delete nvtk;
                is.clear();
            }
        }

        if (new_nv) {
            ct.themNhanVien(new_nv);
        }

        if (!is.eof() && is.fail()) {
             is.clear();
        }
    }

end_reading_loop:;
    return is;
}

std::ostream& operator<<(std::ostream& os, const CongTy& ct) {
    ct.xuatDanhSachNhanVien(os);
    return os;
}