#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "IShape.h"

class Trapezium : public IShape {
private:
    float _base1 = 0.0f;
    float _base2 = 0.0f;
    float _height = 0.0f;
public:
    Trapezium() = default;
    Trapezium(float b1, float b2, float h);

    void setBase1(float b1);
    float base1() const;

    void setBase2(float b2);
    float base2() const;

    void setHeight(float h);
    float height() const;

    float area() override;
    float perimeter() override;
    ShapeType getType() const override;

    void display(std::ostream& os) const override;
    void setData(std::istream& is) override;
};

#endif