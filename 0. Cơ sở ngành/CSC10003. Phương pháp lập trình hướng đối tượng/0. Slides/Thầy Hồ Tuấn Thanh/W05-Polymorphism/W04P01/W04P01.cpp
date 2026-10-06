#include "Function.h"
// // NhanVien -> virtual -> NhanVien
// void f1(NhanVien nv){
//     nv.In();
// }

// NhanVien -> virtual -> NVSanXuat
void f2(NhanVien *nv){
    nv->In();
}

// NhanVien -> virtual -> NVSanXuat
void f3(NhanVien &nv){
    nv.In();
}

int main(){
    CongTy abc;
    abc.Nhap();
    cout << "Tong luong can tra trong thang: " << abc.TinhTongLuong() << endl;
    
    // NVSanXuat sx1("1", "Tuan", "TPHCM", 5000);
    // f3(sx1);

    // NVSanXuat sx1("1", "Tuan", "TPHCM", 5000);
    // f2(&sx1);

    // NVSanXuat sx1("1", "Tuan", "TPHCM", 5000);
    // f1(sx1);

    // NhanVien nv1("0", "Thanh", "Tay Ninh");
    // f1(nv1);

    // NVSanXuat sx1;
    // cout << "Nhap nvsx1" << endl;
    // sx1.Nhap();
    // cout << "nvsx1" << endl;
    // sx1.In();

    // NVCongNhat cn1;
    // cout << "Nhap nvcn1" << endl;
    // cin.ignore();
    // cn1.Nhap();
    // cout << "nvcn1" << endl;
    // cn1.In();

    // NhanVien nv1("1", "MATuan", "TPHCM");
    // nv1.In();

    // NVSanXuat sx1("1", "MATuan", "TPHCM", 5000);
    // sx1.In();

    return 0;
}