#include <iostream>
#include <cmath>

class CA 
{
private:
    double _value;
    
public:
    CA(const double& v) { _value = v; }
    // hàm minh họa gây lỗi
    
    double GetTest() 
    {
        return this->_value;
    }
};

class Level1 
{
public:
    /// hàm minh họa chạy không kiểm soát lỗi có thể xảy ra
    static double RunTest1(CA* pCA) 
    {
        double rs = pCA->GetTest();  // Lỗi xảy ra ở đây khi pCA = nullptr
        return sqrt(rs);
    }
};

int main() 
{
    std::cout << Level1::RunTest1(nullptr) << std::endl;
    return 0;
}