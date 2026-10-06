#ifndef _INT_ARRAY_
#define _INT_ARRAY_
#include <iostream>
#include <string>
using namespace std;

class IntArray{
private:
    int *a;
    int n;
public:
    void inputFromKeyboard();
    string toString();
    IntArray();
    IntArray(int b[], int nb);
    IntArray(const IntArray& other);
    ~IntArray();
    IntArray& operator=(const IntArray& other);
};

class School{
    string name;
public:
    School(string s){
        name = s;
    }
    string toString(){
        return name;
    }
    void changeName(string s){
        name = s;
    }
};

class Student{
    string name;
    int id;
    School *mySchool;
public:
    Student(){
        // Do th
        id  = 0; 
        name = "Unknown";
        mySchool = nullptr; 
    }
    Student(int id, string name, School *school){
        // Do th
        this->id = id; 
        this->name = name; 
        this->mySchool = school;
    }
    ~Student(){
        // Do th
        cout << "Destructor Student: " << name << endl; 
    }

    string toString(){
        string s = "";
        s += "Name: " + name + "; ";
        s += "ID: " + to_string(id) + "; ";
        s += "My school: " + mySchool->toString() + "";\
        return s;
    }
};
#endif