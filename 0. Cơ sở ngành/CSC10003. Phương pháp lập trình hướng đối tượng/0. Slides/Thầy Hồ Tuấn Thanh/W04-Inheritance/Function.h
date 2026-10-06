#ifndef _FUNC_
#define _FUNC_
#include<string>
#include<iostream>
using namespace std;
// base class
// parent class
// super class
class NhanVien{
protected:
    string Ma;
    string HoTen, DiaChi;
    int Luong;
public:
    void Nhap();
    long long TinhLuong();
};

// derived class
// child class
// sub class
class NVSanXuat: public NhanVien{
protected:
    int SoSP;
public:
    // override
    void Nhap();
    long long TinhLuong();
};

class NVCongNhat: public NhanVien{
protected:
    int SoNgayDiLam;    
public:
    // override
    void Nhap();
    long long TinhLuong();
};

#endif