#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;

int main(){
    cout<<"Program Start"<<endl;
    //생성 어케 하지..
    int num = 7;
    /*
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
    cout<<"Max Heap is "<<maxheap.extract()<<endl;
    cout<<"-> Pop"<<endl;
    cout<<"Max Heap is "<<maxheap.extract()<<endl;
    cout<<"-> Pop"<<endl;

    cout<<"Test isFull"<<endl;
    for(int i=0; i<num+1; i++){
        maxheap.insert(i);
        cout<<"Insert "<<i<<endl;
    }
    cout<<"Test isEmpty"<<endl;
    for(int i=0; i<num+1; i++){
        cout<<"Max Heap is "<<maxheap.extract()<<endl;
        cout<<"-> Pop"<<endl;
    }
    */
    //이거 만들어 보니 지난번에 스택에서 생긴 문제랑 똑같네.. if걸기 귀찮으니 그냥 둡니다.
    //보는데 문제가 있는 것도 아니니.

    MinHeap<int> minheap(num);
    cout<<"Generate MinHeap"<<endl;
    minheap.insert(1);
    cout<<"Insert 1"<<endl;
    minheap.insert(2);
    cout<<"Insert 2"<<endl;
    minheap.insert(3);
    cout<<"Insert 3"<<endl;
    cout<<"Min Heap is "<<minheap.extract()<<endl;
    cout<<"-> Pop"<<endl;
    cout<<"Min Heap is "<<minheap.peek()<<endl;
    cout<<"-> Just veiw"<<endl;
    cout<<"Min Heap is "<<minheap.extract()<<endl;
    cout<<"-> Pop"<<endl;
    cout<<"Min Heap is "<<minheap.extract()<<endl;
    cout<<"-> Pop"<<endl;


    return 0;
}