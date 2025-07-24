#include <iostream>
#include <cstring>

// ================== PROTOTYPE ==================
class NgayThang {
private:
    int _ngay, _thang, _nam;
    bool laNamNhuan(const int& nam) const;
    int soNgayTrongThang(const int& thang, const int& nam) const;
    void chuanHoa();
public:
    NgayThang();
    NgayThang(const int& ngay);
    NgayThang(const int& ngay, const int& thang, const int& nam);
    NgayThang(const char* s);
    ~NgayThang();
    void xuatNgay() const;
};

class SinhVien {
private:
    char _mssv[8];
    char* _ho_ten;
    float _dlt, _dth;
    NgayThang _ngay_sinh;
public:
    SinhVien();
    SinhVien(const char* mssv);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const int& ngay, const int& thang, const int& nam);
    SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const NgayThang& ngaysinh);
    SinhVien(const SinhVien& sv);
    ~SinhVien();
    void xuatSinhVien() const;
};

// ================== MAIN ==================
int main() {
    //MSSV: "xxxxxxx", HoTen: "xxxx", NgaySinh: xx/xx/xxxx, DLT: 10, DTH: 10.
    SinhVien sv1;
    sv1.xuatSinhVien();

    SinhVien sv2("1363001");
    sv2.xuatSinhVien ();

    SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
    sv3.xuatSinhVien ();

    SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996) ;
    sv4.xuatSinhVien ();

    NgayThang n(30,2,1996);
    SinhVien sv5 ("1363004", "Ngo Van C", 5, 6, n);
    sv5.xuatSinhVien ();

    SinhVien sv6(sv5);
    sv6.xuatSinhVien ();
    
    return 0;
}

// ================== IMPLEMENTATION ==================
SinhVien::SinhVien() {
    strcpy(_mssv, "xxxxxxx");
    _ho_ten = new char[4];
    strcpy(_ho_ten, "xxxx");
    _dlt = _dth = 10;
    _ngay_sinh = NgayThang();
}

SinhVien::SinhVien(const char* mssv) {
    strcpy(_mssv, mssv);
    _ho_ten = new char[4];
    strcpy(_ho_ten, "xxxx");
    _dlt = _dth = 10;
    _ngay_sinh = NgayThang();
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth) {
    strcpy(_mssv, mssv);
    _ho_ten = new char[strlen(hoten) + 1];
    strcpy(_ho_ten, hoten);
    _dlt = dlt;
    _dth = dth;
    _ngay_sinh = NgayThang();
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const int& ngay, const int& thang, const int& nam) {
    strcpy(_mssv, mssv);
    _ho_ten = new char[strlen(hoten) + 1];
    strcpy(_ho_ten, hoten);
    _dlt = dlt;
    _dth = dth;
    _ngay_sinh = NgayThang(ngay, thang, nam);
}

SinhVien::SinhVien(const char* mssv, const char* hoten, const float& dlt, const float& dth, const NgayThang& ngaysinh) {
    strcpy(_mssv, mssv);
    _ho_ten = new char[strlen(hoten) + 1];
    strcpy(_ho_ten, hoten);
    _dlt = dlt;
    _dth = dth;
    _ngay_sinh = ngaysinh;
}

SinhVien::SinhVien(const SinhVien& sv) {
    strcpy(_mssv, sv._mssv);
    _ho_ten = new char[strlen(sv._ho_ten) + 1];
    strcpy(_ho_ten, sv._ho_ten);
    _dlt = sv._dlt;
    _dth = sv._dth;
    _ngay_sinh = sv._ngay_sinh;
}

SinhVien::~SinhVien() {
    delete[] _ho_ten;
}

void SinhVien::xuatSinhVien() const {
    std::cout << "MSSV: " << _mssv << "\nHoTen: " << _ho_ten << "\nNgaySinh: ";
    _ngay_sinh.xuatNgay();
    std::cout << "\nDLT: " << _dlt << "\nDTH: " << _dth << "\n\n";
}

// ================== NGAY THANG ==================
NgayThang::NgayThang() : _ngay(1), _thang(1), _nam(1) {}

NgayThang::NgayThang(const int& ngay) : _ngay(abs(ngay)), _thang(1), _nam(1) {
    chuanHoa();
}

NgayThang::NgayThang(const int& ngay, const int& thang, const int& nam) : _ngay(abs(ngay)), _thang(abs(thang)), _nam(abs(nam)) {
    chuanHoa();
}

NgayThang::NgayThang(const char* s) {
    char* buffer = new char[strlen(s) + 1];     // "12-12-2012\0"
    strcpy(buffer, s);

    char* token = strtok(buffer, "-/");
    _ngay = token ? atoi(token) : 1;

    token = strtok(nullptr, "-/");
    _thang = token ? atoi(token) : 1;

    token = strtok(nullptr, "-/");
    _nam = token ? atoi(token) : 1;

    delete[] buffer;
    chuanHoa();
}

NgayThang::~NgayThang() {

}

void NgayThang::xuatNgay() const {
    std::cout << _ngay << '/' << _thang << '/' << _nam;
}

void NgayThang::chuanHoa() {
    _ngay = abs(_ngay);
    _thang = abs(_thang);
    _nam = abs(_nam);

    // Xử lý ngày dư thừa
    while (_ngay > soNgayTrongThang(_thang, _nam)) {
        _ngay -= soNgayTrongThang(_thang, _nam);
        _thang++;
        if (_thang > 12) {
            _thang = 1;
            _nam++;
        }
    }

    // Xử lý tháng dư thừa  
    while (_thang > 12) {
        _thang -= 12;
        _nam++;
    }
}

int NgayThang::soNgayTrongThang(const int& thang, const int& nam) const {
    if (thang == 2) {
        return laNamNhuan(nam) ? 29 : 28;
    }

    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }

    return 31;
}

bool NgayThang::laNamNhuan(const int& nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}