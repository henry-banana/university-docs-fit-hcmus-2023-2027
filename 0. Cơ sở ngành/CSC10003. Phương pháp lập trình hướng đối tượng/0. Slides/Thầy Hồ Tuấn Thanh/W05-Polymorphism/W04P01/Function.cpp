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
NVSanXuat::NVSanXuat(){
    cout << "NVSanXuat def cons" << endl;
    
}
NVSanXuat::NVSanXuat(string Ma): NhanVien(Ma){
    cout << "NVSanXuat 1-arg cons" << endl;
    SoSP = 0;
}
NVSanXuat::NVSanXuat(string Ma,string HoTen,string DiaChi): NhanVien(Ma,HoTen,DiaChi)
{
    cout << "NVSanXuat 3-arg cons" << endl;
    SoSP = 0;
}
NVSanXuat::NVSanXuat(string Ma,string HoTen,string DiaChi,int SoSP):NhanVien(Ma,HoTen,DiaChi){
    cout << "NVSanXuat 4-arg cons" << endl;
    this -> SoSP = SoSP;
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
    // cin.ignore();
    cin>>SoSP;
}

void NVCongNhat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay di lam: ";
    cin>>SoNgayDiLam;
}

long long NVSanXuat::TinhLuong(){
    // Luong = NhanVien::TinhLuong() + SoSP * 1000;
    Luong = SoSP * 1000;
    return Luong;
}

long long NVCongNhat::TinhLuong(){
    // Luong = NhanVien::TinhLuong() + SoNgayDiLam * 300000;
    Luong = SoNgayDiLam * 300000;
    return Luong;
} 
long long NhanVien::TinhLuong(){
    Luong = 0;
    return Luong;
}

void NhanVien::In(){
    cout << "Ma NV: " << Ma << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Dia chi: " << DiaChi << endl;
    TinhLuong(); // template method
    cout << "Luong: " << Luong << endl;
}

void NVSanXuat::In(){
    NhanVien::In();
    cout << "So SP: " << SoSP << endl;
}

void NVCongNhat::In(){
    NhanVien::In();
    cout << "So ngay lam: " << SoNgayDiLam << endl;
}

NhanVien::NhanVien() {
    cout << "NhanVien def cons" << endl;
    this->Ma = "1";
    this->HoTen = "No name";
    this->DiaChi = "No addr";
    this->Luong = 0;
}

NhanVien::NhanVien(string name) {
    cout << "NhanVien 1-arg cons" << endl;
    this->Ma = "1";
    this->HoTen = name;
    this->DiaChi = "No addr";
    this->Luong = 0;
}

NhanVien::NhanVien(string ma, string ten, string addr) {
    cout << "NhanVien 3-arg cons" << endl;
    this->Ma = ma;
    this->HoTen = ten;
    this->DiaChi = addr;
    this->Luong = 0;
}

NhanVien::~NhanVien(){
    cout << "NhanVien des" << endl;
}

NVSanXuat::~NVSanXuat(){
    cout << "NVSanXuat des" << endl;
}

void CongTy::Nhap(){
    cout << "Ten cong ty: ";
    getline(cin, TenCongTy);
    int n;
    cout << "So luong nhan vien: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int Loai;
        cout << "NV thu " << i << ":" << endl;
        cout << "Loai NV(1: SX; 2: CN): ";
        cin >> Loai;
        NhanVien* nv;
        if(Loai == 1){
            nv = new NVSanXuat();
        }
        else{
            nv = new NVCongNhat();
        }
        // polymorphism
        nv->Nhap();
        v.push_back(nv);
    }
}
long long CongTy::TinhTongLuong(){
    long long Tong = 0;
    for(int i = 0; i < v.size(); i++){
        Tong += v[i]->TinhLuong();
    }
    return Tong;
}