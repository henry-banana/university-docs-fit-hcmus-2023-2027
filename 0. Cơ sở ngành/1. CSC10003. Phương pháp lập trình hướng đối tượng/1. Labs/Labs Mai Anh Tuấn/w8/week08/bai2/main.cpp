#include "HinhChuNhat.h"
#include "HinhTron.h"
#include "HinhHocPhang.h"
#include <iostream>

int main()
{
    HinhHocPhang* hhp = new HinhHocPhang();
    HinhHocPhang* hcn = new HinhChuNhat(34, 56.8); 
    HinhHocPhang* ht = new HinhTron(73.9);   

    std::cout << hhp->TinhDienTich() << "\t" << hcn->TinhDienTich() << "\t" << ht->TinhDienTich() << "\n";

    delete hhp;
    hhp = hcn;

    std::cout << hhp->TinhDienTich() << "\n";

    delete hcn;
    delete ht;

    hhp = nullptr;
    hcn = nullptr;
    ht = nullptr;
    
    return 0;
}