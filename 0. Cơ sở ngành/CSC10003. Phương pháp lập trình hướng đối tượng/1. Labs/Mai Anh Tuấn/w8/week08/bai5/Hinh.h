#ifndef HINH_H
#define HINH_H

#include <string>

#ifndef M_PI 
#define M_PI 3.14159265358979323846
#endif

class Hinh {
public:
    virtual ~Hinh() = default; 

    virtual std::string getTenHinh() const = 0;
    virtual void xuatThongTin(std::ostream& os) const = 0;

};

std::ostream& operator<<(std::ostream& os, const Hinh& h);

class Hinh2D : public Hinh {
public:
    virtual double tinhChuVi() const = 0;
    virtual double tinhDienTich() const = 0;

    void xuatThongTin(std::ostream& os) const override;
};

class Hinh3D : public Hinh {
public:
    virtual double tinhDienTichXungQuanh() const = 0;
    virtual double tinhTheTich() const = 0;

    void xuatThongTin(std::ostream& os) const override;
};

#endif // HINH_H