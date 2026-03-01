#ifndef _HINHTHANGVUONG_H_
#define _HINHTHANGVUONG_H_

#include "IHinhHocPhang.h"
#include <cmath>

class HinhThangVuong : public IHinhHocPhang {
private:
    double _dayLon;    
    double _dayNho;    
    double _chieuCao;   

public:
    HinhThangVuong(double dayLon = 0, double dayNho = 0, double chieuCao = 0);

    double tinhDienTich() const override;
    double tinhChuVi() const override;
    void xuatThongTin(std::ostream& os) const override;
    const HinhHocPhangType layLoaiHinh() const override;

    static HinhThangVuong* createFromStream(std::istream& is);
    friend std::istream& operator>>(std::istream& is, HinhThangVuong& htv);
};

#endif