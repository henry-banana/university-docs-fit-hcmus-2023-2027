#include "Triangle.h"
#include <iostream>
#include <string>
#include <cmath>

Triangle::Triangle(float b1, float b2, float b3) : _base1(b1), _base2(b2), _base3(b3) {}

void Triangle::setBase1(float b1) {
    _base1 = b1;
}

float Triangle::base1() const {
    return _base1;
}

void Triangle::setBase2(float b2) {
    _base2 = b2;
}

float Triangle::base2() const {
    return _base2;
}

void Triangle::setBase3(float b3) {
    _base3 = b3;
}

float Triangle::base3() const {
    return _base3;
}

float Triangle::area() {
    float s = perimeter() / 2;
    return sqrt(s * (s - _base1) * (s - _base2) * (s - _base3));
}

float Triangle::perimeter() {
    return _base1 + _base2 + _base3;
}

ShapeType Triangle::getType() const {
    return ShapeType::Triangle;
}

void Triangle::display(std::ostream& os) const {
    os << "Triangle: Base1 = " << _base1 << ", Base2 = " << _base2 << ", Base3 = " << _base3;
}

void Triangle::setData(std::istream& is) {
    std::string line;
    std::getline(is, line, ',');
    _base1 = std::stof(line);
    std::getline(is, line, ',');
    _base2 = std::stof(line);
    std::getline(is, line, '\n');
    _base3 = std::stof(line);
}