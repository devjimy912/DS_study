template<class K, class E> class AVL;
template<class K, class E>
class AvlNode {
    friend class AVL<K,E>;
public: 
    AvlNode(const K& k, const E& e) {
        key = k;
        element = e;
        bf = 0;
        leftChild = rightChild = 0;
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
    void Insert(const K& _k, const E& _e); 
    void Delete(const K& _k);
private:
    AvlNode<K,E> * root;
};

template <class K, class E>
inline E &AVL<K, E>::Search(const K &_k) const{
    // TODO: 여기에 return 문을 삽입합니다.
    AvlNode<K,E> *p = root;
    while (p) {
        if (_k < p->key) p = p->leftChild;
        else if (_k > p->key) p = p->rightChild;
        else return p->element; // 키를 찾으면 해당 노드의 값을 반환
    }
    throw std::runtime_error("Key not found"); // 키를 찾지 못한 경우 예외 발생
}

template <class K, class E>
inline void AVL<K, E>::Insert(const K &_k, const E &_e){

    if(!root) { // 특별한 경우 : 공백 트리
        root = new AvlNode<K,E>(_k,_e);
        return;
    }

    // 단계 1: e를 삽입할 위치를 찾는다.
    AvlNode<K,E> *a = nullptr; // 균형 인수 +/- 1을 가진 가장 최근 노드
    AvlNode<K,E> *pa = nullptr; // a의 부모
    AvlNode<K,E> *p = root; // p는 트리 안에서 이동
    AvlNode<K,E> *pp = nullptr; // p의 부모

    while(p) {
        if(p->bf) {
            a = p; 
            pa = pp; 
        }
        if(_k<p->key) { // 왼쪽 서브트리를 취한다
            pp = p; 
            p = p->leftChild; 
        } else if(_k>p->key) { 
            pp = p; 
            p = p->rightChild; 
        } else { // k가 이미 트리 안에 존재한다
            p->element = _e; 
            return; 
        } 
    } // while문의 끝

    // 단계 2: 삽입과 재균형, k는 트리에 있지 않고,
    // pp의 적절한 자식으로 삽입될 것이다.
    AvlNode<K,E> *y = new AvlNode<K,E>(_k,_e);
    if(_k<pp->key) { // 왼쪽 자식으로 삽입
        pp->leftChild = y;
    } else { // 오른쪽 자식으로 삽입
        pp->rightChild = y;
    } 

    // 노드 a에서 pp의 균형 인수를 조정, a의 정의에 의해, 이 경로 내에
    // 있는 모든 노드들은 균형 인수 0이 되어야 하며 후에 +/-1로 변경될 것이다.
    // d = + 1은 x가 a의 왼쪽 서브트리에 삽입된 것을 의미하며
    // d = - 1은 k가 a의 오른쪽 서브트리에 삽입된 것을 의미한다.
    int d = 0;
    AvlNode<K,E> *b, // a의 자식
                *c; // b의 자식
    if(_k>a->key) {
        b = p = a->rightChild;
        d = -1; 
    } else { 
        b = p = a->leftChild; 
        d = 1; 
    }
    while( p != y ) {
        if( _k > (p->key) ) { // 오른쪽 높이가 1만큼 증가
            p->bf = -1; 
            p = p->rightChild;
        } else { // 왼쪽 높이가 1만큼 증가
            p->bf = 1; 
            p = p->leftChild;
        }
    }

    // 트리가 불균형인가?
    if(!(a->bf) || !(a->bf+d)) { // 트리가 계속 균형을 유지
        a->bf += d; 
        return;
    }

    // 트리가 불균형이 되어 회전 타입을 결정
    if(d==1) { // 왼쪽 불균형
        if(b->bf == 1) { // LL 회전
            a->leftChild = b->rightChild;
            b->rightChild = a;
            a->bf = 0; 
            b->bf = 0;
        }
        else { // LR 회전
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
            c->bf = 0; b = c; // b가 새 루트
        } // LR의 끝

    // 왼쪽 불균형의 끝
    } else { // 오른쪽 불균형: 왼쪽 불균형과 대칭
        
    } // 오른쪽 불균형의 끝
    
    // b를 루트로 갖는 서브트리가 다시 균형을 잡아 새 서브트리가 됨
    if(!pa) {
        root = b;
    } else if(a==pa->leftChild) {
        pa->leftChild = b;
    } else {
        pa->rightChild = b;
    }

    return;
} // AVL::Insert의 끝

template <class K, class E>
inline void AVL<K, E>::Delete(const K &_k)
{
}
