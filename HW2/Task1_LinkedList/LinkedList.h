#ifndef LL_H
#define LL_H

#include <iostream>
#include "LinkedListInterface.h"

template <typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    

public:
    LinkedList();
    ~LinkedList();
    void add(E item); // insert
    void removeLast();
    void removeFirst();
    boolean remove(E item);
    void removeAll();
    void invert();
    E get(E item) const; // retrieve
    E get(int index) const; // retrieve
    bool isEmpty() const;
    bool print() const;
};

#endif