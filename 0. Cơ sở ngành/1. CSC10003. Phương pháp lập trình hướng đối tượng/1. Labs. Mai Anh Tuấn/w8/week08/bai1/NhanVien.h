#ifndef _NHANVIEN_H_
#define _NHANVIEN_H_

#include <string>
#include <iostream>

class NhanVien {
private:
    std::string _hoTen, _diaChi;
public:
    NhanVien();
    NhanVien(const std::string& ht, const std::string& dc);
    ~NhanVien();

    friend std::ostream& operator<<(std::ostream& os, const NhanVien& nv);
};

#endif