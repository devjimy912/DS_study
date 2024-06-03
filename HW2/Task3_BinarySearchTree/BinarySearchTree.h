#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinarySearchTreeInterface.h"

template <typename T>
class Node {
    // data fields
    T data;
    Node *left_child, *right_child;
    Node(data){
        this->data = data;
        left_child = nullptr;
        right_child = nullptr;
    }
};

template <typename T>
class BinarySearchTree : public BinarySearchTreeInterface {
private:
    tree_node* middle;

public:
    // 요소를 트리에 삽입
    virtual void insert(const T& key) = 0;

    // 요소를 트리에서 삭제
    virtual void remove(const T& key) = 0;

    // 요소가 트리에 존재하는지 확인
    virtual bool contains(const T& key) const = 0; // search

    // 트리에서 최소값 반환
    virtual T findMin() const = 0;

    // 트리에서 최대값 반환
    virtual T findMax() const = 0;

    // 트리가 비어있는지 확인
    virtual bool isEmpty() const = 0;

    // 트리를 비움
    virtual void clear() = 0;

    // 가상 소멸자
    virtual ~BinarySearchTreeInterface() {}
};

template <typename T>
// 요소를 트리에 삽입
void BinarySearchTree<T>::insert(const T& key){
    Node node = new Node(key);
    if(middle == nullptr){
        middle = node;
    }else{
        Node* temp = middle;
        while(1){
            if(temp->data > node->data){
                if(temp->left_child == nullptr){
                    temp->left_child = node;
                    break;
                }else{
                    temp = temp->left_child;
                }
            }else{
                if(temp->right_child == nullptr){
                    temp->right_child = node;
                    break;
                }else{
                    temp = temp->right_child;
                }
            }
        }
    }
}

template <typename T>
// 요소를 트리에서 삭제
void BinarySearchTree<T>::remove(const T& key){
    //찾고 없애기
    
    //공백 메우기
}

template <typename T>
// 요소가 트리에 존재하는지 확인
bool BinarySearchTree<T>::contains(const T& key) const { // search
    //찾으면 트루
    //없으면 폴스

}

template <typename T>
// 트리에서 최소값 반환
T BinarySearchTree<T>::findMin() const {
    //널포인터 나올 때까지 왼쪽으로
    Node* temp = middle;
    while(temp->left_child != nullptr){
        temp = temp->left_child;
    }
    return temp->data;
}

template <typename T>
// 트리에서 최대값 반환
T BinarySearchTree<T>::findMax() const {
    //널포인터 나올 때까지 오른쪽으로
    Node* temp = middle;
    while(temp->right_child != nullptr){
        temp = temp->right_child;
    }
    return temp->data;
}

template <typename T>
// 트리가 비어있는지 확인
bool BinarySearchTree<T>::isEmpty() const {
    //미들이 널포인터인가
    if(middle == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
// 트리를 비움
void BinarySearchTree<T>::clear() {
    //하나씩 지워야지
    //널이면 돌아가고 있으면 지우고
}

#endif // BINARY_SEARCH_TREE_INTERFACE_H
