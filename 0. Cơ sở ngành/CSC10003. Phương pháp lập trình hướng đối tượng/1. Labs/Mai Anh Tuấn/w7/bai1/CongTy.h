#ifndef _CONGTY_H_
#define _CONGTY_H_

#include "NhanVien.h"
#include "NhanVienThuKy.h"
#include "NhanVienKyThuat.h"
#include <iostream>

class CongTy {
private:
    INhanVien** _danh_sach_nhan_vien;
    int _so_luong_nhan_vien;
    int _suc_chua;
public:
    static const int _INITIAL_SIZE;
    static const int _STEP;

    CongTy();
    CongTy(const CongTy& other);
    CongTy& operator=(const CongTy& other);
    ~CongTy();
    
    INhanVien* createNhanVien(const char* line);

    void themNhanVien(INhanVien* nv);
    void xuatDanhSachNhanVien(std::ostream& os) const;
    void xuatDanhSachNhanVienXuatSac(std::ostream& os) const;
    
    bool docDuLieu(const char* filename);
    bool ghiDuLieu(const char* filename) const;
    
    friend std::istream& operator>>(std::istream& is, CongTy& ct);
    friend std::ostream& operator<<(std::ostream& os, const CongTy& ct);
};

#endif