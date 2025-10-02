#pragma once
#include <iostream>

using namespace std;

// 노드 구조체 정의
struct Node {
    int data;
    struct Node* link;
};

// 헤드 노드 구조체 정의
struct HeadNode {
    Node* head;
};

// 단일 연결 리스트 클래스
class singleList {
public:
    // 빈 연결 리스트 생성
    HeadNode* createList() {
        HeadNode* H = new HeadNode;
        H->head = NULL;
        return H;
    }

    // 리스트의 마지막에 노드 추가
    void addNode(HeadNode* H, int x) {
        Node* NewNode = new Node;
        Node* LastNode;
        NewNode->data = x;
        NewNode->link = NULL;

        if (H->head == NULL) {
            H->head = NewNode;
            return;
        }

        LastNode = H->head;
        while (LastNode->link != NULL) LastNode = LastNode->link;
        LastNode->link = NewNode;
    }
    
    // [구현 실습 1] 특정 노드 뒤에 새로운 노드 추가
    void addThisNode(HeadNode* H, int afterthisdata, int adddata) {
        // 이 부분을 구현하세요.
        struct Node * cur = H->head;
        while(cur!=NULL){
            if(cur->data==afterthisdata) break;
            cur = cur->link;
        }
        if(cur==NULL) return;
        struct Node * newnode = new Node;
        newnode->data = adddata;
        newnode->link = cur->link;
        cur->link = newnode;
        return;
    }

    // [구현 실습 2] 특정 데이터 값을 가진 노드 탐색
    void searchNode(HeadNode* H, int thisdata) {
        // 이 부분을 구현하세요.
        struct Node * cur = H->head;
        while(cur!=NULL){
            if(cur->data == thisdata) break;
            cur = cur->link;
        }
        if(cur!=NULL) cout << "데이터 탐색 성공" << "\n";
        else cout << "데이터 탐색 실패" << "\n";
        return;
    }



    // 리스트의 마지막 노드 삭제
    void deleteNode(HeadNode* H) {
        Node* prevNode;
        Node* delNode;

        if (H->head == NULL) return;
        if (H->head->link == NULL) {
            delete H->head;
            H->head = NULL;
            return;
        }
        else {
            prevNode = H->head;
            delNode = H->head->link;
            while (delNode->link != NULL) {
                prevNode = delNode;
                delNode = delNode->link;
            }
            free(delNode);
            prevNode->link = NULL;
        }
    }

    // [구현 실습 3] 특정 데이터 값을 가진 노드 삭제
    void deleteThisNode(HeadNode* H, int deldata) {
        // 이 부분을 구현하세요.
        struct Node * cur = H->head;
        struct Node * prev_node = NULL;
        while(cur!=NULL){
            if(cur->data==deldata) break;
            prev_node = cur;
            cur = cur->link;
        }
        if(prev_node==NULL) H->head = cur->link;
        else prev_node->link = cur->link;
        delete cur;
        return;
    }

    // 리스트 전체 출력
    void printList(HeadNode* L) {
        Node* p;
        cout << "연결리스트 목록 = ( ";
        p = L->head;
        while (p != NULL) {
            cout << p->data;
            p = p->link;
            if (p != NULL) cout << " --> ";
        }
        cout << " )" << endl;
    }
};