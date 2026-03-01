#include "LinkedList.h"
#include <random>
#include <ctime>

int main() {
    srand((unsigned int)time(0));
    const int maxV = 1000, iTest = 2;
    int n = 5 + rand() % 10;
    LinkedList<int> ll;

    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) {
            ll.AddHead(rand() % maxV);
        } else {
            ll.AddTail(rand() % maxV + maxV);
        }
    }

    std::cout << ll << "\n";
    ll[iTest] = -123;
    ll[iTest + 2] = 9876;
    ll.RemoveHead();
    ll.RemoveTail();
    std::cout << "Sau thay doi: " << "\n";
    std::cout << ll << "\n";

    LinkedList<CString> llCS;
    llCS.AddTail(CString("cstring-1"));
    llCS.AddTail(CString("cstring-2"));
    llCS.AddTail(CString("cstring-3"));

    std::cout << "List CString: " << llCS << "\n";
    llCS[iTest] = CString("new CString");
    std::cout << "List CString changed:\n" << llCS << "\n";

    return 0;
}