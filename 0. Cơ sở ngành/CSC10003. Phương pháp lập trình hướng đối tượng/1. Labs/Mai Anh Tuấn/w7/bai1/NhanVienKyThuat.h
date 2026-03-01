#ifndef _NHANVIENKYTHUAT_H_
#define _NHANVIENKYTHUAT_H_

#include "NhanVien.h"
#include <iostream>

class NhanVienKyThuat : public NhanVien {
private:
    char* _chung_chi_nganh;
    int _so_luong_sang_kien;
public:
    NhanVienKyThuat();
    NhanVienKyThuat(const char* ho_ten, const char* dia_chi, const char* chung_chi, int so_sang_kien);
    NhanVienKyThuat(const NhanVienKyThuat& nv);
    NhanVienKyThuat& operator=(const NhanVienKyThuat& nv);
    ~NhanVienKyThuat();

    const char* chungChiNganh() const;
    int soLuongSangKien() const;

    void setChungChiNganh(const char* chung_chi);
    void setSoLuongSangKien(int so_sang_kien);
    
    bool isXuatSac() const override;

    friend std::istream& operator>>(std::istream& is, NhanVienKyThuat& nv);
    friend std::ostream& operator<<(std::ostream& os, const NhanVienKyThuat& nv);
};

#endif