#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "QueueInterface.h"

template <typename T>
class Queue : public QueueInterface<T> {
private:
    T* queueArray;
    int maxSize;
    int frontIndex;
    int rearIndex;
    int itemCount;

public:
    Queue(int max_queue_size);
    ~Queue();
    void enqueue(T item) override;
    T dequeue() override;
    T front() const override;
    bool isEmpty() const override;
    bool isFull() const override;
};

// Implement here
//생성자
//시작과 끝은 0으로 놓고 시작한다. - 배열에 인덱스로 바로 접근하기 위함.
//아이템 수는 왜 세나 했는데 안에 몇개 들었는지 계산 하지 않는 건 좋았습니다.
//큐도 스택처럼 포인터를 이용한 배열로 생성.
template <typename T>
inline Queue<T>::Queue(int max_queue_size){
    maxSize = max_queue_size+1;
    frontIndex = 0;
    rearIndex = 0;
    itemCount = 0;
    queueArray = new T[maxSize];
}

//소멸자.
//생성했던 배열 지우기.
template <typename T>
inline Queue<T>::~Queue(){
    delete[] queueArray;
}

//큐에 아이템 추가.
//큐가 가득 차면 오버플로우. 아니면 아래 로직대로 해당 인덱스에 아이템을 덮어쓴다. circular큐로 구현함.
template <typename T>
inline void Queue<T>::enqueue(T item){
    //check overflow - max
    //check index number
    if(isFull()){
	    cout << "Queue overflow" << std::endl;
    }else {
        rearIndex = (rearIndex + 1) % maxSize;
        itemCount++;
        queueArray[rearIndex] = item;
    }
}

//큐에서 아이템 추출
//큐가 비었으면 0리턴. 오버플로우가 맞겠지만 출력이상이.. - 이거 스택에서도 똑같았던 걸로 기억합니다.
//프론트인덱스를 1더하고 프론트 인덱스의 데이터 리턴.
template <typename T>
inline T Queue<T>::dequeue(){
    //check underflow - 0
    //check index number
    if(frontIndex == rearIndex){
        // std::cout << "Queue underflow" << std::endl;
		return 0;
    }else {
        frontIndex = (frontIndex + 1) % maxSize;
        itemCount--;
        return queueArray[frontIndex];
    }
}

//가장 앞에 있는 값 확인. - 인덱스 상의 앞은 아님.
//프론트 인덱스의 공간은 안쓰므로 1더해서 해당 인덱스의 값 출력
template <typename T>
inline T Queue<T>::front() const{
    return queueArray[frontIndex+1];
}

//빈 큐인지 확인.
//프론트인덱스와 리어인덱스가 같으면 빈거.
template <typename T>
inline bool Queue<T>::isEmpty() const{
    if(frontIndex == rearIndex){
        std::cout << "Queue underflow" << std::endl;
	    return true;
    }else{
		return false;
    }
}

//가득 찼는지 확인.
//아이템 카운트와 사이즈 비교해서 확인.
//수업자료에는 다른 공식이었지만 여기 아니면 언제 itemCount변수 쓰겠나 싶어서 넣었습니다.
template <typename T>
inline bool Queue<T>::isFull() const{
    if(itemCount == maxSize-1){
	    return true;
    }else {
		return false;
    }
}

#endif