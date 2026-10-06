#include "Point2D.h"

// int main(){
//     // Point2D p1(3, 4);
//     // cout << "p1: " << p1.toString() << endl;

//     // Point2D p2(10); // 10 10 
//     // cout << "p2: " << p2.toString() << endl;

//     // // // nếu trong 1 class, ta ko viết constructor nào hết,
//     // // // thì class đó sẽ có sẵn 1 built-in default constructor
//     // // // nhưng nếu ta đã viết một vài constructor cho class đó rồi,
//     // // // built-in default constructor ko còn nữa
//     // // // Point2D p3(); // sai vì p3 là 1 hàm, ko phải 1 object
//     // // // cout << "p3: " << p3.toString() << endl;

//     // Point2D p4; // 0 0 
//     // cout << "p4: " << p4.toString() << endl;

//     // // nếu class chưa có copy constructor,
//     // // thì đã có sẵn built-in copy constructor
//     // Point2D p5 = p1; // 3 4
//     // cout << "p5: " << p5.toString() << endl;

//     // cout << "d(p4, p5): " << p4.distance1(p5) << endl;
//     // cout << "d(p4, p5): " << p4.distance2(p5) << endl;

//     // Point2D p6(p1); // 3 4
//     // cout << "p6: " << p6.toString() << endl;

//     // Point2D p7;
//     // p7 = p1;
//     // cout << "p7: " << p7.toString() << endl;

//     // Point2D *p8;

//     // Point2D *p9;
//     // p9 = new Point2D(10);
//     // cout << "p9: " << p9->toString() << endl;

//     // Point2D *p10;
//     // p10 = &p1;
//     // cout << "p10: " << p10->toString() << endl;

//     // Point2D p11[3];
//     // for(int i = 0; i < 3; i++){
//     //     cout << p11[i].toString() << endl;
//     // }

//     // Point2D *p12;
//     // p12 = new Point2D[3];
//     // for(int i = 0; i < 3; i++){
//     //     cout << p12[i].toString() << endl;
//     // }

//     return 0;
// }

// f1: O(logn)
// copy tham số: O(n)
// void f1(Point2D p); => bản sao; 
// void f2(const Point2D& p); => cùng object

int main(){
    // Triangle t1(Point2D(0, 0), Point2D(0, 3), Point2D(4, 0));
    // cout << "t1: " << t1.toString() << endl;

    Triangle t2; // 0 0 0 1 1 0
    cout << "t2: " << t2.toString() << endl;
    return 0;
}