#ifndef _POINT_2D_H_
#define _POINT_2D_H_
#include<iostream>
#include<string>
using namespace std;

class Point2D{
    double x, y;
public:
    Point2D(double x, double y);
    Point2D(double a);
    Point2D();
    Point2D(const Point2D &a);
    string toString();
    double distance1(Point2D a);
    double distance2(const Point2D& a);
    ~Point2D();
};

class Triangle {
    Point2D a, b, c;
public:
    // Triangle(Point2D p1, Point2D p2, Point2D p3);
    Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3);
    string toString();
    ~Triangle();
    Triangle();
};

#endif