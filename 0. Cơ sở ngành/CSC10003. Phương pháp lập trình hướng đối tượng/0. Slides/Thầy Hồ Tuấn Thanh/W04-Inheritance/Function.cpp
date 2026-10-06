#include "Function.h"

void NhanVien::Nhap()
{
    cout<<"Nhap ma nhan vien: ";
    getline(cin,Ma);
    cout<<"Nhap ho ten nhan vien: ";
    getline(cin,HoTen);
    cout<<"Nhap dia chi:";
    getline(cin,DiaChi);
    Luong = 0;
}

void NVSanXuat::Nhap(){
    // Option A: CORRECT
    NhanVien::Nhap();

    // // Option B: INCORRECT
    // cout<<"Nhap ma nhan vien: ";
    // getline(cin,Ma);
    // cout<<"Nhap ho ten nhan vien: ";
    // getline(cin,HoTen);
    // cout<<"Nhap dia chi:";
    // getline(cin,DiaChi);
    
    cout<<"Nhap so san pham: ";
    cin.ignore();
    cin>>SoSP;
}

void NVCongNhat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay di lam: ";
    cin.ignore();
    cin>>SoNgayDiLam;
}

long long NVSanXuat::TinhLuong(){
    Luong = NhanVien::TinhLuong() + SoSP * 1000;
    return Luong;
}

long long NVCongNhat::TinhLuong(){
    Luong =NhanVien::TinhLuong() + SoNgayDiLam * 300000;
    return Luong;
} 
long long NhanVien::TinhLuong(){
    Luong = 0;
    return Luong;
}