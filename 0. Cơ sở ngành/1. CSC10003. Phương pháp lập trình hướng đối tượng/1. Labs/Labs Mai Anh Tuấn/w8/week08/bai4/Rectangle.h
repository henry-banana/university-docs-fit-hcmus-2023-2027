#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape {
private:
    float _width = 0.0f;
    float _height = 0.0f;
public:
    Rectangle() = default;
    Rectangle(float w, float h);

    void setWidth(float w);
    float width() const;

    void setHeight(float h);
    float height() const;

    float area() override;
    float perimeter() override;
    ShapeType getType() const override;

    void display(std::ostream& os) const override;
    void setData(std::istream& is) override;
};

#endif