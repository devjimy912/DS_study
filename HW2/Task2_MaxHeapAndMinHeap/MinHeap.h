#ifndef MINHEAP_H
#define MINHEAP_H

#include "HeapInterface.h"

using namespace std;

template <typename T>
class MinHeap : public HeapInterface<T> {
    private:
        T *list;
        int maxSize;
        int last;

    public:
        MinHeap(const int &size);
        void insert(const T& data);
        int findParent(const int& index);
        T extract(); // same as delete
        void swap(T& dataA, T& dataB);
        T peek() const; // get the root item but not delete
        bool isEmpty() const;
        bool isFull() const;

};

template <typename T>
MinHeap<T>::MinHeap(const int &size){
    this->list = new T[size];
    this->maxSize = size;
    this->last = -1;
}

template <typename T>
void MinHeap<T>::insert(const T& data){
    // cout<<"Method call"<<endl;
    if(isFull()){
        cout<<"Heap already full"<<endl;
        return;
    }
    //일단 값을 넣어
    this->last++;
    // cout<<"last++"<<endl;
    this->list[this->last] = data;
    // cout<<"Insert data"<<endl;
    //그리고 값을 비교한다.
    int curr = findParent(this->last);
    int dummy = this->last;
    //while문 수정 필요.
    while(1){
        swap(this->list[curr], this->list[dummy]);
        // cout<<"swap"<<endl;
        dummy = curr;
        curr = findParent(curr);
        // cout<<curr<<endl;
        if(curr < 1){
            break;
        }
    }
}

template <typename T>
int MinHeap<T>::findParent(const int& index){
    if (index == 0) {
        return -1; // 루트 노드의 부모는 없음
    }
    if(index%2 == 1){
        return (index-1)/2;
    }else{
        return (index-2)/2;
    }
}

template <typename T>
//이거 수정 필요..
T MinHeap<T>::extract(){// same as delete
    //만약 비었다면 빈 값보내기
    if(isEmpty()){
        cout<<"Heap is Empty"<<endl;
        return T();
    }
    //일단 값 저장
    T temp = this->list[0];
    // cout<<"save"<<endl;
    //마지막 값을 최상위로 보냄
    this->list[0] = this->list[this->last];
    this->last--;
    // cout<<"start"<<endl;
    //이제 리스트 전체를 스왚으로 헤짚으면 됨.
    int num = 0;
    //또 while이야
    while(1){
        if((num+1)*2 <= this->last){
            cout<<num<<endl;
            break;
        }
        swap(this->list[num], this->list[num*2+1]);
        swap(this->list[num], this->list[num*2+2]);
        num++;
    }

    if(num*2+1 == this->last){
        swap(this->list[num*2+1], this->list[this->last]);
    }

    return temp;
}

template <typename T>
void MinHeap<T>::swap(T& dataA, T& dataB){
    if(dataA > dataB){
        T dummy = dataA;
        dataA = dataB;
        dataB = dummy;
    }
}

template <typename T>
T MinHeap<T>::peek() const {// get the root item but not delete
    if(isEmpty()){
        return T();
    }else{
        return this->list[0];
    }
}

template <typename T>
bool MinHeap<T>::isEmpty() const {
    if(this->last == -1){
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool MinHeap<T>::isFull() const {
    if(this->last +1 == this->maxSize){
        return true;
    }else{
        return false;
    }
}

#endif