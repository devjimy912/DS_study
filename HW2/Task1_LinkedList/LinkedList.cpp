#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"
#include <stack>

template <typename T>
inline LinkedList<T>::LinkedList(){
    //LinkedList 생성자
    //헤드는 널로 초기화하고
    //테일은 헤드를 가리킨다
    head = nullptr;
    tail = head;
}

template <typename T>
inline LinkedList<T>::~LinkedList(){
    //LinkedList 소멸자
    //헤드와 테일을 널로 바꿔주면 끝인가..?
}

template <typename T>
inline void LinkedList<T>::add(T item){
    //추가 메소드
    //노드 하나 생성하고
    //테일이 가리키는 노드의 link에 위에서 만든 노드를 넣는다
    //마지막으로 테일이 위에서 만든 노드를 가리키게 한다
    ListNode node(item);
    tail->link = node;
    tail = node;
}

template <typename T>
inline void LinkedList<T>::removeLast(){
    //테일이 가리키는 노드 지우기 메소드
    //테일을 지우고 delete
    //while문으로 마지막 노드를 테일이 가리키게 한다
    ListNode<T> temp = head;
    while(temp->link != nullptr){ //temp가 가리키는 노드가 가리키는 게 널인가.
        temp = temp->link;
    }
    delete tail;
    tail = temp;
}

template <typename T>
inline void LinkedList<T>::removeFirst(){
    //헤드가 가리키는 노드 지우기 메소드
    //curr 노드 포인터 변수 생성
    //curr는 헤드가 가리키는 노드가 가리키는 노드를 가리킴
    //헤드 지우고 delete
    //헤드가 curr가 가리키는 노드를 가리키게 함
    ListNode<T> temp = head->link;
    delete head;
    head = temp;
}

template <typename T>
inline boolean LinkedList<T>::remove(T item){
    //파라미터로 받은 item을 가진 노드 찾아서 지우기 메소드
    //while문으로 해당 노드 찾기
    //해당 노드가 가리키는 노드를 curr로 가리키기
    //해당 노드 삭제 delete - 이건 prev로 가리키고 지워야하나..?
    //while로 현재 헤드가 가진 링크드리스트의 마지막에 curr가 가리키는 노드 연결

    //이건 지피티 긁어온 코드 - 수정 필요
    if (head == nullptr) return;

        if (head->value == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->value != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) return;

        prev->next = current->next;
        delete current;

    return boolean();
}

template <typename T>
inline void LinkedList<T>::removeAll(){
    //노드 전체 삭제
    //헤드부터 지우면서 마지막까지 내려옴.
    //방식은 헤드가 가리키는 노드를 curr로 가리킴
    //헤드노드 delete
    //헤드가 curr가 가리키는 노드를 가리키도록 설정
    //반복
    ListNode<T> temp;
    while(head->link != nullptr){
        temp = head->link;
        delete head;
        head = temp;
    }
    delete head;
}

template <typename T>
inline void LinkedList<T>::invert(){
    //역순
    //스택에 넣었다 빼기
    std::stack<T> myStack;
    
}

template <typename T>
inline T LinkedList<T>::get(T item) const{
    //얘는 뭐지..?

    return T();
}

template <typename T>
inline T LinkedList<T>::get(int index) const{
    //index만큼 for문으로 내려옴. 이거 +1인가 해야될듯
    ListNode<T> temp = head;
    for(int i=0; i<index; i++){
        temp = temp->link;
    }
    return temp->data;
}

template <typename T>
inline bool LinkedList<T>::isEmpty() const{
    //헤드가 널이면 빈 거
    //아니면 있는 거 겠지
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
inline bool LinkedList<T>::print() const{
    //헤드부터 데이터 출력하면서 내려옴
    //이터레이터는 따로 없으니 curr만들어서 하면 될듯
    //curr = curr->link
    ListNode<T> curr = head;
    while(curr->link != nullptr){
        std::cout << curr->data << std::endl;
        curr = curr->link;
    }
    return false;
}
