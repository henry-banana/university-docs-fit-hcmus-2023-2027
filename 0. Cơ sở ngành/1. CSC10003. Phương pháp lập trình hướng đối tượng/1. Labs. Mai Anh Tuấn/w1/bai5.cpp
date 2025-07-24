#include <iostream>

// ================== PROTOTYPE ==================
class MangSoNguyen {
private:
    int* _arr;
    int _size;
public:
    MangSoNguyen();
    MangSoNguyen(const int& size);
    MangSoNguyen(int* arr, const int& size);
    MangSoNguyen(const MangSoNguyen& msn);
    ~MangSoNguyen();
    void Xuat() const;
};

// ================== MAIN =======================
int main() {
    MangSoNguyen msn1;
    msn1.Xuat();

    MangSoNguyen msn2 (5);
    msn2.Xuat ();

    int arr[10];
    for (int i = 0; i < 8; i++) {
        arr[i] = i * i;
    }
    MangSoNguyen msn3(arr, 8);
    msn3.Xuat();

    MangSoNguyen msn4(msn3);
    msn4.Xuat();

    return 0;
}

// ================== IMPLEMENTATION ==================
MangSoNguyen::MangSoNguyen() {
    _size = 0;
    _arr = nullptr;
}

MangSoNguyen::MangSoNguyen(const int& size) {
    _size = size;
    _arr = new int[size];
    for (int i = 0; i < size; i++) {
        _arr[i] = i;
    }
}

MangSoNguyen::MangSoNguyen(int* arr, const int& size) {
    _size = size;
    _arr = new int[size];
    for (int i = 0; i < size; i++) {
        _arr[i] = arr[i];
    }
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& msn) {
    _size = msn._size;
    _arr = new int[_size];
    for (int i = 0; i < _size; i++) {
        _arr[i] = msn._arr[i];
    }
}

MangSoNguyen::~MangSoNguyen() {
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
}

void MangSoNguyen::Xuat() const {
    std::cout << "Mang so nguyen: ";

    for (int i = 0; i < _size; i++) {
        std::cout << _arr[i] << ' ';
    }

    std::cout << "\n";
}