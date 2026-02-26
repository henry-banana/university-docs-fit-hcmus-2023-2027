#ifndef SHAPES_H
#define SHAPES_H

#include "Hinh.h"
#include <stdexcept>

// --- Các hình 2D ---

class HinhTron : public Hinh2D {
private:
    double banKinh;
public:
    HinhTron(double r);
    std::string getTenHinh() const override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
};

class HinhTamGiacDeu : public Hinh2D {
private:
    double canh;
public:
    HinhTamGiacDeu(double c);
    std::string getTenHinh() const override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
};

class HinhChuNhat : public Hinh2D {
protected:
    double chieuDai;
    double chieuRong;
public:
    HinhChuNhat(double d, double r);
    std::string getTenHinh() const override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
};

class HinhVuong : public Hinh2D {
private:
    double canh;
public:
    HinhVuong(double c);
    std::string getTenHinh() const override;
    double tinhChuVi() const override;
    double tinhDienTich() const override;
};


// --- Các hình 3D ---

class HinhCau : public Hinh3D {
private:
    double banKinh;
public:
    HinhCau(double r);
    std::string getTenHinh() const override;
    double tinhDienTichXungQuanh() const override; 
    double tinhTheTich() const override;
};

class HinhHop : public Hinh3D {
protected: 
    double chieuDai;
    double chieuRong;
    double chieuCao;
public:
    HinhHop(double d, double r, double c);
    std::string getTenHinh() const override;
    double tinhDienTichXungQuanh() const override;
    double tinhTheTich() const override;
};

class HinhLapPhuong : public Hinh3D {
private:
    double canh;
public:
    HinhLapPhuong(double c);
    std::string getTenHinh() const override;
    double tinhDienTichXungQuanh() const override;
    double tinhTheTich() const override;
};

class HinhTru : public Hinh3D {
private:
    double banKinhDay;
    double chieuCao;
public:
    HinhTru(double r, double h);
    std::string getTenHinh() const override;
    double tinhDienTichXungQuanh() const override;
    double tinhTheTich() const override;
};

class HinhNon : public Hinh3D {
private:
    double banKinhDay;
    double chieuCao;
public:
    HinhNon(double r, double h);
    std::string getTenHinh() const override;
    double tinhDienTichXungQuanh() const override;
    double tinhTheTich() const override;
};


#endif // SHAPES_H