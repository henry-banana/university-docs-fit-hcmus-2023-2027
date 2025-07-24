#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct Flight {
    string src; // source 
    string des; // destination
    int hours; 
    int mins;
};
struct Node {
    Flight base;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};

void todo(string flightdata_filename, string data_filename);
void printmatrix2d(char** matrix, int d1, int d2);
void printmatrix3d(char*** matrix, int d1, int d2, int d3);
void printlist(List list);
void printlistpos(List list, string positions_list); // print items at pos; ex: positions = "0.1.10" 
void delmatrix2d(char** &matrix2d, int d1, int d2);
void delmatrix3d(char*** &matrix3d, int d1, int d2, int d3);
void dellist(List& list);
void main_debug();


int main(int argc, char **argv){
    if (argc == 1) {
        main_debug();
    }
    else {
        int idx_argv = 1;
        string flightdata_filename = argv[idx_argv++];
        string data_filename = argv[idx_argv++];
        todo(flightdata_filename, data_filename);
    }
    cout << "\n";
    return 0;
}
void printmatrix2d(char** matrix, int d1, int d2) {
    for (int i = 0; i < d1; i++){
        for (int j = 0; j  < d2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void printmatrix3d(char*** matrix, int d1, int d2, int d3) {
    for (int i = 0; i < d1; i++){
        for (int j = 0; j  < d2; j++) {
            for (int k = 0; k < d3; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
void printlist(List list){
    for (Node* node = list.head; node != NULL; node = node->next){
        cout << node->base.src << "," << node->base.des << "," << node->base.hours << "," << node->base.mins << "\n";
    }
}
void delmatrix2d(char** &matrix2d, int d1, int d2){
    for (int i = 0; i < d1 ; i++) {
        delete[] matrix2d[i];
    }
    delete[] matrix2d;
}
void delmatrix3d(char*** &matrix3d, int d1, int d2, int d3){
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            delete[] matrix3d[i][j];
        }
        delete[] matrix3d[i];
    }
    delete[] matrix3d;
}
void dellist(List& list){
    for (Node *head = list.head; list.head != NULL; head = list.head) {
        list.head = head->next;
        delete head; head = NULL;
    }
}