#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

static const float PI = 3.14159265358979323846f; // Pi constant

class Circle : public IShape {
private:
    float _radius = 0.0f;
public:
    Circle() = default;
    Circle(float r);

    void setRadius(float r);
    float radius() const;

    float area() override;
    float perimeter() override;
    ShapeType getType() const override;

    void display(std::ostream& os) const override;
    void setData(std::istream& is) override;
};

#endif