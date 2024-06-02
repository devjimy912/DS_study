#include <iostream>
#include "LinkedList.h"

//구현한 LinkedList함수들을 모두 사용
//구현한 LinkedList가 잘 돌아가는지 보여주는 client코드를 자유롭게 작성하세요
//반드시 모든 함수들을 사용해야 합니다

using namespace std;

int main(){
    //LinkedList();
    cout<<"program start"<<endl;
    LinkedList<int> list;
    cout<<"generate list"<<endl;
    //void add(T item); // insert
    list.add(2);
    cout<<"add 2"<<endl;
    list.add(1);
    cout<<"add 1"<<endl;
    list.add(5);
    cout<<"add 5"<<endl;
    list.add(6);
    cout<<"add 6"<<endl;
    list.add(4);
    cout<<"add 4"<<endl;
    list.add(3);
    cout<<"add 3"<<endl;
    list.add(9);
    cout<<"add 9"<<endl;
    list.add(8);
    cout<<"add 8"<<endl;
    cout << "List : ";
    list.print(); //For check
    
    // void removeLast();
    list.removeLast();
    cout<<"remove last"<<endl;
    cout << "List : ";
    list.print(); //For check

    // void removeFirst();
    list.removeFirst();
    cout<<"remove first"<<endl;
    cout << "List : ";
    list.print(); //For check

    // bool remove(T item);
    if(list.remove(4)){
        cout << "element 4 removed." << endl;
    }else{
        cout << "can not find element 4" << endl;
    }
    cout << "List : ";
    list.print(); //For check

    // void invert();
    list.invert();
    cout<<"invert"<<endl;
    cout << "List : ";
    list.print(); //For check

    // bool contain(T item) const; // retrieve
    if(list.contain(1)){
        cout << "List contain 1" << endl;
    }else{
        cout << "List does not contain 1" << endl;
    }

    // T get(int index) const; // retrieve
    cout << "Index 2 : " << list.get(2) << endl;

    // bool isEmpty() const;
    if(list.isEmpty()){
        cout << "Empty" << endl;
    }else{
        cout << "Some element in list" << endl;
    }

    // void removeAll(); - in destructor
    list.removeAll();
    cout<<"removeAll" << endl;
    if(list.isEmpty()){
        cout << "Empty" << endl;
    }else{
        cout << "Some element in list" << endl;
    }
    // ~LinkedList()
    list.~LinkedList();
    

    
    return 0;
}