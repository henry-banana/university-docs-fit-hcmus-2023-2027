#include "QuanLyHinhHocPhang.h"
#include "HinhChuNhat.h"
#include "HinhTron.h"
#include "HinhTamGiac.h"
#include "HinhThangVuong.h"
#include <fstream>
#include <cstring>
#include <iostream>

IHinhHocPhang* createHinhChuNhatWrapper(std::istream& is) {
    return HinhChuNhat::createFromStream(is);
}

IHinhHocPhang* createHinhTronWrapper(std::istream& is) {
    return HinhTron::createFromStream(is);
}

IHinhHocPhang* createHinhTamGiacWrapper(std::istream& is) {
    return HinhTamGiac::createFromStream(is);
}

IHinhHocPhang* createHinhThangVuongWrapper(std::istream& is) {
    return HinhThangVuong::createFromStream(is);
}

const HinhHocPhangFactoryEntry hhp_factories[] = {
    {"hcn:", createHinhChuNhatWrapper},
    {"htr:", createHinhTronWrapper},
    {"htg:", createHinhTamGiacWrapper},
    {"hthv:", createHinhThangVuongWrapper}
};

const int num_hhp_factories = sizeof(hhp_factories) / sizeof(hhp_factories[0]);


QuanLyHinhHocPhang::QuanLyHinhHocPhang() : _soLuongHinh(0), _sucChua(_INITIAL_CAPACITY) {
    _danhSachHinh = new IHinhHocPhang*[_sucChua];
    for (int i = 0; i < _sucChua; ++i) {
        _danhSachHinh[i] = nullptr;
    }
}

QuanLyHinhHocPhang::~QuanLyHinhHocPhang() {
    for (int i = 0; i < _soLuongHinh; ++i) {
        delete _danhSachHinh[i];
    }
    delete[] _danhSachHinh;
}

void QuanLyHinhHocPhang::moRongDanhSach() {
    if (_soLuongHinh >= _sucChua) {
        int newCapacity = _sucChua + _CAPACITY_STEP;
        IHinhHocPhang** newDanhSach = new IHinhHocPhang*[newCapacity];
        for (int i = 0; i < _soLuongHinh; ++i) {
            newDanhSach[i] = _danhSachHinh[i];
        }
        for (int i = _soLuongHinh; i < newCapacity; ++i) {
            newDanhSach[i] = nullptr;
        }
        delete[] _danhSachHinh;
        _danhSachHinh = newDanhSach;
        _sucChua = newCapacity;
    }
}

void QuanLyHinhHocPhang::themHinh(IHinhHocPhang* hinh) {
    if (hinh == nullptr) return;
    moRongDanhSach();
    _danhSachHinh[_soLuongHinh++] = hinh;
}

std::istream& operator>>(std::istream& is, QuanLyHinhHocPhang& ql) {
    for (int i = 0; i < ql._soLuongHinh; ++i) {
        delete ql._danhSachHinh[i];
        ql._danhSachHinh[i] = nullptr;
    }
    ql._soLuongHinh = 0;

    char tag_buffer[10];
    char line_buffer[256];
    char peek_char;

    while (is.good() && !is.eof()) {
        peek_char = is.peek();
        while (peek_char != EOF && (peek_char == ' ' || peek_char == '\t' || peek_char == '\n' || peek_char == '\r')) {
            is.get();
            peek_char = is.peek();
        }

        if (is.eof() || !is.good()) break;

        is.getline(line_buffer, sizeof(line_buffer));
        if (strlen(line_buffer) == 0) continue;

        tag_buffer[0] = '\0';
        int tag_len = 0;
        int i = 0;
        while (line_buffer[i] && line_buffer[i] != ':' && tag_len < 9) {
            tag_buffer[tag_len++] = line_buffer[i++];
        }
        if (line_buffer[i] == ':') {
            tag_buffer[tag_len++] = ':';
            i++;
        }
        tag_buffer[tag_len] = '\0';

        while (line_buffer[i] && (line_buffer[i] == ' ' || line_buffer[i] == '\t')) {
            i++;
        }

        IHinhHocPhang* new_hinh = nullptr;
        bool tag_found = false;

        for (int j = 0; j < num_hhp_factories; ++j) {
            if (strcmp(tag_buffer, hhp_factories[j].tag) == 0) {
                tag_found = true;
                
                char params_buffer[200];
                strcpy(params_buffer, &line_buffer[i]);
                
                switch (j) {
                    case 0:
                        {
                            double chieuDai = 0, chieuRong = 0;
                            if (sscanf(params_buffer, "%lf,%lf", &chieuDai, &chieuRong) == 2) {
                                new_hinh = new HinhChuNhat(chieuDai, chieuRong);
                            }
                        }
                        break;
                    case 1:
                        {
                            double banKinh = 0;
                            if (sscanf(params_buffer, "%lf", &banKinh) == 1) {
                                new_hinh = new HinhTron(banKinh);
                            }
                        }
                        break;
                    case 2:
                        {
                            double a = 0, b = 0, c = 0;
                            if (sscanf(params_buffer, "%lf,%lf,%lf", &a, &b, &c) == 3) {
                                new_hinh = new HinhTamGiac(a, b, c);
                            }
                        }
                        break;
                    case 3:
                        {
                            double day = 0, canhBenTrai = 0, canhBenPhai = 0;
                            if (sscanf(params_buffer, "%lf,%lf,%lf", &day, &canhBenTrai, &canhBenPhai) == 3) {
                                new_hinh = new HinhThangVuong(day, canhBenTrai, canhBenPhai);
                            }
                        }
                        break;
                }
                break;
            }
        }

        if (tag_found) {
            if (new_hinh) {
                ql.themHinh(new_hinh);
            }
        } else {
            if (strlen(tag_buffer) > 0) {
                std::cerr << "Khong nhan dien tag: " << tag_buffer << "\n";
            } else {
                std::cerr << "Khong nhan dien tag, bo qua!\n";
            }
        }
    }
    return is;
}

bool QuanLyHinhHocPhang::docTuFile(const char* tenFile) {
    std::ifstream ifs(tenFile);
    if (!ifs) {
        std::cerr << "Khong the mo file: " << tenFile << "\n";
        return false;
    }
    ifs >> *this;
    return ifs.eof() || ifs.good();
}

std::ostream& operator<<(std::ostream& os, const QuanLyHinhHocPhang& ql) {
    os << "Danh sach cac hinh hoc phang:\n";
    for (int i = 0; i < ql._soLuongHinh; ++i) {
        if (ql._danhSachHinh[i]) {
            os << i + 1 << ". " << *(ql._danhSachHinh[i]) << "\n"; 
        }
    }
    return os;
}

void QuanLyHinhHocPhang::xuatThongKe(std::ostream& os) const {
    if (_soLuongHinh == 0) {
        os << "Khong co hinh nao trong danh sach.\n";
        return;
    }

    os << "\n--- THONG KE HINH HOC PHANG ---\n";

    double tongDienTich = 0;
    double tongChuVi = 0;

    int countHCN = 0;
    int countHTR = 0;
    int countHTG = 0;
    int countHTHV = 0;

    for (int i = 0; i < _soLuongHinh; ++i) {
        if (_danhSachHinh[i]) {
            tongDienTich += _danhSachHinh[i]->tinhDienTich();
            tongChuVi += _danhSachHinh[i]->tinhChuVi();

            const HinhHocPhangType loaiHinh = _danhSachHinh[i]->layLoaiHinh();
            if (loaiHinh == HINH_CHU_NHAT) countHCN++;
            else if (loaiHinh == HINH_TRON) countHTR++;
            else if (loaiHinh == HINH_TAM_GIAC) countHTG++;
            else if (loaiHinh == HINH_THANG_VUONG) countHTHV++;
        }
    }

    os << "So luong cac loai hinh:\n";
    os << " - Hinh Chu Nhat: " << countHCN << "\n";
    os << " - Hinh Tron: " << countHTR << "\n";
    os << " - Hinh Tam Giac: " << countHTG << "\n";
    os << " - Hinh Thang Vuong: " << countHTHV << "\n";
    os << "-----------------------------\n";
    os << "Tong dien tich tat ca cac hinh: " << tongDienTich << "\n";
    os << "Tong chu vi tat ca cac hinh: " << tongChuVi << "\n";
    os << "-----------------------------\n";
}