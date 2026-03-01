#include "HinhThangVuong.h"

HinhThangVuong::HinhThangVuong(double dayLon, double dayNho, double chieuCao) 
    : _dayLon(dayLon), _dayNho(dayNho), _chieuCao(chieuCao) {}

double HinhThangVuong::tinhDienTich() const {
    return (_dayLon + _dayNho) * _chieuCao / 2;
}

double HinhThangVuong::tinhChuVi() const {
    double canhBen = sqrt(_chieuCao * _chieuCao + (_dayLon - _dayNho) * (_dayLon - _dayNho));
    return _dayLon + _dayNho + _chieuCao + canhBen;
}

void HinhThangVuong::xuatThongTin(std::ostream& os) const {
    os << "HinhThangVuong: dayLon=" << _dayLon << ", dayNho=" << _dayNho 
       << ", chieuCao=" << _chieuCao
       << ", DienTich=" << tinhDienTich() << ", ChuVi=" << tinhChuVi();
}

const HinhHocPhangType HinhThangVuong::layLoaiHinh() const {
    return HINH_THANG_VUONG;
}

std::istream& operator>>(std::istream& is, HinhThangVuong& htv) {
    char comma1, comma2;
    is >> htv._dayLon >> comma1 >> htv._dayNho >> comma2 >> htv._chieuCao;
    
    if (is.fail() || comma1 != ',' || comma2 != ',') {
        is.clear();
        htv._dayLon = htv._dayNho = htv._chieuCao = 0;
        is.setstate(std::ios_base::failbit);
        return is;
    }
    
    if (htv._dayLon <= htv._dayNho || htv._dayLon <= 0 || htv._dayNho <= 0 || htv._chieuCao <= 0) {
        is.clear();
        htv._dayLon = htv._dayNho = htv._chieuCao = 0;
        is.setstate(std::ios_base::failbit);
    }
    
    return is;
}

HinhThangVuong* HinhThangVuong::createFromStream(std::istream& is) {
    HinhThangVuong* htv = new HinhThangVuong();
    if (is >> *htv) {
        return htv;
    }
    delete htv;
    return nullptr;
}