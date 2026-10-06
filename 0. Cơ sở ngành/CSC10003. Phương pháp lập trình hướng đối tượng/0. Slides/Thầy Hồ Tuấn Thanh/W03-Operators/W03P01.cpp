#include "IntArray.h"
#include "Fraction.h"

// int main(){
//     IntArray m1; // nullptr, 0
//     // m1.inputFromKeyboard();
//     cout << "m1: " << m1.toString() << endl;

//     int a[] = {10, 20, 30};
//     IntArray m2(a, 3);
//     cout << "m2: "  << m2.toString() << endl;
//     a[0] = 80;
//     cout << "m2: "  << m2.toString() << endl;

//     IntArray m3(m2);
//     cout << "m3: "  << m3.toString() << endl;

//     IntArray m4;
//     m4.inputFromKeyboard();
//     m4 = m2;
//     // m2 = m2;
//     cout << "m4: "  << m4.toString() << endl;

//     IntArray m5(m5);
//     cout << "m5: "  << m5.toString() << endl;
//     return 0;
// }

// int main(){
//     School abc("ABC");
//     Student st1(24127001, "Nguyen Van A", &abc);
//     Student st2(24127002, "Ly Thi B", &abc);
//     cout << "st1: " << st1.toString() << endl;
//     cout << "st2: " << st2.toString() << endl;

//     abc.changeName("Super ABC");
//     cout << "st1: " << st1.toString() << endl;
//     cout << "st2: " << st2.toString() << endl;

//     // st1: Name: Nguyen Van A; ID: 24127001; My school: ABC
//     // st2: Name: Ly Thi B; ID: 24127002; My school: ABC
//     // st1: Name: Nguyen Van A; ID: 24127001; My school: Super ABC
//     // st2: Name: Ly Thi B; ID: 24127002; My school: Super ABC
//     // Destructor Student: Ly Thi B
//     // Destructor Student: Nguyen Van A
//     return 0;
// }

int main(){
    Fraction p1(1, 2);
    Fraction p2(3, 4);

    Fraction p3 = p1 + p2;
    // p3 = p1.operator+(p2);
    cout << "p1 + p2 = " << p3.toString() << endl;

    bool check = p1 < p2;
    if(check){
        cout << "p1 < p2" << endl;
    }
    else{
        cout << "p1 >= p2" << endl;
    }

    // p1 += p2;
    // cout << "p1 += p2: " << p1.toString() << endl;

    p3 = p1 + 6;
    cout << "p1 + 6: " << p3.toString() << endl;

    p3 = 7 + p1;
    cout << "7 + p1: " << p3.toString() << endl;

    cout << "Hello 2" << endl;
    return 0;
}