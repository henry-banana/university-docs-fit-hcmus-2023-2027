#include "Company.h"
#include <iostream>
#include <fstream>


int main() {
    Company company;
    company.readEmployeeListFromFile("input.txt");

    std::cout << "All Employees:\n";
    std::cout << company;

    std::cout << "\nOutstanding Employees:\n";
    company.showOutstandingEmployees();

    return 0;
}