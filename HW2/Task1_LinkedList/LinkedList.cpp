#include <iostream>
#include "LinkedList.h"

using namespace std;



template <typename T>
inline LinkedList<T>::LinkedList(){
    head->link = nullptr;
    tail->link = head;
}

template <typename T>
inline LinkedList<T>::~LinkedList(){

}

template <typename T>
inline void LinkedList<T>::add(T item){

}

template <typename T>
inline void LinkedList<T>::removeLast()
{
}

template <typename T>
inline void LinkedList<T>::removeFirst()
{
}

template <typename T>
inline boolean LinkedList<T>::remove(T item)
{
    return boolean();
}

template <typename T>
inline void LinkedList<T>::removeAll()
{
}

template <typename T>
inline void LinkedList<T>::invert()
{
}

template <typename T>
inline E LinkedList<T>::get(T item) const
{
    return E();
}

template <typename T>
inline E LinkedList<T>::get(int index) const
{
    return E();
}

template <typename T>
inline bool LinkedList<T>::isEmpty() const
{
    return false;
}

template <typename T>
inline bool LinkedList<T>::print() const
{
    return false;
}
