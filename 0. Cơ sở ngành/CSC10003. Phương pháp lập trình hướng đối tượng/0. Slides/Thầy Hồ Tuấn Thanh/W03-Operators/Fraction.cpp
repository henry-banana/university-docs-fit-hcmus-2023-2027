#include "Fraction.h"

Fraction::Fraction(){
    num = 0;
    den = 1;
}

Fraction::Fraction(int a){
    num = a;
    den = 1;
}

Fraction::Fraction(int a, int b){
    num = a;
    den = b;
}

// Fraction Fraction::operator+(const Fraction& f){
//     // int a = 3;
//     // int b = 5;
//     // int c = a + b;
//     // // c = 8; a = 3;

//     Fraction ans;
//     ans.num = this->num * f.den + this->den * f.num;
//     ans.den = this->den * f.den;
//     return ans;
// }

string Fraction::toString(){
    return to_string(num) + "/" + to_string(den);
}

bool Fraction::operator<(const Fraction& other) {
    return (num * other.den < den * other.num);
}

Fraction& Fraction::operator+=(const Fraction& other){
    this->num = this->num * other.den + this->den * other.num;
    this->den = this->den * other.den;
    return *this;
}

//p3 = p1 + 6
Fraction Fraction::operator+(int a) {
    Fraction ans;
    ans.num = this->num + a * this->den;
    ans.den = this->den;
    return ans;
}
Fraction operator+(const Fraction& a, const Fraction& b){
    // Option 2.2
    Fraction ans;
    ans.num = a.num * b.den + a.den * b.num; // error "private"
    ans.den = a.den * b.den; // error "private"
    return ans;

    // // Option 2.1
    // int x = a.getNum() * b.getDen() + a.getDen() * b.getNum();
    // int y = a.getDen() * b.getDen();
    // Fraction ans(x, y);
    // return ans;
}