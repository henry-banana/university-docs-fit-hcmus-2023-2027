#include <iostream>
#include <string>
#include "Employee.h"
#include "IEmployee.h"


Employee::Employee() {
    _name = "Unknown";
    _location = "Unknown";
}

Employee::Employee(const std::string& name, const std::string& location) {
    _name = name;
    _location = location;
}

Employee::Employee(const Employee& other) {
    _name = other._name;
    _location = other._location;
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        _name = other._name;
        _location = other._location;
    }
    return *this;
}

Employee::~Employee()  {
    // Destructor implementation
}

void Employee::setName(const std::string& name) {
    _name = name;    
}

const std::string Employee::name() const {
    return _name;
}


void Employee::setLocation(const std::string& location) {
    _location = location;
}

const std::string Employee::location() const {
    return _location;
}

void Employee::readFromStream(std::istream& is) {
    std::string line_part;
    std::getline(is, line_part, '(');
    
    if (!line_part.empty() && line_part.back() == ' ') {
        line_part.pop_back();
    
    }
    _name = line_part;

    std::getline(is, _location, ')');
    readSpecificData(is);
}

void Employee::display(std::ostream& os) const {
    os << _name << " (" << _location << ")";
    displaySpecificData(os);
}

std::istream& operator>>(std::istream& is, IEmployee& employee) {
    employee.readFromStream(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const IEmployee& employee) {
    employee.display(os);
    return os;
}