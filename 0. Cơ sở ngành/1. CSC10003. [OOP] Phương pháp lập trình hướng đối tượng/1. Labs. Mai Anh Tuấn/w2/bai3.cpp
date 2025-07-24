#include <iostream>
#include <cstring>
#include <iomanip>

class HocSinh {
private:
    char* _ho_ten = nullptr;
    double _diem_toan = 0;
    double _diem_ly = 0;
    double _diem_hoa = 0;
    int _ms_hs;

    static int _ms;
    static HocSinh _hs_diem_tb_cao_nhat;

    void CapNhatDiemTBCaoNhat();

public:
    HocSinh();
    HocSinh(const char* ho_ten, double diem_toan, double diem_ly, double diem_hoa);
    ~HocSinh();

    HocSinh(const HocSinh& other);
    HocSinh& operator=(const HocSinh& other);

    double DiemTB() const;
    void DatHoTen(const char* ho_ten);
    void GanDiem(double diem_toan, double diem_ly, double diem_hoa);
    void In(std::ostream& os) const;

    static HocSinh& HSDiemTBCaoNhat();
};

int HocSinh::_ms = 23120001;
HocSinh HocSinh::_hs_diem_tb_cao_nhat("", 0, 0, 0);

// ===============================

int main() {
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);

    HocSinh hs2("Tran Thi B", 5, 8, 4.5);

    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);

    HocSinh hs4("Le Van D", 7.5, 9, -10);

    // "HS: Nguyen Van A, MS: 23120001, DTB: 7.53"
    hs1.In(std::cout);
    std::cout << "\n";

    hs2.In(std::cout);
    std::cout << "\n";

    hs3.In(std::cout);
    std::cout << "\n";

    hs4.In(std::cout);
    std::cout << "\n";

    std::cout << "\nHoc sinh co diem TB cao nhat:" << "\n";
    HocSinh::HSDiemTBCaoNhat().In(std::cout); // Không tạo bản sao
    std::cout << "\n";

    return 0;
}

// ===============================

void HocSinh::CapNhatDiemTBCaoNhat() {
    if (this->DiemTB() > _hs_diem_tb_cao_nhat.DiemTB()) {
        _hs_diem_tb_cao_nhat = *this;
    }
}

HocSinh& HocSinh::HSDiemTBCaoNhat() {
    return _hs_diem_tb_cao_nhat;
}

HocSinh::HocSinh() : _ms_hs(_ms++) {
    _ho_ten = new char[1];
    strcpy(_ho_ten, "");
    GanDiem(0, 0, 0);
    CapNhatDiemTBCaoNhat();
}

HocSinh::HocSinh(const char* ho_ten, double diem_toan, double diem_ly, double diem_hoa) {
    _ho_ten = new char[strlen(ho_ten) + 1];
    strcpy(_ho_ten, ho_ten);
    GanDiem(diem_toan, diem_ly, diem_hoa);
    _ms_hs = _ms++;
    CapNhatDiemTBCaoNhat();
}

HocSinh::HocSinh(const HocSinh& other) {
    _ho_ten = new char[strlen(other._ho_ten) + 1];
    strcpy(_ho_ten, other._ho_ten);
    _diem_toan = other._diem_toan;
    _diem_ly = other._diem_ly;
    _diem_hoa = other._diem_hoa;
    _ms_hs = other._ms_hs;
}

HocSinh& HocSinh::operator=(const HocSinh& other) {
    if (this == &other) {
        return *this;
    }

    delete[] _ho_ten;

    _ho_ten = new char[strlen(other._ho_ten) + 1];
    strcpy(_ho_ten, other._ho_ten);
    _diem_toan = other._diem_toan;
    _diem_ly = other._diem_ly;
    _diem_hoa = other._diem_hoa;
    _ms_hs = other._ms_hs;

    return *this;
}

HocSinh::~HocSinh() {
    if (_ho_ten) {
        delete[] _ho_ten;
    }
}

double HocSinh::DiemTB() const {
    return (_diem_toan + _diem_ly + _diem_hoa) / 3;
}

void HocSinh::DatHoTen(const char* ho_ten) {
    delete[] _ho_ten;
    _ho_ten = new char[strlen(ho_ten) + 1];
    strcpy(_ho_ten, ho_ten);
}

void HocSinh::GanDiem(double diem_toan, double diem_ly, double diem_hoa) {
    _diem_toan = diem_toan < 0 ? 0 : diem_toan;
    _diem_ly = diem_ly < 0 ? 0 : diem_ly;
    _diem_hoa = diem_hoa < 0 ? 0 : diem_hoa;
    CapNhatDiemTBCaoNhat();
}

void HocSinh::In(std::ostream& os) const {
    os << "HS: " << _ho_ten << ", MS: " << _ms_hs << ", DTB: " << std::fixed << std::setprecision(2) << DiemTB();
}