#include <iostream>

void heapSort(int list[], int n);

void adjust(int arr[], int root, int n);

void swap(int* a, int* b);

int main(){
    int size = 5;
    int list[size] = {45,7,25,8,35};

    heapSort(list, size);

    for(int i=0; i<size; i++){
        std::cout<<"["<<list[i]<<"]";
    }
    std::cout<<std::endl;

    return 0;
}

void adjust(int list[], int root, int n){
    int child;
    int temp = list[root];
    child = 2*root+1;
    while(child < n){
        if(child+1 < n && list[child] < list[child+1]){
            child++;
        }
        if(temp >= list[child]){
            break;
        }
        list[root] = list[child];
        root = child;
        child = root*2+1;
    }
    list[root] = temp;
}

void heapSort(int list[], int n){
    for (int i=n/2-1; i>=0; i--){
        adjust(list, i, n);
    }
    for (int i=n-1; i>0; i--) {
        swap(&list[0], &list[i]);
        adjust(list, 0, i);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}