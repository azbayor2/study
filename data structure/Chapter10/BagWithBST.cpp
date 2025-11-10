#include "BagWithBST.h"
#include "BTreeNode.cpp"
#include "BTreeNode.h"

template<class Item>
Bag<Item>::Bag(){
    headptr = NULL;
}

template<class Item>
Bag<Item>::~Bag(){
    tree_clear(headptr);
}

template<class Item>
Bag<Item>::Bag(const Bag & bg){
    headptr = tree_copy(bg.headptr);
}

template<class Item>
void Bag<Item>::insert(const Item & data){
    if(headptr==nullptr){
        headptr = new binary_tree_node(data);
        return;
    }

    binary_tree_node * cur = headptr;

    while(1){
        if(data <= cur->data()){  //작거나 같을 때
            if(cur->left() == nullptr){
                cur->set_left(new binary_tree_node(data));
                return;
            }
            else{
                cur = cur->left();
                continue;
            }
        } else{
            if(cur->right()==nullptr){
                cur->set_right(new binary_tree_node(data));
                return;
            }
            else{
                cur = cur->right();
                continue;
            }
        }
    }

    return;
}

template<class Item>
void Bag<Item>::erase(const Item & data){

}

template<class Item>
void Bag<Item>::erase_one(const Item & data){

}

template<class Item>
void Bag<Item>::operator+=(const Bag & b){
    if(this = *b){
        Bag<Item> * cb = new Bag<Item>(*this);
        insert_all(cb->headptr);
        delete cb;
    }
    else
        insert_all(b->headptr);
    return;
}

template<class Item>
void Bag<Item>::operator=(const Bag & b){
    tree_clear(headptr);
    ret.headptr = tree_copy(b.headptr);
}

template<class Item>
size_t Bag<Item>::size(){
    return Size(headptr);
}

template<class Item>
size_t Bag<Item>::count(const Item & count){

}

template<class Item>
size_t Bag<Item>::Size(const binary_tree_node<Item> *headptr){
    if(headptr==NULL) return 0;
    if(headptr->is_leaf()) return 1;
    return Size(headptr->left()) + Size(headptr->right()) + 1;
}

template<class Item>
void Bag<Item>::insert_all(const binary_tree_node<Item> * src){
    if(src==nullptr) return;

    insert(scr->data());
    insert_all(src->left());
    insert_all(src->right());
}