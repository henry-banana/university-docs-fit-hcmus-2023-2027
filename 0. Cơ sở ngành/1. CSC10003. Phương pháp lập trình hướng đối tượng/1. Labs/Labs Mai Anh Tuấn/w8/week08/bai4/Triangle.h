#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IShape.h"

class Triangle : public IShape {
private:
    float _base1 = 0.0f;
    float _base2 = 0.0f;
    float _base3 = 0.0f;
public:
    Triangle() = default;
    Triangle(float b1, float b2, float b3);

    void setBase1(float b1);
    float base1() const;

    void setBase2(float b2);
    float base2() const;

    void setBase3(float b3);
    float base3() const;

    float area() override;
    float perimeter() override;
    ShapeType getType() const override;

    void display(std::ostream& os) const override;
    void setData(std::istream& is) override;
};

#endif