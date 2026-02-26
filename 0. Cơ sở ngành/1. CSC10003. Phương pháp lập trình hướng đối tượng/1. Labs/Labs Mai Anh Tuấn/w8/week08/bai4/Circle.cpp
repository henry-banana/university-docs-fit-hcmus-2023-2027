#include "Circle.h"
#include <iostream>
#include <string>
#include <cmath>

Circle::Circle(float r) : _radius(r) {}

void Circle::setRadius(float r) {
    _radius = r;
}

float Circle::radius() const {
    return _radius;
}

float Circle::area() {
    return PI * _radius * _radius;
}

float Circle::perimeter() {
    return 2 * PI * _radius;
}

ShapeType Circle::getType() const {
    return ShapeType::Circle;
}

void Circle::display(std::ostream& os) const {
    os << "Circle: Radius = " << _radius;
}

void Circle::setData(std::istream& is) {
    std::string line;
    std::getline(is, line, '\n');
    _radius = std::stof(line);
}