#include "Rectangle.h"
#include <iostream>
#include <string>

Rectangle::Rectangle(float w, float h) : _width(w), _height(h) {}

void Rectangle::setWidth(float w) {
    _width = w;
}

float Rectangle::width() const {
    return _width;
}

void Rectangle::setHeight(float h) {
    _height = h;
}

float Rectangle::height() const {
    return _height;
}

float Rectangle::area() {
    return _width * _height;
}

float Rectangle::perimeter() {
    return 2 * (_width + _height);
}

ShapeType Rectangle::getType() const {
    return ShapeType::Rectangle;
}

void Rectangle::display(std::ostream& os) const {
    os << "Rectangle: Width = " << _width << ", Height = " << _height;
}

void Rectangle::setData(std::istream& is) {
    std::string line;
    std::getline(is, line, ',');
    _width = std::stof(line);
    std::getline(is, line, '\n');
    _height = std::stof(line);
}