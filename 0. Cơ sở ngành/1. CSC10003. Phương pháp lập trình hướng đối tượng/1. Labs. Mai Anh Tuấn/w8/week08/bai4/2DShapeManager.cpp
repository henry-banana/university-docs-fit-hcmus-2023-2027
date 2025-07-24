#include "2DShapeManager.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Trapezium.h"
#include <fstream>
#include <iostream>

void ShapeManager::addShape(const std::shared_ptr<IShape>& shape) {
    if (shape) {
        _shapes.push_back(shape);
    }
}

void ShapeManager::addShapeFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << "\n";
        return;
    }

    while (file >> *this);
    file.close();
}

std::shared_ptr<IShape> ShapeManager::createShape(const std::string& type) {
    if (type == "hcn") {
        return std::make_shared<Rectangle>();
    } 
    else if (type == "htg") {
        return std::make_shared<Triangle>();
    } 
    else if (type == "htr") {
        return std::make_shared<Circle>();
    } 
    else if (type == "hthv") {
        return std::make_shared<Trapezium>();
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const ShapeManager& manager) {
    for (const auto& shape : manager._shapes) {
        os << *shape << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, ShapeManager& manager) {
    std::string type;
    std::getline(is, type, ':'); // Đọc kiểu hình từ dòng đầu tiên

    if (type.empty()) { // Nếu không có kiểu hình thì thoát
        return is;
    }

    std::shared_ptr<IShape> shape = manager.createShape(type); // Sử dụng factory

    if (shape) {
        is >> *shape; // Đọc thông tin hình từ dòng tiếp theo
        manager.addShape(shape);
        manager._shapeTypes[static_cast<int>(shape->getType())]++;
        manager._shapeAreas[static_cast<int>(shape->getType())] += shape->area();
        manager._shapePerimeters[static_cast<int>(shape->getType())] += shape->perimeter();
    }

    return is;
}

std::vector<std::shared_ptr<IShape>>::iterator ShapeManager::begin() {
    return _shapes.begin();
}

std::vector<std::shared_ptr<IShape>>::iterator ShapeManager::end() {
    return _shapes.end();
}

std::shared_ptr<IShape> ShapeManager::operator[](int index) const {
    if (index >= 0 && index < _shapes.size()) {
        return _shapes[index];
    }
    return nullptr;
}

void ShapeManager::displayAllShapeInfo() const {
    for (int i = 0; i < _shapeTypes.size(); ++i) {
        std::cout << "Shape Type: ";

        switch (i) {
            case 0: std::cout << "Rectangle"; break;
            case 1: std::cout << "Triangle"; break;
            case 2: std::cout << "Circle"; break;
            case 3: std::cout << "Trapezium"; break;
            default: std::cout << "Unknown"; break;
        }
        std::cout << "\n";

        std::cout << "Count: " << _shapeTypes.at(i) << "\n";
        std::cout << "Total Area: " << _shapeAreas.at(i) << "\n";
        std::cout << "Total Perimeter: " << _shapePerimeters.at(i) << "\n";
        
    }
}