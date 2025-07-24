#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstring>

// ========================= LinkedList ========================

template <class T>
struct Node {
    T info;
    Node* pNext;
    Node(const T& val = T(), Node* next = nullptr) : info(val), pNext(next) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* _pHead, * _pTail;
    int _n;
    static Node<T>* CreateNode(const T&);

public:
    LinkedList();
    ~LinkedList();

    Node<T>* AddHead(const T&);
    Node<T>* AddTail(const T&);
    Node<T>* RemoveHead();
    Node<T>* RemoveTail();

    T& operator[](const int&);
    const T& operator[](const int&) const;

    template <class U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);
};

template <class T>
LinkedList<T>::LinkedList() {
    _pHead = nullptr;
    _pTail = nullptr;
    _n = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    _n = 0;
    Node<T>* node = _pHead;
    while (_pHead) {
        _pHead = _pHead->pNext;
        delete node;
        node = _pHead;
    }
    _pTail = nullptr;
}

template <class T>
Node<T>* LinkedList<T>::CreateNode(const T& value) {
    Node<T>* node = new Node<T>(value, nullptr);
    return node;
}

template <class T>
Node<T>* LinkedList<T>::AddHead(const T& value) {
    Node<T>* node = CreateNode(value);
    if (node == nullptr) {
        return nullptr;
    }

    if (_pHead == nullptr) {
        _pHead = node;
        _pTail = node;
    } else {
        node->pNext = _pHead;
        _pHead = node;
    }
    _n++;
    return node;
}

template <class T>
Node<T>* LinkedList<T>::AddTail(const T& value) {
    Node<T>* node = CreateNode(value);
    if (node == nullptr) {
        return nullptr;
    }

    if (_pHead == nullptr) {
        _pHead = node;
        _pTail = node;
    } else {
        _pTail->pNext = node;
        _pTail = node;
    }
    _n++;
    return node;
}

template <class T>
Node<T>* LinkedList<T>::RemoveHead() {
    if (_pHead == nullptr) {
        return nullptr;
    }

    Node<T>* node = _pHead;
    _pHead = _pHead->pNext;
    _n--;
    
    if (_pHead == nullptr) {
        _pTail = nullptr;
    }

    return node;
}

template <class T>
Node<T>* LinkedList<T>::RemoveTail() {
    if (_pHead == nullptr) {
        return nullptr;
    }

    Node<T>* node = _pHead;
    Node<T>* prev = nullptr;

    while (node->pNext != nullptr) {
        prev = node;
        node = node->pNext;
    }

    if (prev != nullptr) {
        prev->pNext = nullptr;
        _pTail = prev;
    } else {
        _pHead = nullptr;
        _pTail = nullptr;
    }
    
    _n--;
    return node;
}

template <class T>
T& LinkedList<T>::operator[](const int& index) {
    if (index < 0 || index >= _n) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* node = _pHead;

    for (int i = 0; i < index; i++) {
        node = node->pNext;
    }

    return node->info;
}

template <class T>
const T& LinkedList<T>::operator[](const int& index) const {
    if (index < 0 || index >= _n) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* node = _pHead;

    for (int i = 0; i < index; i++) {
        node = node->pNext;
    }

    return node->info;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    Node<T>* node = list._pHead;
    
    while (node != nullptr) {
        os << node->info << " ";
        node = node->pNext;
    }

    return os;
}

// ========================= CString ========================

class CString {
private:
    char *_mang;

public:
    CString();
    CString(const char *);
    CString(const CString &);
    ~CString();

    CString &operator++();
    CString operator++(int);
    char &operator[](const int &);
    CString &operator=(const CString &);
    friend std::ostream &operator<<(std::ostream &, const CString &);
};

CString::CString() {
    _mang = nullptr;
}

CString::~CString() {
    if (_mang) {
        delete[] _mang;
    }
}

CString::CString(const char *str) {
    int len = strlen(str);
    _mang = new char[len + 1];
    strcpy_s(_mang, len + 1, str);
}

CString::CString(const CString &cs) : CString(cs._mang) {}

CString &CString::operator=(const CString &cs) {
    if (_mang) {
        delete[] _mang;
    }

    int len = strlen(cs._mang) + 1;
    _mang = new char[len];
    strcpy_s(_mang, len, cs._mang);
    return *this;
}

char &CString::operator[](const int &i) {
    int len = strlen(_mang);
    if (i < 0 || i >= len) {
        throw std::out_of_range("out of range");
    }

    return _mang[i];
}

CString &CString::operator++() {
    if (_mang) {
        int len = strlen(_mang);
        _mang[len - 1]++;
    }

    return *this;
}

CString CString::operator++(int) {
    CString temp = *this;

    if (_mang != nullptr) { 
        int len = strlen(_mang);
        _mang[len - 1]++;
    }

    return temp;
}

std::ostream &operator<<(std::ostream &os, const CString &cs) {
    if (cs._mang)
        os << cs._mang;
    return os;
}

#endif