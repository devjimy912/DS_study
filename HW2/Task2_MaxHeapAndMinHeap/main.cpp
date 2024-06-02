#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main(){
    cout<<"Program Start"<<endl;
    //생성 어케 하지..
    int num = 15;
    MaxHeap<int> maxheap(num);
    cout<<"Generate MaxHeap"<<endl;
    maxheap.insert(1);
    cout<<"Insert 1"<<endl;
    maxheap.insert(2);
    cout<<"Insert 2"<<endl;
    maxheap.insert(3);
    cout<<"Insert 3"<<endl;
    cout<<"Max Heap is "<<maxheap.extract()<<endl;
    cout<<"-> Pop"<<endl;
    cout<<"Max Heap is "<<maxheap.peek()<<endl;
    cout<<"-> Just veiw"<<endl;


    return 0;
}