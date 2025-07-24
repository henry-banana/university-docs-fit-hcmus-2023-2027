#ifndef HINHCHUNHAT_H
#define HINHCHUNHAT_H

#include "HinhHocPhang.h"

class HinhChuNhat : public HinhHocPhang {
private:
    float _chieuDai, _chieuRong;

public:
    HinhChuNhat();
    HinhChuNhat(const float& cd, const float& cr);
    float TinhDienTich() override; 
};

#endif