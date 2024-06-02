#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "HeapInterface.h"

template <typename T>
class MaxHeap : public HeapInterface {
    private:
        T *list;
        int maxSize;
        int last;

    public:
        Heap(const int &size);
        void insert(const T& data) = 0;
        T extract() = 0; // same as delete
        void swap(T& dataA, T& dataB) = 0;
        T peek() const = 0; // get the root item but not delete
        bool isEmpty() const = 0;
        bool isFull() const = 0;

}

#endif