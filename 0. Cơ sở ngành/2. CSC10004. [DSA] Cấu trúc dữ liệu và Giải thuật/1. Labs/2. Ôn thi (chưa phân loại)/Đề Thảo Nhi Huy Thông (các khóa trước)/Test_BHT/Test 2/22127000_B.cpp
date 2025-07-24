#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

struct Employee {
    int id;
    int workingdays;
    int workinghours;
};
struct NodeEm{
    Employee em;
    NodeEm *next;
};
struct ListEm{
    NodeEm *head;
    NodeEm *tail;
};

void readfile(string filename, int** &matrix, int &m, int &n, int &number, int &alpha, ListEm &list_ems){
    /* TODO: Đọc dữ liệu từ file có tên filename, với định dạng sau (xem data.txt để biết thêm chi tiết):
    m n
    matrix[0][0] matrix[0][1] ... matrix[0][n-1]
    ...
    matrix[m-1][0] matrix[m-1][1] ... matrix[m-1][n-1]
    // Enter xuống dòng
    number alpha
    // Enter xuống dòng
    MSNV ngày_đi_làm giờ_đi_làm giờ_ra_về
    MSNV ngày_đi_làm giờ_đi_làm giờ_ra_về
    ...
    => TODO1: Lưu dữ liệu về ma trận vào các biến tương ứng: matrix, m, n 
    Sinh viên tự tạo ma trận (new int) trong hàm readfile này
    => TODO2: Lưu dữ liệu về 2 biến alpha + number
    => TODO3: Lưu dữ liệu về nhân viên vào biến: list_ems
    Mỗi nhân viên (node) được lưu 3 thông tin: ID, tổng số ngày nhân viên đã đi làm, tổng số thời gian đã làm
    */

}

int*** solution_ex1(int** matrix, int m, int n, int &d1, int &d2, int &d3){
    /* TODO: Cho ma trận matrix kích thước m x n
    Gọi p và q lần lượt là các ước nhỏ nhất lớn hơn 1 của m và n
    Viết hàm phân rã ma trận matrix thành ma trận 3 chiều chứa các ma trận con kích thước p x q của matrix
    */
    
}

void solution_ex2(ListEm& list_ems, int number, int alpha){
    /* TODO: Những nhân viên có số ngày đi làm < number và số giờ đi làm < alpha sẽ bị đuổi việc.
    Hãy xoá những nhân viên đã bị đuổi ra khỏi danh sách list_ems
    */ 
    
}


void main_debug(){
    // Main function for student 

}












// DO NOT CHANGE ANYTHING FROM HERE
void printscore1(int** matrix, int m, int n){
    cout << "matrix2d:";
    if (m == 0 || n == 0) {
        cout << "null\n"; return;
    }
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " ";
    }
    cout << "\n";
}
void printscore2(ListEm list_ems){
    cout << "linkedlist:";
    if (list_ems.head == NULL) {
        cout << "null\n"; return;
    }
    for (NodeEm *head = list_ems.head; head != NULL; head = head->next){
        cout << head->em.id << " " << head->em.workingdays << " " << head->em.workinghours << " ";
    }
    cout << "\n";
}
void printscore3(int*** matrix, int d1, int d2, int d3){
    cout << "matrix3d:";
    if (d1 == 0 || d2 == 0 || d3 == 0){
        cout << "null\n"; return;
    }
    for(int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            for (int k = 0; k < d3; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << " ";
    }
    cout << "\n";
}
void deleverything(int** &matrix2d, int m, int n, int*** &matrix3d, int d1, int d2, int d3, ListEm &list_ems){
    if(m != 0) {
        for (int i = 0; i < m ; i++) {
            delete[] matrix2d[i];
        }
        delete[] matrix2d;
    }
    if (d1 != 0) {
        for (int i = 0; i < d1; i++) {
            if (d2 != 0) {
                for (int j = 0; j < d2; j++) {
                    delete[] matrix3d[i][j];
                }
                delete[] matrix3d[i];
            }
        }
        delete[] matrix3d;
    }
    for (NodeEm *head = list_ems.head; list_ems.head != NULL; head = list_ems.head) {
        list_ems.head = head->next;
        delete head;
        head = NULL;
    }
}
int main(int argc, char **argv){
    if (argc == 1) {
        main_debug();
    }
    else {
        int idx_argv = 1;
        string filename = argv[idx_argv++];

        int** matrix; int*** result;
        int m = 0, n = 0, d1 = 0, d2 = 0, d3 = 0, number = 0, alpha = 0;
        ListEm list_ems; list_ems.head = NULL;
        readfile(filename, matrix, m, n, number, alpha, list_ems);
        printscore1(matrix, m, n);
        printscore2(list_ems);
        result = solution_ex1(matrix, m, n, d1, d2, d3);
        printscore3(result, d1, d2, d3);
        solution_ex2(list_ems, number, alpha);
        printscore2(list_ems);

        deleverything(matrix, m, n, result, d1, d2, d3, list_ems);
    }
    return 0;
}
