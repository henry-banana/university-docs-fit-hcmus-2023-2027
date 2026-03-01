#ifndef _QUANLYHINHHOCPHANG_H_
#define _QUANLYHINHHOCPHANG_H_

#include "IHinhHocPhang.h"
#include <iostream>

struct HinhHocPhangFactoryEntry {
    const char* tag;
    CreateHinhHocPhangFunc creator;
};

static IHinhHocPhang* createHinhChuNhatWrapper(std::istream& is);
static IHinhHocPhang* createHinhTronWrapper(std::istream& is);

class QuanLyHinhHocPhang {
private:
    IHinhHocPhang** _danhSachHinh;
    int _soLuongHinh;
    int _sucChua;

    static const int _INITIAL_CAPACITY = 10;
    static const int _CAPACITY_STEP = 5;

    void moRongDanhSach();

public:
    QuanLyHinhHocPhang();
    ~QuanLyHinhHocPhang();
    QuanLyHinhHocPhang(const QuanLyHinhHocPhang&) = delete;
    QuanLyHinhHocPhang& operator=(const QuanLyHinhHocPhang&) = delete;

    void themHinh(IHinhHocPhang* hinh);
    bool docTuFile(const char* tenFile);
    void xuatThongKe(std::ostream& os) const;

    friend std::istream& operator>>(std::istream& is, QuanLyHinhHocPhang& ql);
    friend std::ostream& operator<<(std::ostream& os, const QuanLyHinhHocPhang& ql);
};

#endif