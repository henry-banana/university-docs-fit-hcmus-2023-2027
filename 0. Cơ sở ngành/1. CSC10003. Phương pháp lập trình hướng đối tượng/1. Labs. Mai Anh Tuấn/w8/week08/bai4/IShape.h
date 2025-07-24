#ifndef ISHAPE_H
#define ISHAPE_H

#include <string>

enum class ShapeType {
    Rectangle,
    Triangle,
    Circle,
    Trapezium,
    Unknown
};

class IShape {
public:
    virtual ~IShape() = default;
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void display(std::ostream& os) const = 0;
    virtual void setData(std::istream& is) = 0;
    virtual ShapeType getType() const = 0;

};

inline std::ostream& operator<<(std::ostream& os, const IShape& shape) {
    shape.display(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, IShape& shape) {
    shape.setData(is);
    return is;
}

#endif