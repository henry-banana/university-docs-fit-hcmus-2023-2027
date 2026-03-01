#include "QuanLyHinhHocPhang.h"
#include <iostream>
#include <fstream> 

int main() {
    QuanLyHinhHocPhang qlHHP;

    if (qlHHP.docTuFile("hhp.txt")) {
        std::cout << "Doc file thanh cong.\n";
        std::cout << qlHHP; 
        qlHHP.xuatThongKe(std::cout);
    } else {
        std::cout << "Doc file that bai hoac file rong.\n";
    }

    return 0;
}