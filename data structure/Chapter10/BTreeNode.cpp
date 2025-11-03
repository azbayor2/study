#include "BTreeNode.h"

template<class Item> 
binary_tree_node<Item>::binary_tree_node(const Item & item, 
    binary_tree_node<Item> *left_field, binary_tree_node<Item> *right_field){
    this->data_field = item;
    this->left_field = left_field;
    this->right_field = right_field;
}

// template<class Item> 
// binary_tree_node<Item>::binary_tree_node(const Item & item=0){
//     this->data_field = item;
//     this->left_field = nullptr;
//     this->right_field = nullptr;
// }

template<class Item> 
Item & binary_tree_node<Item>::data(){
    return this->data_field;
}

template<class Item> 
const Item & binary_tree_node<Item>::data() const{
    return this->data_field;
}

template<class Item> 
binary_tree_node<Item> *& binary_tree_node<Item>::left(){
    return this->left_field;
}

template<class Item> 
const binary_tree_node<Item> *binary_tree_node<Item>::left() const{
    return this->left_field;
}

template<class Item> 
binary_tree_node<Item> *& binary_tree_node<Item>::right(){
    return this->right_field;
}

template<class Item> 
const binary_tree_node<Item> * binary_tree_node<Item>::right() const{
    return this->right_field;
}

template<class Item> 
void binary_tree_node<Item>::set_data(const Item & data){
    this->data_field=data;
}

template<class Item> 
void binary_tree_node<Item>::set_left(binary_tree_node<Item> *node){
    this->left_field = node;
}

template<class Item> 
void binary_tree_node<Item>::set_right(binary_tree_node<Item> *node){
    this->right_field = node;
}

template<class Item> 
bool binary_tree_node<Item>::is_leaf(){
    if(this->left_field==NULL && this->right_field==NULL) return true;
    return false;
}


//tree functions
template<class Item>
void tree_clear(binary_tree_node<Item> *& root){
    if(root==NULL) return;

    tree_clear(root->left);
    tree_clear(root->right);
    delete root;

    root = NULL;
}

template<class Item>
binary_tree_node<Item> * tree_copy(binary_tree_node<Item> *root){
    if(root==NULL) return NULL;

    binary_tree_node<Item> * l = tree_copy(root->left);
    binary_tree_node<Item> * r = tree_copy(root->right);

    return new binary_tree_node<Item>(root->data, l, r);
}