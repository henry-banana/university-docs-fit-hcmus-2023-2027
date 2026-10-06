#include "IntArray.h"

void IntArray::inputFromKeyboard(){
    do{
        cout << "Nhap so luong: ";
        cin >> n;
    }while(n < 0);
    
    if(n == 0){
        a = nullptr;
    }
    a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}
//// outDebug(7006,0x20b4fa140) malloc: *** error for object 0x16b752a58: pointer being freed was not allocated
// IntArray::IntArray(int b[], int nb){
//     a = b;
//     n = nb;
// }

IntArray::IntArray(int b[], int nb){
    if(b == nullptr){
        a = nullptr;
        n = 0;
    }
    else{
        a = new int [nb];
        for (int i = 0; i < nb; i++){
            a[i] = b[i];
        }
        n = nb;
    }
}

string IntArray::toString(){
    string ans = "";
    if(n > 0){
        for(int i = 0; i < n; i++){
            ans = ans + to_string(a[i]) + " ";
        }
    }
    else{
        ans = "Empty array";
    }
    return ans;
}
IntArray::~IntArray(){
    if(a != nullptr){
        delete []a;
        a = nullptr;
        n = 0;
    }
}
IntArray::IntArray(){
    n = 0;
    a = nullptr;
}

IntArray::IntArray(const IntArray& other){
    if(this != &other){
        n = other.n;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = other.a[i];
    }
    else{
        n = 0;
        a = nullptr;
    }
}

IntArray& IntArray::operator=(const IntArray& other){
    if(this != &other){
        delete[] a;
        n = other.n;
        if(n == 0){
            a = nullptr;
        }
        else{
            a = new int[n];
            for (int i = 0; i < n; i++){
                a[i] = other.a[i];
            }
        }
    }
    return *this;
}