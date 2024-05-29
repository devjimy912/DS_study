
#ifndef LL_INTERFACE_H
#define LL_INTERFACE_H

template <typename T>
class HeapInterface {
public:
    
    virtual void insert(const T& data) = 0;

    virtual T extract() = 0; // same as delete

     virtual void swap(T& dataA, T& dataB) = 0;

    virtual T peek() const = 0; // get the root item but not delete

    virtual bool isEmpty() const = 0;

    virtual bool isFull() const = 0;

    virtual ~HeapInterface() {}
};

#endif

