#include "CongTy.h"
#include <iostream>
#include <fstream>

int main() {
    CongTy cong_ty;
    
    if (!cong_ty.docDuLieu("input.txt")) {
        std::cout << "Không thể đọc file input.txt!\n";
        return 1;
    }
    
    std::cout << "====================================\n";
    cong_ty.xuatDanhSachNhanVien(std::cout);
    
    std::cout << "====================================\n";
    cong_ty.xuatDanhSachNhanVienXuatSac(std::cout);
    
    return 0;
}