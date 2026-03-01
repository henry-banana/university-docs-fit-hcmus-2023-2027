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
/// không đổi

class Level2 
{
public:
    /// hàm minh họa bỏ qua xử lý lỗi, để tầng cao hơn xử lý
    static double RunTest2() 
    {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest3(pCA);  // Exception sẽ được throw ra từ đây
        return sqrt(dRS);
    }
};

int main() 
{
    try 
    {
        std::cout << Level2::RunTest2() << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cout << "error: " << ex.what() << std::endl;
    }
    
    return 0;
}