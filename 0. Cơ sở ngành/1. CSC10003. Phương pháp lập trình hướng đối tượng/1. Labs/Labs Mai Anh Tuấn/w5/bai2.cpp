#include <iostream>
#include <algorithm>

template <class T>
class SLList {
private:
    struct Node {
        T _info;
        Node* _pNext;
    };

    Node* _pHead, * _pTail;
    int _n;
    static Node* CreateNode(const T& value);
public:
    class Iterator {
    public:
        // Các type alias cần thiết cho iterator traits (để tương thích STL)
        using iterator_category = std::forward_iterator_tag;    // Chỉ duyệt tiến
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
    private:
        Node* current_node;
        Iterator(Node* node) : current_node(node) {}
        friend class SLList<T>;
    public:
        Iterator() : current_node(nullptr) {}
        reference operator*() {
            if (current_node == nullptr) {
                throw std::out_of_range("Dereferencing end() or null iterator");
            }

            return current_node->_info;
        }

        pointer operator->() {
            if (current_node == nullptr) {
                throw std::out_of_range("Accessing member via end() or null iterator");
            }

            return &(current_node->_info);
        }

        Iterator& operator++() {
            if (current_node) {
                current_node = current_node->_pNext;
            } else {
                throw std::out_of_range("Incrementing end() or null iterator");
            }
            return *this;
        }

        Iterator operator++(int) {
            if (current_node == nullptr) {
                throw std::out_of_range("Incrementing end() or null iterator");
            }

            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        bool operator==(const Iterator& other) const {
            return current_node == other.current_node;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    SLList();
    ~SLList();

    void AddHead(const T& value);
    void AddTail(const T& value);
    void RemoveHead();
    void RemoveTail();
    void Clear();

    // --- Iterator Access ---
    Iterator begin();
    Iterator end();

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const SLList<U>& ll);
};

void fnAction(int);
void fnAction2(int&);
bool fnPredict(int);
// =========================================

int main() {
    SLList<int> l;
    l.AddTail(1);
    l.AddTail(1);
    l.AddTail(0);
    l.AddTail(4);
    l.AddTail(2);
    l.AddTail(5);

    // Duyệt iterator (chuẩn STL)
    for (SLList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << ", ";
    }

    std::cout << "\n";

    // Duyệt iterator (for each trong algo)
    std::for_each(l.begin(), l.end(), fnAction2);
    std::for_each(l.begin(), l.end(), fnAction);
    std::cout << "\n";

    // Sử dụng hàm replace_if trong algorithm
    std::replace_if(l.begin(), l.end(), fnPredict, 100);
    std::cout << l << "\n";


    // Sử dụng fill trong algorithm
    std::fill(l.begin(), l.end(), 123);
    std::cout << l << "\n";
    l.Clear();

    return 0;
}

// =========================================

template <class T>
typename SLList<T>::Node* SLList<T>::CreateNode(const T& value) {
    Node* node = new Node{value, nullptr};
    return node;
}

template <class T>
typename SLList<T>::Iterator SLList<T>::begin() {
    return Iterator(_pHead);
}

template <class T>
typename SLList<T>::Iterator SLList<T>::end() {
    return Iterator(nullptr);
}

template<class T>
typename std::ostream& operator<<(std::ostream& os, const SLList<T>& ll) {
    typename SLList<T>::Node* node = ll._pHead;
    while (node) {
        os << node->_info << ", ";
        node = node->_pNext;
    }
    return os;
}

template <class T>
SLList<T>::SLList() : _pHead(nullptr), _pTail(nullptr), _n(0) {}

template <class T>
SLList<T>::~SLList() {
    while(_pHead) {
        Node* temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
    }
    _pTail = nullptr;
    _n = 0;
}

template <class T>
void SLList<T>::Clear() {
    while (_pHead) {
        Node* temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
    }
    _pTail = nullptr;
    _n = 0;
}

template <class T>
void SLList<T>::AddTail(const T& value) {
    Node* newNode = CreateNode(value);
    if (newNode == nullptr) {
        std::cerr << "Memory allocation failed!" << "\n";
        return;
    }

    if (_pHead == nullptr) {
        _pHead = _pTail = newNode;
        ++_n;
        return;
    }

    _pTail->_pNext = newNode;
    _pTail = newNode;
    ++_n;
} 

template <class T>
void SLList<T>::AddHead(const T& value) {
    Node* newNode = CreateNode(value);
    if (newNode == nullptr) {
        std::cerr << "Memory allocation failed!" << "\n";
        return;
    }

    if (_pHead == nullptr) {
        _pHead = _pTail = newNode;
        ++_n;
        return;
    }

    newNode->_pNext = _pHead;
    _pHead = newNode;
    ++_n;
}

template <class T>
void SLList<T>::RemoveHead() {
    if (_pHead == nullptr) {
        std::cerr << "List is empty!" << "\n";
        return;
    }

    Node* temp = _pHead;
    _pHead = _pHead->_pNext;
    delete temp;
    --_n;

    if (_pHead == nullptr) {
        _pTail = nullptr;
    }
}

template <class T>
void SLList<T>::RemoveTail() {
    if (_pHead == nullptr) {
        std::cerr << "List is empty!" << "\n";
        return;
    }

    if (_pHead == _pTail) {
        delete _pHead;
        _pHead = _pTail = nullptr;
        --_n;
        return;
    }

    Node* current = _pHead;
    while (current->_pNext != _pTail) {
        current = current->_pNext;
    }

    delete _pTail;
    _pTail = current;
    _pTail->_pNext = nullptr;
    --_n;
    if (_pTail == nullptr) {
        _pHead = nullptr;
    }
}

void fnAction(int val) {
    std::cout << val << ", ";
}

void fnAction2(int& val) {
    val *= 2;
}

bool fnPredict(int val) {
    const int threshold = 3;
    return val > threshold;
}