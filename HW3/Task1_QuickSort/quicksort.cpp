#include <iostream>

template <typename T>
void quicksort(T arr[], int left, int right){
    //피벗 정하고
    //왼쪽에서 큰거
    //오른쪽에서 작은거
    //둘다 찾으면 바꾸고 다시.
    //찾는 위치가 맞닿으면 멈춤.
    //멈춘 위치의 오른쪽 부분과 피벗 바꿈.

    // int pivot, i, j;  
    // if (left < right) {
    //     i = left; // left is the first index of the left sublist.     
    //     j = right+1; // right is the last element index of the right sublist.
    //     pivot = list[left].key;
    //     do {
    //         do i++; while(i <= right && list[i].key < pivot);
    //         do j--; while(j  > left  && list[j].key > pivot);
    //         if(i<j)
    //             swap(&list[i], &list[j]);
    //     } while (i<j);     
    //     swap(&list[left], &list[j]);

    //     QuickSort(list, left, j-1);
    //     QuickSort(list, j+1, right);
    // }

    if (left < right) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, left, right);

        // Recursively sort the left and right subarrays
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
}

template <typename T>
int partition(T arr[], int left, int right){
    T pivot = arr[left];  // Pivot element
    int i = left + 1;     // Start from the element next to the pivot
    int j = right;        // Start from the end of the array

    while (true) {
        // Increment i while the elements are less than the pivot
        while (i <= right && arr[i].id < pivot.id) {
            i++;
        }

        // Decrement j while the elements are greater than the pivot
        while (j >= left && arr[j].id > pivot.id) {
            j--;
        }

        // If i and j cross, break out of the loop
        if (i >= j) {
            break;
        }

        // Swap elements at i and j
        swap(arr[i], arr[j]);
    }

    // Swap the pivot element with the element at j
    swap(arr[left], arr[j]);

    return j;  // Return the pivot index
}

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}