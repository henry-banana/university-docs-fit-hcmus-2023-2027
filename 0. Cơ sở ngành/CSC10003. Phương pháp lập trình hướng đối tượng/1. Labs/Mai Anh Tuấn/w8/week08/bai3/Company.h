#ifndef COMPANY_H
#define COMPANY_H

#include "IEmployee.h"
#include <memory>
#include <vector>

class Company {
private:
    std::vector<std::shared_ptr<IEmployee>> _employees;
    std::vector<std::shared_ptr<IEmployee>> _outstandingEmployees;
public:
    Company();
    ~Company();

    void addEmployee(const std::shared_ptr<IEmployee>& employee);
    void showAllEmployees() const;
    void showOutstandingEmployees() const;
    void readEmployeeListFromFile(std::string filename);
    std::shared_ptr<IEmployee> createEmployeeByType(const std::string& type);

    friend std::ostream& operator<<(std::ostream& os, const Company& company);
    friend std::istream& operator>>(std::istream& is, Company& company);
};

#endif