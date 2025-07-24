#ifndef _2DSHAPEMANAGER_H
#define _2DSHAPEMANAGER_H

#include "IShape.h"

#include <string>
#include <vector>
#include <memory>
#include <map>

class ShapeManager {
private:
    std::vector<std::shared_ptr<IShape>> _shapes;
    std::map<int, int> _shapeTypes; // <index, count>
    std::map<int, float> _shapeAreas; // <index, area>
    std::map<int, float> _shapePerimeters; // <index, perimeter>
public:
    ShapeManager() = default;
    ~ShapeManager() = default;
    
    void addShape(const std::shared_ptr<IShape>& shape);
    void addShapeFromFile(const std::string& filename);
    std::shared_ptr<IShape> createShape(const std::string& type);
    void displayAllShapeInfo() const;

    std::vector<std::shared_ptr<IShape>>::iterator begin();
    std::vector<std::shared_ptr<IShape>>::iterator end();

    std::shared_ptr<IShape> operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const ShapeManager& manager);
    friend std::istream& operator>>(std::istream& is, ShapeManager& manager);
};

#endif