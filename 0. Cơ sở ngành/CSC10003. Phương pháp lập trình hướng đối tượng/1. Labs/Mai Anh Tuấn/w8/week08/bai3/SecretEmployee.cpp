#include "SecretEmployee.h"
#include <iostream>

SecretEmployee::SecretEmployee() 
    : Employee(), 
      _languageCertification("Unknown"), 
      _totalReports(0) {}

SecretEmployee::SecretEmployee(const std::string& name, const std::string& location, const std::string& languageCertification, int totalReports) 
    : Employee(name, location), 
      _languageCertification(languageCertification), 
      _totalReports(totalReports) {}

SecretEmployee::SecretEmployee(const SecretEmployee& other) 
    : Employee(other), 
      _languageCertification(other._languageCertification), 
      _totalReports(other._totalReports) {}

SecretEmployee& SecretEmployee::operator=(const SecretEmployee& other) {
    if (this != &other) {
        Employee::operator=(other);
        _languageCertification = other._languageCertification;
        _totalReports = other._totalReports;
    }
    return *this;
}

SecretEmployee::~SecretEmployee() {
    // Destructor implementation
}

void SecretEmployee::setLanguageCertification(const std::string& languageCertification) {
    _languageCertification = languageCertification;
}

const std::string SecretEmployee::languageCertification() const {
    return _languageCertification;
}

void SecretEmployee::setTotalReports(int totalReports) {
    _totalReports = totalReports;
}

int SecretEmployee::totalReports() const {
    return _totalReports;
}

void SecretEmployee::readSpecificData(std::istream& is) {
    std::string temp;
    
    std::getline(is, temp, '[');
    std::getline(is, _languageCertification, ']');
    std::getline(is, temp, '<');
    std::getline(is, temp, '>');
    
     if (!temp.empty()) {
      _totalReports = std::stoi(temp);
    } else {
      _totalReports = 0;
    }
    std::getline(is, temp);
}

void SecretEmployee::displaySpecificData(std::ostream& os) const {
    os << " [" << _languageCertification << "] <" << _totalReports << ">";
}

bool SecretEmployee::isOutstanding() const {
    return _totalReports >= 12;
}