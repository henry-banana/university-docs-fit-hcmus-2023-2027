#ifndef TECHEMPLOYEE_H
#define TECHEMPLOYEE_H
#include "Employee.h"

class TechEmployee : public Employee {
private:
    std::string _specializedCertification;
    int _totalIdeas;
public:
    TechEmployee();
    TechEmployee(const std::string& name, const std::string& location, const std::string& certification, int totalIdeas);
    TechEmployee(const TechEmployee& other);
    TechEmployee& operator=(const TechEmployee& other);
    ~TechEmployee() override;

    void setCertification(const std::string& certification);
    const std::string certification() const;

    void setTotalIdeas(int totalIdeas);
    int totalIdeas() const;

    bool isOutstanding() const override;

    friend std::ostream& operator<<(std::ostream& os, const TechEmployee& techEmployee);
    friend std::istream& operator>>(std::istream& is, TechEmployee& techEmployee);

    void readSpecificData(std::istream& is) override;
    void displaySpecificData(std::ostream& os) const override;
};

#endif