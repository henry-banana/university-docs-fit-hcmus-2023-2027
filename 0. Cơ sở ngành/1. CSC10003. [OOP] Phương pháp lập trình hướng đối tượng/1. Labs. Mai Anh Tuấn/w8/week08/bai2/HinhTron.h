#ifndef HINHTRON_H
#define HINHTRON_H
#include "HinhHocPhang.h"

#define PI 3.14159

class HinhTron : public HinhHocPhang {
private:
    float _banKinh;

public:
    HinhTron();
    HinhTron(const float& bk);
    float TinhDienTich() override;
};

#endif