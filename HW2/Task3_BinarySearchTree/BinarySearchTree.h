#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinarySearchTreeInterface.h"

using namespace std;

template <typename T>
class Node {
    // data fields
public:
    T data;
    Node<T> *left_child, *right_child;
    Node<T>(T data){
        this->data = data;
        left_child = nullptr;
        right_child = nullptr;
    }
};

template <typename T>
class BinarySearchTree : public BinarySearchTreeInterface<T> {
private:
    Node<T>* middle;

public:
    // 요소를 트리에 삽입
    virtual void insert(const T& key);

    // 요소를 트리에서 삭제
    virtual void remove(const T& key);

    // 요소가 트리에 존재하는지 확인
    virtual bool contains(const T& key) const; // search

    // 트리에서 최소값 반환
    virtual T findMin() const;

    // 트리에서 최대값 반환
    virtual T findMax() const;

    // 트리가 비어있는지 확인
    virtual bool isEmpty() const;

    // 트리를 비움
    virtual void clear();
};

template <typename T>
// 요소를 트리에 삽입
void BinarySearchTree<T>::insert(const T& key){
    Node<T>* node = new Node<T>(key);
    if(middle == nullptr){
        middle = node;
    }else{
        Node<T>* temp = middle;
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
    if(contains(key)){
        cout<<"Doesn't exist "<<key<<endl;
        return;
    }
    //찾고 없애기
    Node<T>* temp = middle;
    Node<T>* prev;
    int a;
    while(1){
        if(temp->data > key){
            prev=temp;
            temp = temp->left_child;
            a=1;//right
        }else if(temp->data < key){
            prev=temp;
            temp = temp->right_child;
            a=0;//left
        }else{//찾음. 공백 메우기
            if(temp->right_child == nullptr && temp->left_child == nullptr){
                delete temp;
                if(a){
                    prev->right_child = nullptr;
                }else{
                    prev->left_child = nullptr;
                }
            }else if(temp->right_child != nullptr && temp->left_child == nullptr){
                if(a){
                    prev->right_child = temp->right_child;
                }else{
                    prev->left_child = temp->right_child;
                }
                delete temp;
            }else if(temp->right_child == nullptr && temp->left_child != nullptr){
                if(a){
                    prev->right_child = temp->left_child;
                }else{
                    prev->left_child = temp->left_child;
                }
                delete temp;
            }else{//둘다있는거
                Node<T>* change = temp->left_child;
                while(change->right_child != nullptr){
                    prev = change;
                    change = change->right_child;
                }
                temp->data = change->data;
                if(change->right_child == nullptr && change->left_child == nullptr){
                    delete change;
                    if(a){
                        prev->right_child = nullptr;
                    }else{
                        prev->left_child = nullptr;
                    }
                }else if(change->right_child != nullptr && change->left_child == nullptr){
                    if(a){
                        prev->right_child = change->right_child;
                    }else{
                        prev->left_child = change->right_child;
                    }
                    delete change;
                }else if(change->right_child == nullptr && change->left_child != nullptr){
                    if(a){
                        prev->right_child = change->left_child;
                    }else{
                        prev->left_child = change->left_child;
                    }
                    delete change;
                }
            }
        }
    }
}

template <typename T>
// 요소가 트리에 존재하는지 확인
bool BinarySearchTree<T>::contains(const T& key) const { // search
    //찾으면 트루
    //없으면 폴스
    Node<T>* temp = middle;
    while(1){
        if(temp->data > key){
            if(temp->left_child == nullptr){
                return false;
            }else{
                temp = temp->left_child;
            }
        }else if(temp->data < key){
            if(temp->right_child == nullptr){
                return false;
                break;
            }else{
                temp = temp->right_child;
            }
        }else{
            return true;
        }
    }
    
}

template <typename T>
// 트리에서 최소값 반환
T BinarySearchTree<T>::findMin() const {
    //널포인터 나올 때까지 왼쪽으로
    Node<T>* temp = middle;
    while(temp->left_child != nullptr){
        temp = temp->left_child;
    }
    return temp->data;
}

template <typename T>
// 트리에서 최대값 반환
T BinarySearchTree<T>::findMax() const {
    //널포인터 나올 때까지 오른쪽으로
    Node<T>* temp = middle;
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
    Node<T>* temp = middle;
    while(1){
        if(middle->right_child == nullptr && middle->left_child == nullptr){
            break;
        }
        if(temp->right_child == nullptr && temp->left_child == nullptr){
            delete temp;
            temp = middle;
        }else{
            if(temp->right_child != nullptr){
                temp = temp->right_child;
            }else{
                temp = temp->left_child;
            }
        }
    }
    delete middle;
    middle = nullptr;
}

#endif // BINARY_SEARCH_TREE_INTERFACE_H
