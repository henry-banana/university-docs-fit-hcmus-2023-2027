#include "Point2D.h"

Point2D::Point2D(double x, double y) {
    cout << "Point2D cons 2 args" << endl;
    this->x = x;
    this->y = y;
}

Point2D::Point2D(double a) { 
    cout << "Point2D cons 1 arg" << endl;
    x = a;
    y = a;
}

Point2D::Point2D(){
    cout << "Point2D default cons" << endl;
    this->x = 0;
    this->y = 0;
}
Point2D::Point2D(const Point2D &a) {
    cout << "Point2D copy cons" << endl;
    this->x = a.x;
    this->y = a.y;
}

string Point2D::toString(){
    return "x = " + to_string(x) + " y = " + to_string(y);
}

// d(p4, p5): Point2D copy cons
// Point2D distance
// 5
double Point2D::distance1(Point2D a){
    cout << "Point2D distance" << endl;
    double dx = (x - a.x) * (x - a.x);
    double dy = (y - a.y) * (y - a.y);
    return sqrt(dx + dy);
}

// d(p4, p5): Point2D distance
// 5
double Point2D::distance2(const Point2D& a){
    cout << "Point2D distance" << endl;
    double dx = (x - a.x) * (x - a.x);
    double dy = (y - a.y) * (y - a.y);
    return sqrt(dx + dy);
}

Point2D::~Point2D(){
    cout << "Point2D des" << endl;
}


// Triangle::Triangle(Point2D p1, Point2D p2, Point2D p3){
//     cout << "Triangle cons 3 args" << endl;
//     a = p1;
//     b = p2;
//     c = p3;
// }

// Triangle::Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3){
//     cout << "Triangle cons 3 args" << endl;
//     a = p1;
//     b = p2;
//     c = p3;
// }

Triangle::Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3)
    :a(p1), b(p2), c(p3) {
    cout << "Triangle cons 3 args" << endl;
}

// Triangle::Triangle() {
//     cout << "Triangle default cons" << endl;
//     a = Point2D(0,0);
//     b = Point2D(0,1);
//     c = Point2D(1,0);
// }

// Triangle::Triangle() {
//     cout << "Triangle default cons" << endl;
//     Point2D p1(0,0);
//     Point2D p2(0,1);
//     Point2D p3(1,0);
//     a = p1;
//     b = p2;
//     c = p3;
// }

Triangle::Triangle(): a(0, 0), b(0, 1), c(1, 0) {
    cout << "Triangle default cons" << endl;
}

string Triangle::toString(){
    string s = "";
    s += "A => " + a.toString() + ";";
    s += "B => " + b.toString() + ";";
    s += "C => " + c.toString();
    return s;
}

Triangle::~Triangle(){
    cout << "Triangle des" << endl;
}