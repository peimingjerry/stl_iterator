
#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;

template<typename T>
struct ListItem {
        T _value;
        ListItem<T> *_next;
};

template <typename _Tp>
struct List_Iterator {
    typedef std::forward_iterator_tag iterator_category;
    typedef _Tp value_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;

    typedef ListItem<_Tp> Node;

    Node *ptr;

    List_Iterator(Node *p=0): ptr(p) {}

    reference operator*() const { return ptr->_value; }

    pointer operator->() { return &(operator *()); }

    List_Iterator& operator++ () {
        ptr = ptr->_next;
        return *this;
    }   

    bool operator== (const List_Iterator& i) {
        return ptr == i.ptr;
    }   

    bool operator!= (const List_Iterator& i) {
        return ptr != i.ptr;
    }   
};

template<typename T>
list<T>::~list() {
    while (_front != _end) {
        delete _front;
        _front = _front->_next;
    }
}

template<typename T>
void list<T>::put_front(T value) {
    Node *tmp = new Node;
    tmp->_value = value;
    tmp->_next = _front;
    this->_front = tmp;
    this->_size++;
}

template<typename T>
void list<T>::display(std::ostream &os) const {
    Node *tmp;
    os<<this->_size<<" items in this list:"<<"\n";
    for (tmp=this->_front; tmp!=0; tmp=tmp->_next)
        os<<tmp->_value<<"\t";
    os<<"\n\n";
}

#endif
