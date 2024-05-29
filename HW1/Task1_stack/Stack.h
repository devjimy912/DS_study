#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackInterface.h"

template <typename T>
class Stack : public StackInterface<T> { // Stack class implements StackInterface<T>
    private:
        T* stackArray;
        int maxSize;
        int topIndex;

    public:
        Stack(int max_stack_size);
        ~Stack();
        void push(T item) override;
        T pop() override;
        T top() const override;
        bool isEmpty() const override;
        bool isFull() const override;
};

//Constructor
template <typename T>
Stack<T>::Stack(int max_stack_size) {
    // implement
    maxSize = max_stack_size;
    topIndex = -1;
    stackArray = new T[max_stack_size];
}

//Destructor
template <typename T>
Stack<T>::~Stack() {
    // implement
    delete[] stackArray;
}

template <typename T>
void Stack<T>::push(T item) {
    // implement
    if(topIndex == maxSize-1){
        std::cout << "Stack overflow" << std::endl;
    }else{
        stackArray[++topIndex] = item;
    }
}

template <typename T>
T Stack<T>::pop() {
    // implement
    if(topIndex==-1){
        return 0;
    }else{
        return stackArray[topIndex--];
    }
}

template <typename T>
T Stack<T>::top() const {
    // implement
    return stackArray[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    // implement
    if(topIndex < 0){
        std::cout << "Stack underflow" << std::endl;
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool Stack<T>::isFull() const {
    // implement
    return (topIndex+1 == maxSize);
}

#endif
