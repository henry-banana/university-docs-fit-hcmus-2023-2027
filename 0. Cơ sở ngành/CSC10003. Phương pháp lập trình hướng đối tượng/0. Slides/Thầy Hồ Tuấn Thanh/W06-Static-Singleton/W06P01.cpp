#include <iostream>
using namespace std;

class A{
private:
    static int count;

    // B2
    static A* conTro;

    // B1
    A(){
        cout << "A::constructor" << endl;
        count++;
    }
public:
    // B3
    A(const A& other) = delete;

    static int getCount(){
        return count;
    }

    // B4
    static A* getObject(){
        if(conTro == nullptr){
            conTro = new A;
        }
        else{
            // Do nothing
        }
        return conTro;
    }

    // B5
    A& operator=(const A& other) = delete;

    ~A(){
        cout << "A::Destructor" << endl;
    }

    // B8
    static void deleteObject(){
        if(conTro != nullptr){
            delete conTro;
            conTro = nullptr;
            count--;
        }
    }
};

int A::count = 0;

// B6
A* A::conTro = nullptr;

int main(){
    // B7
    A* a1 = A::getObject();
    A* a2 = A::getObject();
    A* a3 = A::getObject();
    A* a4 = A::getObject();
    cout << "Count: " << A::getCount() << endl;
    cout << (a1 == a2) << endl;
    // B9
    A::deleteObject();
    cout << "Count: " << A::getCount() << endl;
    return 0;
}