#ifndef LN_H
#define LN_H

#include <iostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode<T> *link;
    ListNode(T item) : data(item), link(nullptr){};
};

#endif