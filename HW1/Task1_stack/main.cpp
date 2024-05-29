#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }

    // Test stack underflow
    std::cout << "Popped element from empty stack: " << stack.pop() << std::endl;

    // Test isFull method
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }

    if (stack.isFull()) {
        std::cout << "Stack is full" << std::endl;
    }

    // Test stack overflow
    stack.push(6);

    return 0;
}
