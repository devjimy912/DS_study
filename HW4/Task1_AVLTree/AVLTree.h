#ifndef AVLTREE
#define AVLTREE

template<class K, class E> class AVL;

template<class K, class E>
class AvlNode{
friend class AVL<K,E>;
public AvlNode(const K& k, const E& e) { // 0 is nullptr;
    key=k;
    element=e;
    bf=0; //who are you..
    leftChild = nullptr;
    rightChild = nullptr;
}
private:
    K key;
    E element;
    int bf;
    AvlNode<K,E> *leftChild, *rightChild;
}

template<class K, class E>
class AVL{
public:
    AVL() : root(0) {};
    E& Search(const K&) const;
private:
    AvlNode<K,E> *root;
}

#endif