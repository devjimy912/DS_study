
#ifndef LL_INTERFACE_H
#define LL_INTERFACE_H

template <typename E>
class LinkedListInterface {
public:
    virtual ~LinkedListInterface() {}
    virtual void add(E item) = 0; // insert
    virtual void removeLast() = 0;
    virtual void removeFirst() = 0;
    virtual bool remove(E item) = 0;
    virtual void removeAll() = 0;
    virtual void invert() = 0;
    virtual bool contain(E item) const = 0; // retrieve
    virtual E get(int index) const = 0; // retrieve
    virtual bool isEmpty() const = 0;
    virtual bool print() const = 0;
};

#endif

