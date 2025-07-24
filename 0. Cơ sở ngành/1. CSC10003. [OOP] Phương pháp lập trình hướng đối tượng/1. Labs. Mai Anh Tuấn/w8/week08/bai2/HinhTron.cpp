#include "HinhTron.h"
#include <cmath>

HinhTron::HinhTron() : _banKinh(0) {}

HinhTron::HinhTron(const float& bk) 
    : _banKinh((bk == 0) ? 1 : abs(bk)) {}

float HinhTron::TinhDienTich() {
    return PI * _banKinh * _banKinh;
}