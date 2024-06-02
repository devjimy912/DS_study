#ifndef HEAP_H
#define HEAP_H

#include "HeapInterface.h"
#include <iostream>

template <typename T>
class Heap : public HeapInterface {
    private:
        T *list;
        int maxSize;
        int curr;

    public:
        Heap(const int &size);
        void insert(const T& data) = 0;
        T extract() = 0; // same as delete
        void swap(T& dataA, T& dataB) = 0;
        T peek() const = 0; // get the root item but not delete
        bool isEmpty() const = 0;
        bool isFull() const = 0;

}

template <typename T>
Heap::Heap(const int &size){
    this->list = new T[size];
    this->maxSize = size;
    this->curr = 0;
}

void Heap::insert(const T& data){
    //일단 값을 넣어
    this->list[curr] = data;
    //그리고 값을 비교한다.
    while(1){
        
    }
}

T Heap::extract(){// same as delete

}

void Heap::swap(T& dataA, T& dataB){

}

T Heap::peek() const {// get the root item but not delete

}

bool Heap::isEmpty() const {

}

bool Heap::isFull() const {

}



#endif