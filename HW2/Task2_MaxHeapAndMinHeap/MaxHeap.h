#ifndef MAXHEAP
#define MAXHEAP

#include <HeapInterface.h>

typedef struct{
    int key;
    string data;
} Element;

template <typename T>
class MAXHEAP : public HeapInterface {
    private:
        T* heap;

    public:
        
        MAXHEAP();
        ~MAXHEAP();

        virtual void insert(const T& data) = 0;
        virtual T extract() = 0; // same as delete
        virtual void swap(T& dataA, T& dataB) = 0;
        virtual T peek() const = 0; // get the root item but not delete
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
        virtual ~HeapInterface() {}
};




#endif