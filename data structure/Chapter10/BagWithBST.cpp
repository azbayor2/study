#include "BagWithBST.h"
#include "BTreeNode.cpp"
#include "BTreeNode.cpp"

template<class Item>
Bag<Item>::Bag(){
    headptr = NULL;
}

template<class Item>
Bag<Item>::~Bag(){
    
}

template<class Item>
Bag<Item>::Bag(const Bag & bg){

}

template<class Item>
void Bag<Item>::insert(const Item & data){

}

template<class Item>
void Bag<Item>::erase(const Item & data){

}

template<class Item>
void Bag<Item>::erase_one(const Item & data){

}

template<class Item>
void Bag<Item>::operator+=(const Bag & b){

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