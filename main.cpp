
#include "list.h"

#ifdef USE_STL_ALGO
#include <algorithm>
using std::find;
using std::iter_swap;
#else
#include "iterator_algo.h"
#endif

int main(void) {
    list<int> myList;

    myList.put_front(0);
    myList.put_front(-1);
    myList.put_front(-2);
    myList.put_front(-3);
    myList.put_front(-4);
    myList.display();

    // use iterator
    list<int>::iterator iter;

    iter = find(myList.begin(), myList.end(), 2); 
    if (iter == myList.end())
        cout<<"Cannot find item!"<<"\n";
    else
        cout<<"Found! "<<*iter<<"\n";
    myList.display();

    iter = find(myList.begin(), myList.end(), -2);
    if (iter == myList.end())
        cout<<"Cannot find item!"<<"\n";
    else
        cout<<"Found! "<<*iter<<"\n";
    myList.display();

    iter_swap(iter, myList.begin());
    myList.display();

    // iterator traits for pointer type
    int *p1, *p2;
    p1 = new int(1);
    p2 = new int(2);
    cout<<"*p1 = "<<*p1<<"\t*p2 = "<<*p2<<"\n\n";
    iter_swap(p1, p2);
    cout<<"*p1 = "<<*p1<<"\t*p2 = "<<*p2<<"\n\n";
    delete p1;
    delete p2;

    return 0;
}
