#include "Shape.h"
#include <vector>
#include <iostream>
#include <memory>

int main() {
    std::vector<Hinh*> dsHinh;

    dsHinh.push_back(new HinhTron(3.5));
    dsHinh.push_back(new HinhTamGiacDeu(8.5));
    dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
    dsHinh.push_back(new HinhVuong(4.1));
    dsHinh.push_back(new HinhCau(13.5));
    dsHinh.push_back(new HinhLapPhuong(2.9));
    dsHinh.push_back(new HinhHop(1.2, 3.7, 6.3));
    dsHinh.push_back(new HinhTru(6.1, 4.9)); // Sửa lỗi cú pháp (:
    dsHinh.push_back(new HinhNon(8.7, 3.2));


    std::cout << "Thong tin cac hinh:\n";
    /// xuất thông tin các hình
    /// định dạng: <tên hình> [P hoặc Sxq = xx, S hoặc V = xx]
    /// ví dụ: "Hinh Vuong [P = 12.5, S = 45.7]"
    /// hoặc: "Hinh Cau [Sxq = 45.7, V = 67.4]"
    // Toán tử << đã được nạp chồng cho Hinh và gọi hàm ảo xuatThongTin
    for (int i = 0; i < dsHinh.size(); i++) {
        std::cout << *dsHinh[i] << "\n";
    }

    std::cout << "\n\n";

    // Giải phóng bộ nhớ
    for (int i = 0; i < dsHinh.size(); i++) {
        delete dsHinh[i]; // Giải phóng bộ nhớ cho từng đối tượng
    }

    dsHinh.clear(); // Xóa các con trỏ khỏi vector

    return 0;
}