// <MSSV>.cpp
#include <iostream>

// Include cac thu vien
using namespace std;

// Khai bao cac struct
struct NODE {
    string ID;
    int year;
    int views;
    int length;
    string name;
    NODE* pNext;
};

struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

// Cac ham ho tro (neu co)

// Bai lam
// Bai 01-----------------------------------------------------------------------
// Cac ham lien quan den bai 01 (neu co)

void Bai01()
{
    // Noi dung bai 01
}

// Bai 02-----------------------------------------------------------------------
int findLenLPS(string str) {
    int n = str.length();
    int start = 0, end = 1, low, hi;

    for (int i = 0; i < n; i++) {
        low = i - 1;
        hi = i;
        while (low >= 0 && hi < n && str[low] == str[hi]) {
            if (hi - low + 1 > end) {
                start = low;
                end = hi - low + 1;
            }
            low--;
            hi++;
        }

        low = i - 1;
        hi = i + 1;

        while (low >= 0 && hi < n && str[low] == str[hi]) {
            if (hi - low + 1 > end) {
                start = low;
                end = hi - low + 1;  
            }
            low--;
            hi++;
        }
    }
 
    return end;
}

void Bai02() {
    string str = "hello"; // Chuoi vi du, sinh vien co the thay doi de kiem tra
    cout << "Max len of the longest palindrome substring: " << findLenLPS(str);
    // In ra so phep gan, so phep so sanh
}

int main()
{
    // Comment cac bai chua thuc hien duoc
    Bai01();
    Bai02();

    return 0;
}