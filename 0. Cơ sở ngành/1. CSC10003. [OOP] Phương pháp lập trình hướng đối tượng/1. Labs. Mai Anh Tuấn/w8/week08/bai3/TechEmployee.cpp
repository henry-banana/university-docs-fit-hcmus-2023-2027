#include <iostream>
#include <string>
#include "TechEmployee.h"

TechEmployee::TechEmployee() 
    : Employee(), 
      _specializedCertification("Unknown"), 
      _totalIdeas(0) {}

TechEmployee::TechEmployee(const std::string& name, const std::string& location, const std::string& certification, int totalIdeas) 
    : Employee(name, location), 
      _specializedCertification(certification), 
      _totalIdeas(totalIdeas) {}

TechEmployee::TechEmployee(const TechEmployee& other) 
    : Employee(other), 
      _specializedCertification(other._specializedCertification), 
      _totalIdeas(other._totalIdeas) {}

TechEmployee& TechEmployee::operator=(const TechEmployee& other) {
    if (this != &other) {
        Employee::operator=(other);
        _specializedCertification = other._specializedCertification;
        _totalIdeas = other._totalIdeas;
    }
    return *this;
}


TechEmployee::~TechEmployee() {
    // Destructor implementation
}

void TechEmployee::setCertification(const std::string& certification) {
    _specializedCertification = certification;
}

const std::string TechEmployee::certification() const {
    return _specializedCertification;
}


void TechEmployee::setTotalIdeas(int totalIdeas) {
    _totalIdeas = totalIdeas;
}

int TechEmployee::totalIdeas() const {
    return _totalIdeas;
}

void TechEmployee::readSpecificData(std::istream& is) {
    std::string temp;
    
    std::getline(is, temp, '['); 
    std::getline(is, _specializedCertification, ']');
    std::getline(is, temp, '<'); 
    std::getline(is, temp, '>');
    if (!temp.empty()) {
      _totalIdeas = std::stoi(temp);
    } else {
      _totalIdeas = 0; 
    }
    std::getline(is, temp); 
}

void TechEmployee::displaySpecificData(std::ostream& os) const {
    os << " [" << _specializedCertification << "] <" << _totalIdeas << ">";
}

bool TechEmployee::isOutstanding() const {
    return _totalIdeas >= 6;
}