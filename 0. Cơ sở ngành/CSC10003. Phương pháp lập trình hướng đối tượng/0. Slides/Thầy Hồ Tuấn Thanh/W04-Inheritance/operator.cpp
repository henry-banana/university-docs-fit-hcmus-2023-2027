#include <iostream>
#include <cstring>
using namespace std;
// A. Tuyên bố không sử dụng công cụ AI
// “Trong suốt quá trình thực hiện đồ án / bài tập, sinh viên không sử dụng bất kỳ công cụ AI
// dưới bất kỳ hình thức nào.”
class MyString
{
    char* pString;

public:
    size_t length() const
    {
        return pString ? strlen(pString) : 0;
    }

    MyString()
    {
        pString = new char[1];
        pString[0] = '\0';
    }

    MyString(const char* s)
    {
        if (s)
        {
            size_t n = strlen(s) + 1;
            pString = new char[n];
            strcpy(pString, s);
        }
        else
        {
            pString = new char[1];
            pString[0] = '\0';
        }
    }

    MyString(const MyString& s)
    {
        size_t n = s.length() + 1;
        pString = new char[n];
        strcpy(pString, s.pString);
    }

    MyString(MyString &&other) noexcept {
        pString = other.pString;
        other.pString = new char[1];
        other.pString[0] = '\0';
    }

    bool operator==(const MyString& other) const
    {
        return strcmp(pString, other.pString) == 0;
    }

    MyString& operator+=(const MyString& other)
    {
        if (!other.pString) return *this;
        size_t n = length();
        size_t m = other.length();
        char* temp = new char[n + m + 1];
        strcpy(temp, pString);
        strcat(temp, other.pString);
        delete[] pString;
        pString = temp;
        return *this;
    }

    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            delete[] pString;
            if (!other.pString)
            {
                pString = new char[1];
                pString[0] = '\0';
            }
            else
            {
                size_t n = other.length() + 1;
                pString = new char[n];
                strcpy(pString, other.pString);
            }
        }
        return *this;
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] pString; 
            if (!other.pString) {
                pString = new char[1];
                pString[0] = '\0';
            }
            else {
                pString = other.pString; 
                other.pString = new char[1];
                other.pString[0] = '\0';
            }
        }
        return *this; 
    }

    friend ostream& operator<<(ostream& os, const MyString& str)
    {
        os << str.pString;
        return os;
    }
    friend istream& operator>>(istream& is, MyString& str) {
        char tmp[101];
        // is.ignore(); // o Tuan Thanh
        is.getline(tmp,101);
        delete[] str.pString;
        str.pString = new char[strlen(tmp)+1];
        strcpy(str.pString,tmp);
        return is;
    }

    ~MyString()
    {
        delete[] pString;
    }
};



int main()
{
    // MyString s1("abc");
    // MyString s2("def");
    // cout << "s1 == s2: " << (s1 == s2 ? "True" : "False") << endl;
    // MyString s3("abc");
    // cout << "s1 == s3: " << (s1 == s3 ? "True" : "False") << endl;
    // s1 += s2;
    // cout << "s1 += s2: " << s1 << endl;
    
    // MyString s4;
    // s4 = s1;
    // cout << "s4: " << s4 << endl;
    // MyString s5(s2);
    // cout << "s5: " << s5 << endl;

    MyString s6;
    cin >> s6;
    cout << "s6: " << s6 << endl;

    MyString s7 = move(s6);
    cout << "s7: " << s7 << endl;
    cout << "s6: " << s6 << endl;

    MyString s8;
    s8 = move(s7);
    cout << "s8: " << s8 << endl;
    cout << "s7: " << s7 << endl;
    return 0;
}
