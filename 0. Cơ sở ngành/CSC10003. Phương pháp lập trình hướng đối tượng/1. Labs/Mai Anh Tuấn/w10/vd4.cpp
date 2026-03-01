#include <iostream>
#include <cmath>
#include <exception>

class CA 
{
private:
    double _value;
    
public:
    CA(const double& v) { _value = v; }
    /// hàm minh họa gây lỗi
    double GetTest() 
    {
        return this->_value;
    }
};
/// không đổi

class Level1 
{
public:
    /// hàm minh họa thông báo lỗi theo cách quăng exception
    static double RunTest3(CA* pCA) 
    {
        if (pCA == nullptr) 
        {
            throw std::runtime_error("Argument must not be null");
        }
        double rs = pCA->GetTest();
        return sqrt(rs);
    }
};

int main() 
{
    std::cout << Level1::RunTest3(nullptr) << std::endl;
    return 0;
}