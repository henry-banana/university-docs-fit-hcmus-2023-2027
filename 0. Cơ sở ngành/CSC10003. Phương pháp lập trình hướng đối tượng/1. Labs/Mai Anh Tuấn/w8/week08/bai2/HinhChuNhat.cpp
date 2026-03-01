#include "HinhChuNhat.h"
#include <cmath> // For abs
#include <iostream> // For std::cout

HinhChuNhat::HinhChuNhat() : _chieuDai(0), _chieuRong(0) {} 

HinhChuNhat::HinhChuNhat(const float& cd, const float& cr) 
    : _chieuDai(((cd == 0) ? 1 : fabs(cd))), _chieuRong((cr == 0) ? 1 : fabs(cr)) {}

float HinhChuNhat::TinhDienTich() {
    return _chieuDai * _chieuRong;
}