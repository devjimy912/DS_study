#ifndef BINARY_SEARCH_TREE_INTERFACE_H
#define BINARY_SEARCH_TREE_INTERFACE_H

template <typename T>
class BinarySearchTreeInterface {
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

#endif // BINARY_SEARCH_TREE_INTERFACE_H
