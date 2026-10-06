#include <iostream>
#include <string>
using namespace std;

class A{
public:
    int x;
    A(){ 
        x = 0;
    }
    A(int x){
        this->x = x;
    }
    virtual void show(){
        cout << "A::x: " << x << endl;
    }
};

class B{
public:
    int x;
    B(){
        x = 100;
    }
    B(int x){
        this->x = x;
    }
    void show(){
        cout << "B::x" << x << endl;
    }
};

class C: public A, public B{
public:
    C(){

    }
    C(int x): A(x), B(x*100){

    }
    // void show(){
    //     cout << "C::show(): " << A::x << " - "  << B::x << endl;
    // }
};

int main(){
    C c1;
    // // cout << c1.x << endl; // error
    // cout << c1.A::x << endl;
    // cout << c1.B::x << endl;

    // // c1.show(); // error
    // c1.A::show();
    // c1.B::show();
    // c1.show();

    A* pA;
    pA = &c1;
    // pA->show(); // void A::show();
    // pA->show(); // virtual void A::show();
    pA->show(); // remove void C::show();

    return 0;
}