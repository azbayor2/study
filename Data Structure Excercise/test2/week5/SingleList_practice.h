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
        Node * cur = H->head;
        while(cur!=nullptr){
            if(cur->data==afterthisdata){
                Node * ins = new Node();
                ins->data = adddata;
                ins->link = cur->link;
                cur->link = ins;
                return;
            }
            cur = cur->link;
        }

        return;
    }

    // [구현 실습 2] 특정 데이터 값을 가진 노드 탐색
    void searchNode(HeadNode* H, int thisdata) {
        Node * cur = H->head;
        while(cur!=nullptr){
            if(cur->data ==thisdata){
                cout << "found!" << endl;
                return;
            }
            cur = cur->link;
        }

        cout << "not found!" << endl;

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
        Node * cur = H->head;
        Node * prev = nullptr;
        while(cur!=nullptr){
            if(cur->data==deldata){
                if(prev==nullptr) //헤드 노드일 때
                H->head = cur->link;
                delete cur;
                return;
            }
            else{
                prev->link = cur->link;
                delete(cur);
                return;
            }

            cur = cur->link;
        }

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