#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
Note:
- Do not modify the definitions of structures or functions.
- Insert your code in the specified locations indicated 
                                    by the comment '// YOUR CODE HERE'.
*/

// Problem 1
struct Course {
    string courseID, courseName, department;
    int instructorID;
};


vector<Course> ReadData(string fileName) {
    vector<Course> res;

    // YOUR CODE HERE

    return res;
}

Course Search(vector<Course> listCourses, string idc) {

    // YOUR CODE HERE

    return Course {"NA", "NA", "NA", -1}; // Remove this line if you have your own return value.
}


// Problem 2
struct Node {
    int data;
    Node* pNext;
};

void removeHead(Node* &pHead) {

    // YOUR CODE HERE
}

// Problem 3
// Note: Only returning 0 or 1 WILL NOT earn points.
bool isX(int n, int m){

    // YOUR CODE HERE

    return 0; // Remove this line if you have your own return value.
}

/*
    Note: Only modify the main function if necessary for testing, 
                                        and then undo the changes.
*/
int main() {
    // Problem 1----------------------------------------------------
    cout << "Problem 1: \n";

    vector<Course> listCourses = ReadData("data_N2.txt");

    Course foundCourse = Search(listCourses, "CS401");

    cout << "Found course: " << foundCourse.courseID << " " << foundCourse.courseName 
                                    << " " << foundCourse.department << " " << foundCourse.instructorID << "\n";


    // Problem 2----------------------------------------------------
    cout << "\nProblem 2:\n";

    Node* pHead = new Node {1, nullptr};
    pHead->pNext = new Node {2, nullptr};
    pHead->pNext->pNext = new Node {3, nullptr};
    pHead->pNext->pNext->pNext = new Node {4, nullptr};

    removeHead(pHead);
    removeHead(pHead);

    Node* cur = pHead;
    while (cur != nullptr) {
        cout << cur->data << " -> ";
        cur = cur->pNext;
    }
    cout << "nullptr\n";


    // Problem 3----------------------------------------------------
    cout << "\nProblem 3:\n";

    int n = 1212, m = 4;
    cout << "isX(" << n << ", " << m << ") -> " << isX(n, m) << endl;

    return 0;
}