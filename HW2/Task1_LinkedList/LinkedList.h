#ifndef LL_H
#define LL_H

#include "LinkedListInterface.h"
#include "ListNodfe.h"

template <typename T>
class LinkedList : public LinkedListInterface<T> {
private:
    ListNode<T> *head; 
    ListNode<T> *tail;
    ListNode<T> *curr;
public:
    LinkedList();
    ~LinkedList();
    void add(T item); // insert
    void removeLast();
    void removeFirst();
    boolean remove(T item);
    void removeAll();
    void invert();
    E get(T item) const; // retrieve
    E get(int index) const; // retrieve
    bool isEmpty() const;
    bool print() const;
};

#endif