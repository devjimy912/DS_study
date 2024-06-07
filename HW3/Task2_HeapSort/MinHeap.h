#ifndef MINHEAP_H
#define MINHEAP_H

using namespace std;

template <typename T>
class MinHeap{
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

// #include "MaxHeap.h"
// #include <iostream>

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
    int child = this->last;
    int parent = findParent(child);
    
    //while문 수정 필요.
    while(1){
        // cout<<this->list[parent]<<" swap "<<this->list[child]<<endl;
        swap(this->list[parent], this->list[child]);
        
        child = parent;
        parent = findParent(child);
        // cout<<curr<<endl;
        if(parent < 1){
            break;
        }
    }
    // cout<<"End While"<<endl;
    //마지막. 0번 인덱스와 비교
    swap(this->list[parent], this->list[child]);
    // cout<<"0to0"<<endl;
}

template <typename T>
int MinHeap<T>::findParent(const int& index){
    if (index == 0) {
        return 0; // 루트 노드의 부모는 없음
    }
    if(index%2 == 1){
        return (index-1)/2;
    }else{
        return (index-2)/2;
    }
}

template <typename T>
T MinHeap<T>::extract(){// same as delete
    //만약 비었다면 빈 값보내기
    if(isEmpty()){
        cout<<"Heap is Empty"<<endl;
        return T();
    }
    //일단 값 저장
    T temp = this->list[0];
    //마지막 값을 최상위로 보냄
    this->list[0] = this->list[this->last];
    this->last--;
    //이제 리스트 전체를 스왚으로 헤짚으면 됨.
    int num = 0;
    while(num*2+2 <= this->last){
        swap(this->list[num], this->list[num*2+1]);
        swap(this->list[num], this->list[num*2+2]);
        num++;
    }

    if(num*2+1 == this->last){
        swap(this->list[num*2+1], this->list[this->last]);
    }

    return temp;

    /* 만들고 나서 swap메소드가 있는 걸 봤네요.
    저거 사용하려면 다른 아래 방식이랑은 다른 로직을 써야해서 새로 만드는데
    만든 거 지우기 아쉬워 남깁니다.
    //값이 있다면 최상위 값 보내기
    //일단 값 저장
    T temp = this->list[0];
    //이제 비교해야됨
    int num = 0;
    int left, right;
    //비교조건1 : 자식이 둘인가
    while((num+1)*2 <= this->last){ 
        left = num*2+1;
        right = num*2+2;
        if(left < right){ //오른쪽이 더 큰거
            this->list[num] = this->list[right];
            num = right;
        }else{ //왼쪽이 더 큰거
            this->list[num] = this->list[left];
            num = left;
        }
    }
    //자식이 하나면 왼쪽거 올리고 없으면 끝.
    //위에서는 자식이 하나 또는 안 남는 지점에서 멈춤.
    //인덱스 없는거 건들면 안되니까 if로 한번 걸렀어야 했네
    this->list[num] = this->list[this->last];
    //마지막 단계
    this->last--;
    */
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