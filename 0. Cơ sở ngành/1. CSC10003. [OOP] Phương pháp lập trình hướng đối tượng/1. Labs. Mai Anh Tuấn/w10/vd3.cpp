#include <iostream>
#include <cmath>

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
/// không đổi
{
public:
    // Hàm từ ví dụ 2 - xử lý lỗi bằng giá trị trả về
    static double RunTest2(CA* pCA) 
    {
        if (pCA == nullptr) 
        {
            return -1; // Trả về -1 để báo lỗi
        }
        double rs = pCA->GetTest();
        return sqrt(rs);
    }
};

class Level2 
{
public:
    /// hàm minh họa xử lý lỗi dựa vào giá trị trả về
    static double RunTest1() 
    {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest2(pCA);
        if (dRS == -1) 
        {
            return -1;  // Chuyển lỗi lên cao hơn
        }
        return sqrt(dRS);
    }
};

int main() 
{
    std::cout << Level2::RunTest1() << std::endl;
    return 0;
}