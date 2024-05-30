#include <iostream>
#include "LinkedList.h"

//구현한 LinkedList함수들을 모두 사용
//구현한 LinkedList가 잘 돌아가는지 보여주는 client코드를 자유롭게 작성하세요
//반드시 모든 함수들을 사용해야 합니다

using namespace std;

int main(){
    //LinkedList();
    LinkedList<int> list;
    // ~LinkedList();

    // void add(T item); // insert
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    // void removeLast();
    list.removeLast();
    // void removeFirst();
    list.removeFirst();
    // bool remove(T item);

    // void removeAll();

    // void invert();

    // T get(T item) const; // retrieve

    // T get(int index) const; // retrieve

    // bool isEmpty() const;

    // bool print() const;

    
    return 0;
}