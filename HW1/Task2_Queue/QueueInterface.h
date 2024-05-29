#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

using namespace std;

template <typename T>
class QueueInterface {
public:
    virtual ~QueueInterface() {}
    virtual void enqueue(T item) = 0; // same as add
    virtual T dequeue() = 0;            // same as delete
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif
