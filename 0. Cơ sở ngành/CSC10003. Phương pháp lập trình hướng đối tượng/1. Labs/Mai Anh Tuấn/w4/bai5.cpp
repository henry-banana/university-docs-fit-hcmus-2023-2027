#include "LinkedList.h"

class SoNguyenLon {
private:
    LinkedList<int> _list;
    int _size = 0;

    void removeLeadingZeros();

public:
    SoNguyenLon();
    SoNguyenLon(const int& x);
    SoNguyenLon(const int& x, const int& size);
    ~SoNguyenLon();

    SoNguyenLon(const SoNguyenLon& snl);
    SoNguyenLon& operator=(const SoNguyenLon& snl);

    friend SoNguyenLon operator-(const SoNguyenLon& snl1, const SoNguyenLon& snl2);
    friend SoNguyenLon operator-(const long long s1, const SoNguyenLon& snl2);

    friend SoNguyenLon operator+(const SoNguyenLon& snl1, const SoNguyenLon& s2);
    friend SoNguyenLon operator+(const SoNguyenLon& snl1, const long long s2);
    
    friend SoNguyenLon operator*(const SoNguyenLon& snl1, const SoNguyenLon& s2);
    
    bool operator>=(const SoNguyenLon& other) const;

    friend std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl);
};

// ==================================================

int main() {
    SoNguyenLon snl1; 
    SoNguyenLon snl2(44667733); 
    SoNguyenLon snl3(5, 9); 
    SoNguyenLon snl4(7, 30); 
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 1098765432 - snl2; 
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
    SoNguyenLon snl8 = snl2 * snl3; 

    std::cout << snl1 << "\n" << snl2 << "\n" << snl3 << "\n"; 
    std::cout << snl4 << "\n" << snl5 << "\n" << snl6 << "\n"; 
    std::cout << snl7 << "\n" << snl8 << "\n" << "\n"; 

    return 0;
}

// ==================================================
void SoNguyenLon::removeLeadingZeros() {
    while (_size > 1 && _list[0] == 0) {
        _list.RemoveHead();
        _size--;
    }
}

bool SoNguyenLon::operator>=(const SoNguyenLon& other) const {
    if (_size != other._size) {
        return _size > other._size;
    }
    for (int i = _size - 1; i >= 0; i--) {
        if (_list[i] != other._list[i]) {
            return _list[i] > other._list[i];
        }
    }
    return true;
}

SoNguyenLon::SoNguyenLon() {
    _list.AddHead(0);
    _size = 1;
}

SoNguyenLon::SoNguyenLon(const int& x) {
    int temp = x;
    if (x == 0) {
        _list.AddHead(0);
        _size = 1;
    } else {
        while (temp > 0) {
            _list.AddHead(temp % 10);
            temp /= 10;
            _size++;
        }
    }
}

SoNguyenLon::SoNguyenLon(const int& x, const int& size) {
    for (int i = 0; i < size; i++) {
        _list.AddTail(x);
        _size++;
    }
    removeLeadingZeros();
}

SoNguyenLon::~SoNguyenLon() {
    _list.~LinkedList<int>();
    _size = 0;
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) : _size(0) {
    for (int i = 0; i < snl._size; i++) {
        _list.AddTail(snl._list[i]);
        _size++;
    }
}

SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl) {
    if (this == &snl) {
        return *this;
    }

    _list.~LinkedList<int>();
    _list = LinkedList<int>();
    _size = 0;

    for (int i = 0; i < snl._size; i++) {
        _list.AddTail(snl._list[i]);
        _size++;
    }

    return *this;
}

SoNguyenLon operator+(const SoNguyenLon& snl1, const SoNguyenLon& snl2) {
    SoNguyenLon result;
    result._list.RemoveHead();
    result._size = 0;
    
    int carry = 0;
    int i = snl1._size - 1;
    int j = snl2._size - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? snl1._list[i--] : 0;
        int digit2 = (j >= 0) ? snl2._list[j--] : 0;
        
        int sum = digit1 + digit2 + carry;
        result._list.AddHead(sum % 10);
        carry = sum / 10;
        result._size++;
    }
    
    result.removeLeadingZeros();
    return result;
}

SoNguyenLon operator+(const SoNguyenLon& snl1, const long long s2) {
    SoNguyenLon snl2(s2);
    return snl1 + snl2;
}

SoNguyenLon operator-(const SoNguyenLon& snl1, const SoNguyenLon& snl2) {
    if (!(snl1 >= snl2)) {
        return SoNguyenLon(0);
    }

    SoNguyenLon result;
    result._list.RemoveHead();
    result._size = 0;
    
    int borrow = 0;
    int i = snl1._size - 1;
    int j = snl2._size - 1;
    
    while (i >= 0) {
        int digit1 = snl1._list[i--] - borrow;
        int digit2 = (j >= 0) ? snl2._list[j--] : 0;
        borrow = 0;
        
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        }
        
        result._list.AddHead(digit1 - digit2);
        result._size++;
    }
    
    result.removeLeadingZeros();
    return result;
}

SoNguyenLon operator-(const long long s1, const SoNguyenLon& snl2) {
    SoNguyenLon snl1(s1);
    return snl1 - snl2;
}

SoNguyenLon operator*(const SoNguyenLon& snl1, const SoNguyenLon& snl2) {
    SoNguyenLon result;
    result._list.RemoveHead();
    result._size = 0;
    
    for (int i = 0; i < snl1._size + snl2._size; i++) {
        result._list.AddTail(0);
        result._size++;
    }
    
    for (int i = snl1._size - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = snl2._size - 1; j >= 0; j--) {
            int pos = (snl1._size - 1 - i) + (snl2._size - 1 - j);
            int product = snl1._list[i] * snl2._list[j] + result._list[result._size - 1 - pos] + carry;
            carry = product / 10;
            result._list[result._size - 1 - pos] = product % 10;
        }
        if (carry > 0) {
            int pos = (snl1._size - 1 - i) + snl2._size;
            result._list[result._size - 1 - pos] += carry;
        }
    }
    
    result.removeLeadingZeros();
    return result;
}

std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl) {
    for (int i = 0; i < snl._size; i++) {
        os << snl._list[i];
    }
    return os;
}