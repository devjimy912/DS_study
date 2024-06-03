#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree<int> tree;

    tree.insert(15);
    tree.insert(13);
    tree.insert(6);
    tree.insert(5);
    tree.insert(9);
    tree.insert(17);
    tree.insert(16);
    tree.insert(30);

    if(tree.contains(17)){
        cout<<"tree has 17"<<endl;
    }else{
        cout<<"not exist"<<endl;
    }
    tree.remove(17);
    if(tree.contains(17)){
        cout<<"tree has 17"<<endl;
    }else{
        cout<<"not exist"<<endl;
    }
    cout<<"Max: "<<tree.findMax()<<endl;
    cout<<"Min: "<<tree.findMin()<<endl;

    if(tree.isEmpty()){
        cout<<"Empty"<<endl;
    }else{
        cout<<"Something exist"<<endl;
    }
    tree.clear();
    if(tree.isEmpty()){
        cout<<"Empty"<<endl;
    }else{
        cout<<"Something exist"<<endl;
    }

    return 0;
}