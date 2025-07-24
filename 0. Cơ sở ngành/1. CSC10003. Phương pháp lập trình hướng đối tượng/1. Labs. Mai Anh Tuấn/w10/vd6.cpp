#include <iostream>
#include <cmath>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

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

/// tao custom exception bằng cách dẫn xuất
class MyException : public exception
{
private:
    string _errorDescription;
    int _errorCode;
    string _fullMessage;  // Lưu message để tránh memory leak
    
public:
    /// hàm khởi tạo có tạo message cho base
    MyException(const int& errCode, const string& errDes) 
    {
        _errorCode = errCode;
        _errorDescription = errDes;
        _fullMessage = BuildErrorMessage(errCode, errDes);
    }
    
    const string& GetErrorDescription() const
    {
        return _errorDescription;
    }
    
    const int& GetErrorCode() const
    {
        return _errorCode;
    }
    
    // Override what() để trả về message
    const char* what() const noexcept override
    {
        return _fullMessage.c_str();
    }
    
private:
    static string BuildErrorMessage(const int& errCode, const string& errDes)
    {
        ostringstream oss;
        oss << "Error code: " << errCode;
        oss << " - Description: " << errDes;
        return oss.str();
    }
};

class Level1 
{
public:
    /// hàm minh họa thông báo lỗi theo cách quăng custom exception
    static double RunTest4(CA* pCA) 
    {
        if (pCA == nullptr) 
        {
            throw MyException(123, "Argument must not be null");
        }
        double rs = pCA->GetTest();
        return sqrt(rs);
    }
};

class Level2 
{
public:
    /// hàm minh họa gọi hàm tạo ra custom exception
    static double RunTest3() 
    {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest4(pCA);
        return sqrt(dRS);
    }
    
    /// hàm minh họa quăng exception
    static void RunErr() 
    {
        throw exception();
    }
};

int main() 
{
    for (int i = 0; i < 2; i++) 
    {
        cout << "******************************************" << endl;
        try 
        {
            if (i == 0) 
            {
                cout << Level2::RunTest3() << endl;
            }
            else 
            {
                Level2::RunErr();
            }
        }
        catch (const MyException& me) 
        {
            cout << "custom error: " << me.what() << endl;
        }
        catch (const exception& ex) 
        {
            cout << "common error: " << ex.what() << endl;
        }
    }
    
    return 0;
}