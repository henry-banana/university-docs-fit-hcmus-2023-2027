#include <iostream>
#include <vector>

class MyString {
private:
    std::vector<char> _str;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& s);
    ~MyString();

    std::vector<MyString> Split(const std::vector<char>& arrChar, bool removeEmpty);

    MyString& operator=(const MyString& s);
    MyString operator+(const MyString& s);
    MyString operator+(const char* s);

    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    friend MyString operator+(const char* c, const MyString& s);
};

// ==========================================

int main() {
    MyString ms1("abcdsf");
    MyString ms2 = "____" + ms1;
    MyString ms3 = ms1 + ms2;

    std::cout << "ms1= " << ms1 << "\n";
    std::cout << "ms2= " << ms2 << "\n";
    std::cout << "ms3= " << ms3 << "\n\n";


    MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
    std::vector<char> arrChar;
    arrChar.push_back(',');
    arrChar.push_back('.');
    arrChar.push_back(';');
    std::vector<MyString> vMs = ms.Split(arrChar, false);
    std::cout << "Split:\n";

    for (std::vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); ++itMS) {
        std::cout << *itMS << " ";
    }

    std::cout << "\nsize= " << vMs.size() << "\n\n";
    vMs = ms.Split(arrChar, true);
    std::cout << "Split co loai bo empty:\n";

    for (std::vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); ++itMS) {
        std::cout << *itMS << " ";
    }

    std::cout << "\nsize= " << vMs.size() << "\n\n";
    return 0;
}

// ==========================================

MyString::MyString() {
    _str.clear();
}

MyString::MyString(const char* s) {
    _str.clear();
    if (s == nullptr) {
        _str.push_back('\0');
        return;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        _str.push_back(s[i]);
    }
}

MyString::MyString(const MyString& s) {
    _str.clear();
    for (int i = 0; i < s._str.size(); i++) {
        _str.push_back(s._str[i]);
    }
}

MyString::~MyString() {
    _str.clear();
}


std::vector<MyString> MyString::Split(const std::vector<char>& arrChar, bool removeEmpty) {
    std::vector<MyString> result;
    MyString current;

    for (int i = 0; i < _str.size(); i++) {
        bool isDelimiter = false;

        for (char c : arrChar) {
            if (_str[i] == c) {
                isDelimiter = true;
                break;
            }
        }

        if (isDelimiter) {
            if (!removeEmpty || current._str.size() > 0) {
                result.push_back(current);
                current._str.clear();
            }
        } else {
            current._str.push_back(_str[i]);
        }
    }

    if (!removeEmpty || current._str.size() > 0) {
        result.push_back(current);
    }

    return result;
}


MyString& MyString::operator=(const MyString& s) {
    if (this == &s) {
        return *this;
    }

    _str.clear();
    
    for (int i = 0; i < s._str.size(); i++) {
        _str.push_back(s._str[i]);
    }

    return *this;
}

MyString MyString::operator+(const MyString& s) {
    MyString result;

    for (int i = 0; i < _str.size(); i++) {
        result._str.push_back(_str[i]);
    }
    
    for (int i = 0; i < s._str.size(); i++) {
        result._str.push_back(s._str[i]);
    }

    return result;
}

MyString MyString::operator+(const char* s) {
    MyString result;

    for (int i = 0; i < _str.size(); i++) {
        result._str.push_back(_str[i]);
    }
    
    for (int i = 0; s[i] != '\0'; i++) {
        result._str.push_back(s[i]);
    }

    return result;
}


std::ostream& operator<<(std::ostream& os, const MyString& s) {
    for (int i = 0; i < s._str.size(); i++) {
        os << s._str[i];
    }

    return os;
}

MyString operator+(const char* c, const MyString& s) {
    MyString result;
    
    for (int i = 0; c[i] != '\0'; i++) {
        result._str.push_back(c[i]);
    }

    for (int i = 0; i < s._str.size(); i++) {
        result._str.push_back(s._str[i]);
    }

    return result;  
}
