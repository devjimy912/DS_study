#ifndef LL_H
#define LL_H

#include "LinkedListInterface.h"
#include "ListNodfe.h"

template <typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    ListNode<T> *head; 
    ListNode<T> *tail;
public:
    LinkedList();
    ~LinkedList();
    void add(T item); // insert
    void removeLast();
    void removeFirst();
    boolean remove(T item);
    void removeAll();
    void invert();
    T get(T item) const; // retrieve
    T get(int index) const; // retrieve
    bool isEmpty() const;
    bool print() const;
};

#endif