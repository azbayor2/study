#include "linkedlist.h"
#include <iostream>
#include <algorithm>

int length(const node * headptr){
    const node * cur = headptr;
    int count=0;
    while(cur!=NULL){
        count++;
        cur = cur->get_link();
    }

    return count;
}

void headinsert(node *& headptr, int data){
    headptr = new node(data, headptr);
}

void insert(node * cur, int data){
    cur->set_link(new node(data, cur->get_link()));
}

void remove(node * cur){
    node * rem = cur->get_link();
    cur->set_link(rem->get_link());
    delete rem;
}

void headremove(node *&headptr){
    node * rem = headptr;
    headptr = rem->get_link();
    delete rem;
}

node * search(node * headptr, int data){
    node * cur = headptr;
    while(cur!=NULL && cur->get_data()!= data)
        cur = cur->get_link();
    
    return cur;
}

node * locate(node * headptr, const int & dest){
    node * cur = headptr;
    for(int count=1; cur!=NULL && count<dest; count++)
        cur = cur->get_link();

    return cur;
}

void listcopy(node *& headptr, node *& tailptr, const node * src){
    headptr = NULL;
    headinsert(headptr, src->get_data());
    tailptr = headptr;

    const node * cur = src->get_link();
    while(cur!=NULL){
        insert(tailptr, cur->get_data());
        tailptr = tailptr->get_link();
        cur = cur->get_link();
    }
}
void clear(node * &headptr){
    while(headptr!=NULL){
        headremove(headptr);
    }
}