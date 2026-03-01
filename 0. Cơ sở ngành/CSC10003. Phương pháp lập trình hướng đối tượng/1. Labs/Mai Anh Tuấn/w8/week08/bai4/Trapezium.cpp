#include "Trapezium.h"
#include <iostream>
#include <string>
#include <cmath>

Trapezium::Trapezium(float b1, float b2, float h) : _base1(b1), _base2(b2), _height(h) {}

void Trapezium::setBase1(float b1) {
    _base1 = b1;
}

float Trapezium::base1() const {
    return _base1;
}

void Trapezium::setBase2(float b2) {
    _base2 = b2;
}

float Trapezium::base2() const {
    return _base2;
}

void Trapezium::setHeight(float h) {
    _height = h;
}

float Trapezium::height() const {
    return _height;
}

float Trapezium::area() {
    return ((_base1 + _base2) * _height) / 2;
}

float Trapezium::perimeter() {
    return _base1 + _base2 + 2 * sqrt(pow((_base1 - _base2) / 2, 2) + pow(_height, 2));
}

ShapeType Trapezium::getType() const {
    return ShapeType::Trapezium;
}

void Trapezium::display(std::ostream& os) const {
    os << "Trapezium: Base1 = " << _base1 << ", Base2 = " << _base2 << ", Height = " << _height;
}

void Trapezium::setData(std::istream& is) {
    std::string line;
    std::getline(is, line, ',');
    _base1 = std::stof(line);
    std::getline(is, line, ',');
    _base2 = std::stof(line);
    std::getline(is, line, '\n');
    _height = std::stof(line);
}