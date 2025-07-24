#ifndef IEMPLOYEE_H
#define IEMPLOYEE_H

#include <string>

class IEmployee {
public:
    virtual ~IEmployee() = default;

    virtual void setName(const std::string& name) = 0;
    virtual const std::string name() const = 0;

    virtual void setLocation(const std::string& location) = 0;
    virtual const std::string location() const = 0;

    virtual void readFromStream(std::istream& is) = 0;
    virtual void display(std::ostream& os) const = 0;
    virtual bool isOutstanding() const = 0;
};

std::istream& operator>>(std::istream& is, IEmployee& employee);
std::ostream& operator<<(std::ostream& os, const IEmployee& employee);

#endif