#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "IEmployee.h"

class Employee : public IEmployee {
private:
    std::string _name;
    std::string _location;
protected:
    virtual void readSpecificData(std::istream& is) = 0;
    virtual void displaySpecificData(std::ostream& os) const = 0;
public:
    Employee();
    Employee(const std::string& name, const std::string& location);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee() override;

    void setName(const std::string& name) override;
    const std::string name() const override;

    void setLocation(const std::string& location) override;
    const std::string location() const override;

    void readFromStream(std::istream& is) override;
    void display(std::ostream& os) const override;
};

#endif