// MSSV_N2.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
Note:
- Do not modify function prototypes or struct declarations.
- Insert your code in the specified locations indicated 
                                    by the comment '// YOUR CODE HERE'.
*/

// Helper function(s) (if needed)


// Problem 1
struct Film {
    string ID, title, producer;
    int length, views;
};

struct Node {
    Film data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};


// 1.1
void ReadList(string fileName, List &list) {
    // YOUR CODE HERE
}

void PrintList(List list) {
    // YOUR CODE HERE
}


// 1.2
void AddEpisode(List &list, Film newEp) {
    // YOUR CODE HERE
}


// 1.3
// Note: Only returning true or false WILL NOT earn points.
bool CheckContinuity(List list) {
    // YOUR CODE HERE
}


void Problem01() {
    cout << "Problem 01: \n";
    List list;
    list.pHead = nullptr;
    list.pTail = nullptr;

    cout << "\n1.1. The list: \n";
    ReadList("data.txt", list);
    PrintList(list);

    cout << "\n1.2. After adding an episodes: \n";
    Film newEp {"ST-004", "Stranger_Things_Season_1_Episode_4", "Netflix", 5610, 245678};
    if (list.pHead != nullptr)
        AddEpisode(list, newEp);
    PrintList(list);

    cout << "\n1.3. Can list be continuous?: ";
    cout << CheckContinuity(list);
}


// Problem 2
vector<string> GenerateBinStr(int n) {
    if (n == 0)
        return {""};
    if (n == 1)
        return {"0", "1"};

    vector<string> res, resOfSmallerN = GenerateBinStr(n - 1);
    for (int i = 0; i < resOfSmallerN.size(); i++) {
        string curStr = resOfSmallerN[i];
        string temp = curStr + '0';
        res.push_back(temp);
        if (curStr[curStr.length() - 1] != '1') {
            temp = curStr + '1';
            res.push_back(temp);
        }
    }
    return res;
}

void FindAllBinStr(int n) {
    vector<string> res = GenerateBinStr(n);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}

void Problem02() {
    cout << "\n\nProblem 02:";
    int n = 3;
    int countAsm = 0, countCmp = 0;

    cout << "\nAll possible binary strings of size " << n << " without consecutive 1s: ";
    // TODO: You must modify the following line to get the numbers of assignments and comparisons
    FindAllBinStr(n);

    // Print the numbers of assignments and comparisons
    cout << "\n- The number of assignments: " << countAsm;
    cout << "\n- The number of comparisons: " << countCmp;
}


/*
    Note: Only modify the main function if necessary for testing, 
                                        and then undo the changes.
*/
int main() {
    Problem01();
    Problem02();

    return 0;
}