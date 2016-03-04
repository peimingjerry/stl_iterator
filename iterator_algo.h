
#ifndef ITERATOR_ALGO_H
#define ITERATOR_ALGO_H

#include "iterator_traits.h"
#include <iostream>
using std::cout;

template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& value) {
    cout<<"Using self-defined find function!\n";
    for (; first!=last; ++first) {
        if ( *first == value )
            break;
    }
    return first;
}

template <typename _Iterator1, typename _Iterator2>
void iter_swap(_Iterator1 i1, _Iterator2 i2) {
    cout<<"Using self-defined iter_swap function!\n";
    typename Iterator_Traits<_Iterator1>::value_type tmp;
    tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
}

#endif
