#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.front() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    }

    // Test queue underflow
    std::cout << "Dequeued element from empty queue: " << queue.dequeue() << std::endl;

    // Test isFull method
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i);
    }

    if (queue.isFull()) {
        std::cout << "Queue is full" << std::endl;
    }

    // Test queue overflow
    queue.enqueue(6);

    return 0;
}
