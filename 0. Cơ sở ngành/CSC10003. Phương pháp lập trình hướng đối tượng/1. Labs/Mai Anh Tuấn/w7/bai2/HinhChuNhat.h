#ifndef _HINHCHUNHAT_H_
#define _HINHCHUNHAT_H_

#include "IHinhHocPhang.h"

class HinhChuNhat : public IHinhHocPhang {
private:
    double _chieuDai;
    double _chieuRong;

public:
    HinhChuNhat(double dai = 0, double rong = 0);

    double tinhDienTich() const override;
    double tinhChuVi() const override;
    void xuatThongTin(std::ostream& os) const override;
    const HinhHocPhangType layLoaiHinh() const override;

    static HinhChuNhat* createFromStream(std::istream& is);
    friend std::istream& operator>>(std::istream& is, HinhChuNhat& hcn);
};

#endif