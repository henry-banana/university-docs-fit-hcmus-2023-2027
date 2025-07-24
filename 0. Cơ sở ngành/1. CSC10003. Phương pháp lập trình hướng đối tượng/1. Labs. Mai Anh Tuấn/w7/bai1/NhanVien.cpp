#include "NhanVien.h"
#include <cstring>
#include <iostream>

INhanVien::~INhanVien() {}

NhanVien::NhanVien() : _ho_ten(nullptr), _dia_chi(nullptr) {}

NhanVien::NhanVien(const char* ho_ten, const char* dia_chi) {
    _ho_ten = new char[strlen(ho_ten) + 1];
    strcpy(_ho_ten, ho_ten);
    
    _dia_chi = new char[strlen(dia_chi) + 1];
    strcpy(_dia_chi, dia_chi);
}

NhanVien::NhanVien(const NhanVien& nv) {
    if (nv._ho_ten) {
        _ho_ten = new char[strlen(nv._ho_ten) + 1];
        strcpy(_ho_ten, nv._ho_ten);
    } else {
        _ho_ten = nullptr;
    }
    
    if (nv._dia_chi) {
        _dia_chi = new char[strlen(nv._dia_chi) + 1];
        strcpy(_dia_chi, nv._dia_chi);
    } else {
        _dia_chi = nullptr;
    }
}

NhanVien& NhanVien::operator=(const NhanVien& nv) {
    if (this != &nv) {
        delete[] _ho_ten;
        delete[] _dia_chi;
        
        if (nv._ho_ten) {
            _ho_ten = new char[strlen(nv._ho_ten) + 1];
            strcpy(_ho_ten, nv._ho_ten);
        } else {
            _ho_ten = nullptr;
        }
        
        if (nv._dia_chi) {
            _dia_chi = new char[strlen(nv._dia_chi) + 1];
            strcpy(_dia_chi, nv._dia_chi);
        } else {
            _dia_chi = nullptr;
        }
    }
    return *this;
}

NhanVien::~NhanVien() {
    delete[] _ho_ten;
    delete[] _dia_chi;
}

const char* NhanVien::hoTen() const {
    return _ho_ten;
}

const char* NhanVien::diaChi() const {
    return _dia_chi;
}

void NhanVien::setHoTen(const char* ho_ten) {
    delete[] _ho_ten;
    _ho_ten = new char[strlen(ho_ten) + 1];
    strcpy(_ho_ten, ho_ten);
}

void NhanVien::setDiaChi(const char* dia_chi) {
    delete[] _dia_chi;
    _dia_chi = new char[strlen(dia_chi) + 1];
    strcpy(_dia_chi, dia_chi);
}