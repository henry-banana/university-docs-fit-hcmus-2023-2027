#ifndef _IHINHHOCPHANG_H_
#define _IHINHHOCPHANG_H_

#include <iostream>

enum HinhHocPhangType {
    HINH_CHU_NHAT,
    HINH_TRON,
    HINH_TAM_GIAC,
    HINH_THANG_VUONG
};

class IHinhHocPhang {
public:
    virtual ~IHinhHocPhang() {}
    virtual double tinhDienTich() const = 0;
    virtual double tinhChuVi() const = 0;
    virtual void xuatThongTin(std::ostream& os) const = 0; 
    virtual const HinhHocPhangType layLoaiHinh() const = 0;
};

std::ostream& operator<<(std::ostream& os, const IHinhHocPhang& hhp);

using CreateHinhHocPhangFunc = IHinhHocPhang* (*)(std::istream&);

#endif