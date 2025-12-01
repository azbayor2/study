#pragma once

#include <iostream>

template<class Item>
class binary_tree_node{
    public:
    typedef binary_tree_node<Item> btn;
    
    private:
    Item data_field;
    btn * left_field;
    btn * right_field;

    public:
    
    Item data() const{
        return data_field;
    };

    Item & data(){
        return data_field;
    };

    void set_data(const Item& data){
        this->data_field = data;
        return;
    }

    btn*& left(){
        return left_field;
    }

    btn* left() const{
        return left_field;
    }

    btn* right() const{
        return right_field;
    }

    btn*& right(){
        return right_field;
    }

    void set_left(btn* field){
        left_field=field;
    }

    void set_right(btn* field){
        right_field=field;
    }

    bool is_leaf(){
        if(left_field==NULL && right_field==NULL) return true;

        return false;
    }

    binary_tree_node(const Item & data, btn* l=NULL, btn* r=NULL){
        this->data_field = data;
        left_field = l;
        right_field = r;
    }
    
};

template<class Item>
binary_tree_node<Item>* tree_copy(binary_tree_node<Item> *& btn){
    if(btn == NULL) return NULL;

    binary_tree_node<Item> *l;
    binary_tree_node<Item> *r;

    l = tree_copy(btn->left());
    r = tree_copy(btn->right());

    return new binary_tree_node<Item>(btn->data(), l, r);
}

template<class Item>
void tree_clear(binary_tree_node<Item> *& btn){
    if(btn==NULL) return;
    tree_clear(btn->left());
    tree_clear(btn->right());
    delete btn;
    btn = NULL;
    return;
}

template<class Item>
void show_tree(binary_tree_node<Item> * node, int indent){
    if(node==NULL) return;

    std::string c = "    ";

    std::string ind = "";

    for(int i =0; i<indent; i++) ind+=c;

    show_tree(node->right(), indent+1);
    std::cout << ind << node->data() << std::endl;
    show_tree(node->left(), indent+1);
}

