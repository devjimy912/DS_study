#ifndef LL_H
#define LL_H

#include "LinkedListInterface.h"e

template <typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    list_node *head; 
    list_node *tail;
    list_node *curr;
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