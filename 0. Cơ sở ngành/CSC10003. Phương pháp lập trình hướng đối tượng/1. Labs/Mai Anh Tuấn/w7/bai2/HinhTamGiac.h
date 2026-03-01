#ifndef _HINHTAMGIAC_H_
#define _HINHTAMGIAC_H_

#include "IHinhHocPhang.h"
#include <cmath>

class HinhTamGiac : public IHinhHocPhang {
private:
    double _a;
    double _b;
    double _c;

public:
    HinhTamGiac(double a = 0, double b = 0, double c = 0);

    double tinhDienTich() const override;
    double tinhChuVi() const override;
    void xuatThongTin(std::ostream& os) const override;
    const HinhHocPhangType layLoaiHinh() const override;

    static HinhTamGiac* createFromStream(std::istream& is);
    friend std::istream& operator>>(std::istream& is, HinhTamGiac& htg);
};

#endif