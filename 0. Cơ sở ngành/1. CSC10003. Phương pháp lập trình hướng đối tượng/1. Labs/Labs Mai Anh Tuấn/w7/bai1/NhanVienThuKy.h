#ifndef _NHANVIENTHULY_H_
#define _NHANVIENTHULY_H_

#include "NhanVien.h"
#include <iostream>

class NhanVienThuKy : public NhanVien {
private:
    char* _chung_chi_ngoai_ngu;
    int _so_luong_bao_cao;
public:
    NhanVienThuKy();
    NhanVienThuKy(const char* ho_ten, const char* dia_chi, const char* chung_chi, int so_bao_cao);
    NhanVienThuKy(const NhanVienThuKy& nv);
    NhanVienThuKy& operator=(const NhanVienThuKy& nv);
    ~NhanVienThuKy();

    const char* chungChiNgoaiNgu() const;
    int soLuongBaoCao() const;
    
    void setChungChiNgoaiNgu(const char* chung_chi);
    void setSoLuongBaoCao(int so_bao_cao);
    
    bool isXuatSac() const override;

    friend std::istream& operator>>(std::istream& is, NhanVienThuKy& nv);
    friend std::ostream& operator<<(std::ostream& os, const NhanVienThuKy& nv);
};

#endif