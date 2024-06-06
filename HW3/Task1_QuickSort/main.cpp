#include <iostream>
#include <string>
#include "quicksort.h"

struct Student {
    int id;
    std::string name;

    bool operator<(const Student& other) const {
        return id < other.id;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << ", Name: " << student.name;
    return os;
}

int main() {
    Student arr[] = {
        {102, "Alice"},
        {101, "Bob"},
        {104, "Charlie"},
        {103, "David"},
        {105, "Eve"}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << std::endl;
    std::cout << std::endl;

    quicksort(arr, 0, n - 1);

    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << std::endl;
    return 0;
}

