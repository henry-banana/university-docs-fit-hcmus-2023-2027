#ifndef _HINHTRON_H_
#define _HINHTRON_H_

#include "IHinhHocPhang.h"

const double PI = 3.1415926535;

class HinhTron : public IHinhHocPhang {
private:
    double _banKinh;

public:
    HinhTron(double bk = 0);

    double tinhDienTich() const override;
    double tinhChuVi() const override;
    void xuatThongTin(std::ostream& os) const override;
    const HinhHocPhangType layLoaiHinh() const override;

    static HinhTron* createFromStream(std::istream& is);
    friend std::istream& operator>>(std::istream& is, HinhTron& ht);
};

#endif