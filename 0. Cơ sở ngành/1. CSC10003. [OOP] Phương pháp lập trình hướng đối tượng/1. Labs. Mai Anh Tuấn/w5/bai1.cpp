#include <iostream>

#define NOE 10

class A {
private:
    int info[NOE];
public:
    A();
    typedef int* indexOf;
    indexOf GetInfo(const int&); 
    void Xuat(std::ostream&);
};

A::A() {
    for (int i = 0; i < NOE; ++i) {
        info[i] = i + NOE; 
    }
}

A::indexOf A::GetInfo(const int &i) {
    indexOf rt = info + i; 
    return rt;
}

void A::Xuat(std::ostream &os) {
    for (int i = 0; i < NOE; ++i) {
        os << info[i] << ", "; 
    }
    os << "\n";
}

int main() {
    const int i = 7;
    A a;
    A::indexOf io = a.GetInfo(i);
    
    std::cout << *io << "\n";
    *io = 10;
    
    a.Xuat(std::cout);

    return 0;
}