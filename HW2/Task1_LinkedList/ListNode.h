#ifndef LN_H
#define LN_H

#include <iostream>

template <typename T>
class ListNode {
private:
    T data;
    ListNode<T> *link;
public:
    ListNode();
    void SetData(T data);
    T GetData();
    void SetLink(ListNode<T> *link);
    ListNode<T>* GetLink();
};

#endif

template <typename T>
inline ListNode<T>::ListNode(){
    data = T();
    link = nullptr;
}

template <typename T>
inline void ListNode<T>::SetData(T data){
    this->data = data;
}

template <typename T>
inline T ListNode<T>::GetData(){
    return data;
}

template <typename T>
inline void ListNode<T>::SetLink(ListNode<T> *link){
    this->link = link;
}

template <typename T>
inline ListNode<T> *ListNode<T>::GetLink(){
    return link;
}
