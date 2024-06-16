#include <iostream>
#include <algorithm> // std::max 사용을 위해 추가
#include <stdexcept> // 예외 처리를 위해 추가

template<class K, class E> class AVL;
template<class K, class E>
class AvlNode {
    friend class AVL<K,E>;
public:
    AvlNode(const K& k, const E& e) {
        key = k;
        element = e;
        bf = 0;
        leftChild = rightChild = nullptr;
    }
private:
    K key;
    E element;
    int bf;
    AvlNode<K,E> *leftChild, *rightChild;
};

template<class K, class E>
class AVL {
public:
    AVL() : root(nullptr) {};
    E& Search(const K& _k) const;
    void Insert(const K& _k, const E &_e);
    void Delete(const K& _k);
    void PrintTree() const;
private:
    AvlNode<K,E>* root;
    int height(AvlNode<K,E>* node) const;
    AvlNode<K,E>* rightRotate(AvlNode<K,E>* y);
    AvlNode<K,E>* leftRotate(AvlNode<K,E>* x);
    void PrintTree(AvlNode<K,E> *node, int space) const;
    AvlNode<K,E>* deleteNode(AvlNode<K,E>* node, const K& key);
    AvlNode<K,E>* findMin(AvlNode<K,E>* node) const;
};

template <class K, class E>
int AVL<K, E>::height(AvlNode<K,E>* node) const {
    // std::cout<<"height"<<std::endl;
    if (node == nullptr) return 0;
    return std::max(height(node->leftChild), height(node->rightChild)) + 1;
}

template <class K, class E>
inline E& AVL<K, E>::Search(const K &_k) const {
    std::cout<<"Search"<<std::endl;
    AvlNode<K,E>* p = root;
    while (p != nullptr) {
        if (_k < p->key) p = p->leftChild;
        else if (_k > p->key) p = p->rightChild;
        else return p->element;
    }
    throw std::runtime_error("Key not found");
}

template <class K, class E>
inline void AVL<K, E>::Insert(const K &_k, const E &_e) {
    std::cout<<"insert"<<std::endl;
    if (!root) {
        root = new AvlNode<K,E>(_k,_e);
        return;
    }

    AvlNode<K,E> *a = root;
    AvlNode<K,E> *pa = nullptr;
    AvlNode<K,E> *p = root;
    AvlNode<K,E> *pp = nullptr;
    
    while (p) {
        if (p->bf) {
            a = p;
            pa = pp;
        }
        if (_k < p->key) {
            pp = p;
            p = p->leftChild;
        } else if (_k > p->key) {
            pp = p;
            p = p->rightChild;
        } else {
            p->element = _e;
            return;
        }
    }

    AvlNode<K,E> *y = new AvlNode<K,E>(_k,_e);
    if (_k < pp->key) {
        pp->leftChild = y;
    } else {
        pp->rightChild = y;
    }

    int d = 0;
    AvlNode<K,E> *b, *c;
    if (_k > a->key) {
        b = p = a->rightChild;
        d = -1;
    } else {
        b = p = a->leftChild;
        d = 1;
    }
    while (p != y) {
        if (_k > p->key) {
            p->bf = -1;
            p = p->rightChild;
        } else {
            p->bf = 1;
            p = p->leftChild;
        }
    }

    if (!(a->bf) || !(a->bf + d)) {
        a->bf += d;
        return;
    }

    if (d == 1) {
        if (b->bf == 1) {
            a->leftChild = b->rightChild;
            b->rightChild = a;
            a->bf = 0;
            b->bf = 0;
        } else {
            c = b->rightChild;
            b->rightChild = c->leftChild;
            a->leftChild = c->rightChild;
            c->leftChild = b;
            c->rightChild = a;
            switch (c->bf) {
                case 1:
                    a->bf = -1;
                    b->bf = 0;
                    break;
                case -1:
                    b->bf = 1;
                    a->bf = 0;
                    break;
                case 0:
                    b->bf = 0;
                    a->bf = 0;
                    break;
            }
            c->bf = 0;
            b = c;
        }
    } else {
        if (b->bf == -1) {
            a->rightChild = b->leftChild;
            b->leftChild = a;
            a->bf = 0;
            b->bf = 0;
        } else {
            c = b->leftChild;
            b->leftChild = c->rightChild;
            a->rightChild = c->leftChild;
            c->rightChild = b;
            c->leftChild = a;
            switch (c->bf) {
                case 1:
                    b->bf = -1;
                    a->bf = 0;
                    break;
                case -1:
                    a->bf = 1;
                    b->bf = 0;
                    break;
                case 0:
                    a->bf = 0;
                    b->bf = 0;
                    break;
            }
            c->bf = 0;
            b = c;
        }
    }

    if (!pa) {
        root = b;
    } else if (a == pa->leftChild) {
        pa->leftChild = b;
    } else {
        pa->rightChild = b;
    }

    return;
}

template <class K, class E>
AvlNode<K,E>* AVL<K, E>::rightRotate(AvlNode<K,E>* y) {
    std::cout<<"rightrotate"<<std::endl;
    AvlNode<K,E>* x = y->leftChild;
    AvlNode<K,E>* T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->bf = height(y->leftChild) - height(y->rightChild);
    x->bf = height(x->leftChild) - height(x->rightChild);

    return x;
}

template <class K, class E>
AvlNode<K,E>* AVL<K, E>::leftRotate(AvlNode<K,E>* x) {
    std::cout<<"leftrotate"<<std::endl;
    AvlNode<K,E>* y = x->rightChild;
    AvlNode<K,E>* T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->bf = height(x->leftChild) - height(x->rightChild);
    y->bf = height(y->leftChild) - height(y->rightChild);

    return y;
}

template <class K, class E>
void AVL<K, E>::PrintTree() const {
    std::cout<<"printtree"<<std::endl;
    PrintTree(root, 0);
}

template <class K, class E>
void AVL<K, E>::PrintTree(AvlNode<K,E> *node, int space) const {
    if (node == nullptr)
        return;

    space += 10;

    PrintTree(node->rightChild, space);

    std::cout << std::endl;
    for (int i = 10; i < space; i++)
        std::cout << " ";
    std::cout << node->key << "\n";

    PrintTree(node->leftChild, space);
}

template <class K, class E>
AvlNode<K,E>* AVL<K, E>::findMin(AvlNode<K,E>* node) const {
    std::cout<<"findmin"<<std::endl;
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
}

template <class K, class E>
AvlNode<K,E>* AVL<K, E>::deleteNode(AvlNode<K,E>* node, const K& key) {
    // std::cout<<"deleteNOde"<<std::endl;
    if (node == nullptr)
        return node;

    if (key < node->key) {
        node->leftChild = deleteNode(node->leftChild, key);
    } else if (key > node->key) {
        node->rightChild = deleteNode(node->rightChild, key);
    } else {
        if ((node->leftChild == nullptr) || (node->rightChild == nullptr)) {
            AvlNode<K,E>* temp = node->leftChild ? node->leftChild : node->rightChild;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AvlNode<K,E>* temp = findMin(node->rightChild);

            node->key = temp->key;
            node->element = temp->element;

            node->rightChild = deleteNode(node->rightChild, temp->key);
        }
    }

    if (node == nullptr) return node;

    node->bf = height(node->leftChild) - height(node->rightChild);

    if (node->bf > 1 && height(node->leftChild->leftChild) >= height(node->leftChild->rightChild)) {
        return rightRotate(node);
    }

    if (node->bf > 1 && height(node->leftChild->leftChild) < height(node->leftChild->rightChild)) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (node->bf < -1 && height(node->rightChild->rightChild) >= height(node->rightChild->leftChild)) {
        return leftRotate(node);
    }

    if (node->bf < -1 && height(node->rightChild->rightChild) < height(node->rightChild->leftChild)) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template <class K, class E>
inline void AVL<K, E>::Delete(const K &_k) {
    std::cout<<"delete"<<std::endl;
    root = deleteNode(root, _k);
}