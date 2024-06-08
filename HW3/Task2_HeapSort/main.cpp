#include "MinHeap.h"

template <typename T>
void heapSort(T* arr, MinHeap<T> minheap);

template <typename T>
void adjust(T* arr, MinHeap<T> minheap);

int main(){
    int size = 5;
    int list[size] = {45,7,25,8,35};

    MinHeap<int> mh(size);

    //adjust
    adjust(list, mh);

    //heapsort
    int sorted[size];
    heapSort(sorted, mh);

    for(int i=0; i<size; i++){
        std::cout<<"["<<sorted[i]<<"]";
    }
    std::cout<<std::endl;

    return 0;
}

template <typename T>
void heapSort(T* arr, MinHeap<T> minheap){
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        arr[i] = minheap.extract();
    }
}

template <typename T>
void adjust(T* arr, MinHeap<T> minheap){
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<size; i++){
        minheap.insert(arr[i]);
    }
}