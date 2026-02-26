#include "Company.h"
#include "Employee.h"
#include "IEmployee.h"
#include "TechEmployee.h"
#include "SecretEmployee.h"
#include <iostream>
#include <fstream>

Company::Company() {}

Company::~Company() {
    _employees.clear();
}

void Company::addEmployee(const std::shared_ptr<IEmployee>& employee) {
    if (employee) { 
        _employees.push_back(employee);
        if (employee->isOutstanding()) { 
            _outstandingEmployees.push_back(employee);
        }
    }
}

void Company::showAllEmployees() const {
    for (const auto& employee : _employees) {
        std::cout << *employee << "\n";
    }
}

void Company::showOutstandingEmployees() const {
    for (const auto& employee : _outstandingEmployees) {
        std::cout << *employee << "\n";
    }
}

void Company::readEmployeeListFromFile(std::string filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << "\n";
        return;
    }

    while (file >> *this);
}

std::ostream& operator<<(std::ostream& os, const Company& company) {
    company.showAllEmployees();
    return os;
}

std::istream& operator>>(std::istream& is, Company& company) {
    std::string type;
    std::getline(is, type, ':'); 
    
    if (type.empty()) { 
        return is;
    }

    std::shared_ptr<IEmployee> employee = company.createEmployeeByType(type); // Sử dụng factory

    if (employee) {
        is >> *employee; 
        
        if (is.fail() && !is.eof()){ 
            std::cerr << "Error parsing data for employee type: " << type << "\n";
            is.clear(); 
        } else {
            company.addEmployee(employee);
        }
    } else {
        std::string dummy;
        std::getline(is, dummy); 
    }

    return is;
}

std::shared_ptr<IEmployee> Company::createEmployeeByType(const std::string& type) {
    if (type == "nvkt") {
        return std::make_shared<TechEmployee>();
    } else if (type == "nvtk") {
        return std::make_shared<SecretEmployee>();
    }
    std::cerr << "Unknown employee type in factory: " << type << "\n";
    return nullptr;
}