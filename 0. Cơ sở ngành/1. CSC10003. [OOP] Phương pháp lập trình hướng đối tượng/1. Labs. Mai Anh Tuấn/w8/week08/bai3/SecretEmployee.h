#ifndef SECRETEMPLOYEE_H
#define SECRETEMPLOYEE_H
#include "Employee.h"

class SecretEmployee : public Employee {
private:
    std::string _languageCertification;
    int _totalReports;
public:
    SecretEmployee();
    SecretEmployee(const std::string& name, const std::string& location, const std::string& languageCertification, int totalReports);
    SecretEmployee(const SecretEmployee& other);
    SecretEmployee& operator=(const SecretEmployee& other);
    ~SecretEmployee() override;

    void setLanguageCertification(const std::string& languageCertification);
    const std::string languageCertification() const;

    void setTotalReports(int totalReports);
    int totalReports() const;

    bool isOutstanding() const override;protected:
    
    void readSpecificData(std::istream& is) override;
    void displaySpecificData(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const SecretEmployee& secretEmployee);
    friend std::istream& operator>>(std::istream& is, SecretEmployee& secretEmployee);
};

#endif