#include <iostream>
#include <vector>
#include <cstring>

class SoNguyenLon {
private:
    std::vector<unsigned char> lCS;
    void Pow10(const int& n);
public:
    SoNguyenLon(void);
    SoNguyenLon(const int& cs, const int& scs);
    SoNguyenLon(const unsigned long& n);
    SoNguyenLon(const SoNguyenLon& snl);
    SoNguyenLon(const char* s);
    ~SoNguyenLon(void);

    int SoCS();
    SoNguyenLon operator+(SoNguyenLon snl);
    SoNguyenLon operator-(SoNguyenLon snl);
    SoNguyenLon operator*(SoNguyenLon snl);
    bool operator>(SoNguyenLon& snl);
    const SoNguyenLon& operator=(const SoNguyenLon& snl);
    SoNguyenLon& operator+=(SoNguyenLon snl);

    friend SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl);
    friend SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl);
    friend std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl);
};

// ===========================================

int main() {
    const int iTest = 78912; 
    SoNguyenLon snl1(123); 
    SoNguyenLon snl2(40000); 
    std::cout << snl1 << " + " << snl2 << " = "; 
    std::cout << (snl1 + snl2) << "\n"; 

    std::cout << snl1 << " * " << snl2 << " = "; 
    std::cout << (snl1 * snl2) << "\n"; 

    std::cout << snl1 << " - " << snl2 << " = "; 
    std::cout << (snl1 - snl2) << "\n"; 

    std::cout << snl2 << " - " << snl1 << " = ";
    std::cout << (snl2 - snl1) << "\n";

    std::cout << iTest << " - " << snl2 << " = ";
    std::cout << (iTest - snl2) << "\n";

    return 0;
}

// ===========================================

void SoNguyenLon::Pow10(const int& n) {
    for (int i = 0; i < n; ++i) {
        lCS.insert(lCS.begin(), 0);
    }
}

SoNguyenLon::SoNguyenLon(void) {
    lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs) {
    int csR = cs;
    if (csR < 1) {
        csR = 1;
    }

    if (csR > 9) {
        csR = 9;
    }

    int soCS = abs(scs);
    if (soCS < 1) {
        soCS = 1;
    }

    for (int i = 0; i < soCS; ++i) {
        lCS.push_back(csR);
    }
}

SoNguyenLon::SoNguyenLon(const unsigned long& n) {
    unsigned long temp = n;
    while (temp) {
        lCS.push_back(temp % 10);
        temp /= 10;
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
    lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] < '0' || s[i] > '9') {
            std::cerr << "Invalid character in string: " << s[i] << "\n";
            return;
        }
        lCS.push_back(s[i] - '0');
    }
}

SoNguyenLon::~SoNguyenLon(void) {

}


int SoNguyenLon::SoCS() {
    return lCS.size();
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl) {
    SoNguyenLon snlKQ;
    snlKQ.lCS.clear();
    SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
    int nho = 0, temp;

    for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
        temp = lCS[i] + snl.lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }

    for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i) {
        temp = snlSCSMax->lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }

    if (nho > 0) {
        snlKQ.lCS.push_back(nho);
    }
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl) {
    if (!(*this > snl)) {
        return SoNguyenLon();
    }

    SoNguyenLon snlKQ;
    snlKQ.lCS.clear();
    
    int muon = 0, temp;
    
    for (int i = 0; i < snl.SoCS(); ++i) {
        temp = lCS[i] - snl.lCS[i] - muon;
        if (temp < 0) {
            temp += 10;
            muon = 1;
        } else {
            muon = 0;
        }
        snlKQ.lCS.push_back(temp);
    }
    
    for (int i = snl.SoCS(); i < SoCS(); ++i) {
        temp = lCS[i] - muon;
        if (temp < 0) {
            temp += 10;
            muon = 1;
        } else {
            muon = 0;
        }
        snlKQ.lCS.push_back(temp);
    }
    
    while (snlKQ.lCS.size() > 1 && snlKQ.lCS.back() == 0) {
        snlKQ.lCS.pop_back();
    }
    
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl) {
    SoNguyenLon snlKQ, * psnlTemp;
    SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
    int nho = 0, temp;

    for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
        psnlTemp = new SoNguyenLon;
        psnlTemp->lCS.clear();
        nho = 0;

        for (int j = 0; j < snlSCSMax->SoCS(); ++j) {
            temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
            psnlTemp->lCS.push_back(temp % 10);
            nho = temp / 10;
        }

        if (nho > 0) {
            psnlTemp->lCS.push_back(nho);
        }

        psnlTemp->Pow10(i);
        snlKQ += *psnlTemp;
        delete psnlTemp;
    }

    return snlKQ;
}

bool SoNguyenLon::operator>(SoNguyenLon& snl) {
    if (lCS.size() > snl.lCS.size()) {
        return true;
    } else if (lCS.size() < snl.lCS.size()) {
        return false;
    }

    for (int i = lCS.size() - 1; i >= 0; --i) {
        if (lCS[i] > snl.lCS[i]) {
            return true;
        } else if (lCS[i] < snl.lCS[i]) {
            return false;
        }
    }
    return false;
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl) {
    if (this != &snl) {
        lCS = snl.lCS;
    }
    return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl) {
    SoNguyenLon snlKQ = *this + snl;
    lCS = snlKQ.lCS;
    return *this;
}


SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl) {
    SoNguyenLon snl1(n);
    SoNguyenLon snlKQ = snl1 + snl;
    return snlKQ;
}

SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl) {
    SoNguyenLon snl1(n);
    SoNguyenLon snlKQ = snl1 - snl;
    return snlKQ;
}

std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl) {
    for (int i = snl.lCS.size() - 1; i >= 0; --i) {
        os << (int)snl.lCS[i];
    }
    return os;
}

