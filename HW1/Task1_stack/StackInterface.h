#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include <iostream>

template <typename T>
class StackInterface {
public:
    virtual ~StackInterface() {}
    virtual void push(T item) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif