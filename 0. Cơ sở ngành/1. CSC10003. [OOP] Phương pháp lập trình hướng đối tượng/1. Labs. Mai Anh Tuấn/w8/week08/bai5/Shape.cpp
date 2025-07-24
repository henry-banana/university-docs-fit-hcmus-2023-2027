#include "Shape.h"
#include <cmath>

// --- HinhTron ---
double HinhTron::tinhChuVi() const {
    return 2 * M_PI * banKinh;
}

double HinhTron::tinhDienTich() const {
    return M_PI * banKinh * banKinh;
}

std::string HinhTron::getTenHinh() const {
    return "Hinh Tron";
}

HinhTron::HinhTron(double r) : banKinh(r) {
    if (r < 0) throw std::invalid_argument("Ban kinh khong duoc am.");
}
// --- HinhTamGiacDeu ---

std::string HinhTamGiacDeu::getTenHinh() const {
    return "Hinh Tam Giac Deu";
}

double HinhTamGiacDeu::tinhChuVi() const {
    return 3 * canh;
}

double HinhTamGiacDeu::tinhDienTich() const {
    return (std::sqrt(3) / 4.0) * canh * canh;
}

HinhTamGiacDeu::HinhTamGiacDeu(double c) : canh(c) {
    if (c < 0) throw std::invalid_argument("Canh khong duoc am.");
}

// --- HinhChuNhat ---
double HinhChuNhat::tinhChuVi() const {
    return 2 * (chieuDai + chieuRong);
}

double HinhChuNhat::tinhDienTich() const {
    return chieuDai * chieuRong;
}

std::string HinhChuNhat::getTenHinh() const {
    return "Hinh Chu Nhat";
}

HinhChuNhat::HinhChuNhat(double d, double r) : chieuDai(d), chieuRong(r) {
    if (d < 0 || r < 0) throw std::invalid_argument("Chieu dai va chieu rong khong duoc am.");
}

// HinhVuong
std::string HinhVuong::getTenHinh() const {
    return "Hinh Vuong";
}

HinhVuong::HinhVuong(double c) : canh(c) {
    if (c < 0) throw std::invalid_argument("Canh khong duoc am.");
}

double HinhVuong::tinhChuVi() const {
    return 4 * canh;
}

double HinhVuong::tinhDienTich() const {
    return canh * canh;
}

// --- HinhCau ---
double HinhCau::tinhDienTichXungQuanh() const { // Coi là diện tích bề mặt
    return 4 * M_PI * banKinh * banKinh;
}

double HinhCau::tinhTheTich() const {
    return (4.0/3.0) * M_PI * std::pow(banKinh, 3);
}

std::string HinhCau::getTenHinh() const {
    return "Hinh Cau";
}

HinhCau::HinhCau(double r) : banKinh(r) {
    if (r < 0) throw std::invalid_argument("Ban kinh khong duoc am.");
}

// --- HinhHop ---
double HinhHop::tinhDienTichXungQuanh() const {
    return 2 * chieuCao * (chieuDai + chieuRong);
}

double HinhHop::tinhTheTich() const {
    return chieuDai * chieuRong * chieuCao;
}

std::string HinhHop::getTenHinh() const {
    return "Hinh Hop";
}

HinhHop::HinhHop(double d, double r, double c) : chieuDai(d), chieuRong(r), chieuCao(c) {
    if (d < 0 || r < 0 || c < 0) throw std::invalid_argument("Chieu dai, chieu rong va chieu cao khong duoc am.");
}

// HinhLapPhuong 

std::string HinhLapPhuong::getTenHinh() const {
    return "Hinh Lap Phuong";
}

HinhLapPhuong::HinhLapPhuong(double c) : canh(c) {
    if (c < 0) throw std::invalid_argument("Canh khong duoc am.");
}

double HinhLapPhuong::tinhDienTichXungQuanh() const {
    return 4 * canh * canh;
}

double HinhLapPhuong::tinhTheTich() const {
    return canh * canh * canh;
}

// --- HinhTru ---
double HinhTru::tinhDienTichXungQuanh() const {
    return 2 * M_PI * banKinhDay * chieuCao;
}

double HinhTru::tinhTheTich() const {
    return M_PI * banKinhDay * banKinhDay * chieuCao;
}

std::string HinhTru::getTenHinh() const {
    return "Hinh Tru";
}

HinhTru::HinhTru(double r, double h) : banKinhDay(r), chieuCao(h) {
    if (r < 0 || h < 0) throw std::invalid_argument("Ban kinh day va chieu cao khong duoc am.");
}

// --- HinhNon ---
double HinhNon::tinhDienTichXungQuanh() const {
    double duongSinh = std::sqrt(banKinhDay * banKinhDay + chieuCao * chieuCao);
    return M_PI * banKinhDay * duongSinh;
}

double HinhNon::tinhTheTich() const {
    return (1.0/3.0) * M_PI * banKinhDay * banKinhDay * chieuCao;
}

std::string HinhNon::getTenHinh() const {
    return "Hinh Non";
}

HinhNon::HinhNon(double r, double h) : banKinhDay(r), chieuCao(h) {
    if (r < 0 || h < 0) throw std::invalid_argument("Ban kinh day va chieu cao khong duoc am.");
}