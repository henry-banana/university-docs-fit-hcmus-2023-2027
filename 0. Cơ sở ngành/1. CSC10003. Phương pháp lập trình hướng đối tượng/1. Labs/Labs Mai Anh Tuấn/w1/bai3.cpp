#include <iostream>
#include <iomanip>
// ================== PROTOTYPE ==================
class ThoiGian {
private:
    int _gio, _phut, _giay;
    void chuanHoa();
public:
    ThoiGian();
    ThoiGian(const int& giay);
    ThoiGian(const int& phut, const int& giay);
    ThoiGian(const int& gio, const int& phut, const int& giay);
    ~ThoiGian();
    void xuatThoiGian();
};


// ================== MAIN ==================
int main() {
    ThoiGian tg1; //00:00:00
    tg1.xuatThoiGian();
    
    ThoiGian tg2(1212); //00:20:12
    tg2.xuatThoiGian ();
    
    ThoiGian tg3(125,45); //02:05:45
    tg3.xuatThoiGian();
    
    ThoiGian tg4(12,239,-78); //15:59:00
    tg4.xuatThoiGian();
}

// ================== IMPLEMENTATION ==================
ThoiGian::ThoiGian() : _gio(0), _phut(0), _giay(0) {}

ThoiGian::ThoiGian(const int& giay) : _gio(0), _phut(0), _giay(giay <= 0 ? 0 : giay) {
    chuanHoa();
}

ThoiGian::ThoiGian(const int& phut, const int& giay) : _gio(0), _phut(abs(phut)), _giay(giay <= 0 ? 0 : giay) {
    chuanHoa();
}

ThoiGian::ThoiGian(const int& gio, const int& phut, const int& giay) : _gio(abs(gio)), _phut(abs(phut)), _giay(giay <= 0 ? 0 : giay) {
    chuanHoa();
}

ThoiGian::~ThoiGian() {
    
}

void ThoiGian::chuanHoa() {
    _phut += _giay / 60;
    _giay %= 60;
    _gio += _phut / 60;
    _phut %= 60;
}

void ThoiGian::xuatThoiGian() {
    std::cout << std::setw(2) << std::setfill('0') << _gio << ":" 
            << std::setw(2) << std::setfill('0') << _phut << ":" 
            << std::setw(2) << std::setfill('0') << _giay << "\n";
}