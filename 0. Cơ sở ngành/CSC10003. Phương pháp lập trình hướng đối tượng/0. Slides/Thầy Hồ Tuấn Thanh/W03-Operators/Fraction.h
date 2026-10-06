#ifndef _FRAC_
#define _FRAC_
#include <iostream>
using namespace std;

class Fraction{
    int num, den;
public:
    Fraction();
    Fraction(int a);
    Fraction(int a, int b);
    // Fraction operator+(const Fraction& f); // member of Fraction => Option 1
    Fraction& operator+=(const Fraction& f);
    string toString();
    bool operator<(const Fraction& other);
    Fraction operator+(int a);
    int getNum() const{
        return num;
    }
    int getDen() const{
        return den;
    }
    void setNum(int x){
        num = x;
    }
    void setDen(int x){
        den = x;
    }

    // Option 2.2
    friend Fraction operator+(const Fraction& a, const Fraction& b); // not a member of Fraction
};

// // Option 2.1
// Fraction operator+(const Fraction& a, const Fraction& b); // not a member of Fraction

#endif