#ifndef _NHANVIEN_H_
#define _NHANVIEN_H_

#include "INhanVien.h"

class NhanVien : public INhanVien {
private:
    char* _ho_ten;
    char* _dia_chi;
public:
    NhanVien();
    NhanVien(const char* ho_ten, const char* dia_chi);
    NhanVien(const NhanVien& nv);
    NhanVien& operator=(const NhanVien& nv);
    ~NhanVien();

    const char* hoTen() const override;
    const char* diaChi() const override;

    void setHoTen(const char* ho_ten);
    void setDiaChi(const char* dia_chi);
};

#endif