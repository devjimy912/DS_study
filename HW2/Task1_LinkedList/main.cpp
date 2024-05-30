#include <iostream>
#include "LinkedList.h"

//구현한 LinkedList함수들을 모두 사용
//구현한 LinkedList가 잘 돌아가는지 보여주는 client코드를 자유롭게 작성하세요
//반드시 모든 함수들을 사용해야 합니다

using namespace std;

int main(){
    //LinkedList();
    LinkedList<int> list;
    // void add(T item); // insert
    list.add(1);
    list.add(2);
    list.add(5);
    list.add(6);
    list.add(3);
    list.add(4);
    cout << "List : " << endl;
    list.print(); //For check
    // void removeLast();
    list.removeLast();
    cout << "List : " << endl;
    list.print(); //For check
    // void removeFirst();
    list.removeFirst();
    cout << "List : " << endl;
    list.print(); //For check
    // bool remove(T item);
    if(list.remove(4)){
        cout << "element 4 removed." << endl;
    }else{
        cout << "can not find element 4" << endl;
    }
    // void invert();
    list.invert();
    cout << "List : " << endl;
    list.print(); //For check
    // bool contain(T item) const; // retrieve
    if(list.contain(1)){
        cout << "List contain 1" << endl;
    }else{
        cout << "List does not contain 1" << endl;
    }
    // T get(int index) const; // retrieve
    cout << "List : " << endl;
    list.print(); //For check
    cout << "Index 2 : " << list.get(2) << endl;
    // bool isEmpty() const;
    if(list.isEmpty()){
        cout << "Empty" << endl;
    }else{
        cout << "Some element in list" << endl;
    }
    // void removeAll(); - in destructor
    list.removeAll();
    if(list.isEmpty()){
        cout << "Empty" << endl;
    }else{
        cout << "Some element in list" << endl;
    }
    // ~LinkedList()
    list.~LinkedList();

    
    return 0;
}