#include <iostream>
#include <cmath>

class CA 
{
private:
    double _value;
    
public:
    // Constructor nhận giá trị double
    CA(double value) : _value(value) {}
    
    // Getter method
    double GetTest() const 
    {
        return _value;
    }
};

class Level1 
{
public:
    // Hàm xử lý lỗi thông qua giá trị trả về
    static double RunTest2(CA* pCA) 
    {
        // Kiểm tra con trỏ null
        if (pCA == nullptr) 
        {
            return -1; // Trả về -1 để báo lỗi
        }
        
        // Nếu con trỏ hợp lệ, thực hiện tính toán
        double rs = pCA->GetTest();
        
        // Kiểm tra thêm giá trị âm (tùy chọn)
        if (rs < 0) 
        {
            return -1; // Trả về -1 nếu không thể tính căn bậc 2
        }
        
        return sqrt(rs);
    }
};

int main() 
{
    std::cout << "=== Vi du 2: Xu ly loi bang gia tri tra ve ===" << std::endl;
    
    // Test 1: Truyền nullptr
    std::cout << "\nTest 1 - Truyen nullptr:" << std::endl;
    double result1 = Level1::RunTest2(nullptr);
    if (result1 == -1) {
        std::cout << "Loi: Con tro null!" << std::endl;
    } else {
        std::cout << "Ket qua: " << result1 << std::endl;
    }
    
    // Test 2: Truyền object hợp lệ
    std::cout << "\nTest 2 - Truyen object hop le:" << std::endl;
    CA validObject(25.0);
    double result2 = Level1::RunTest2(&validObject);
    if (result2 == -1) {
        std::cout << "Loi xay ra!" << std::endl;
    } else {
        std::cout << "Ket qua: " << result2 << std::endl;
    }
    
    // Test 3: Truyền object với giá trị âm
    std::cout << "\nTest 3 - Truyen object voi gia tri am:" << std::endl;
    CA negativeObject(-16.0);
    double result3 = Level1::RunTest2(&negativeObject);
    if (result3 == -1) {
        std::cout << "Loi: Khong the tinh can bac 2 cua so am!" << std::endl;
    } else {
        std::cout << "Ket qua: " << result3 << std::endl;
    }
    
    // Test 4: So sánh với phương pháp gốc từ hình ảnh
    std::cout << "\n=== Test giong trong hinh anh ===" << std::endl;
    std::cout << "Level1::RunTest2(nullptr) = " << Level1::RunTest2(nullptr) << std::endl;

    return 0;
}