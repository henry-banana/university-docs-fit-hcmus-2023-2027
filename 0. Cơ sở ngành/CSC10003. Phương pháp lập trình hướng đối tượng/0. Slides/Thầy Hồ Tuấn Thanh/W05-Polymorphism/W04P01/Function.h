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
    virtual void Nhap();
    virtual long long TinhLuong()=0;
    virtual void In();

    NhanVien();
    NhanVien(string Ma);
    NhanVien(string Ma, string HoTen, string DiaChi);
    ~NhanVien();
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
    void In();

    NVSanXuat();
    NVSanXuat(string Ma);
    NVSanXuat(string Ma, string HoTen, string DiaChi);
    NVSanXuat(string Ma, string HoTen, string DiaChi, int SoSP);
    ~NVSanXuat();
};

class NVCongNhat: public NhanVien{
protected:
    int SoNgayDiLam;    
public:
    // override
    void Nhap();
    long long TinhLuong();
    void In();
};

class CongTy {
    vector<NhanVien*> v;
    string TenCongTy;
public:
    void Nhap();
    long long TinhTongLuong();
}

#endif