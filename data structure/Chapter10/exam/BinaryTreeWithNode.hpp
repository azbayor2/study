#pragma once

template<class Item>
class binary_tree_node{
    public:
    typedef binary_tree_node btn;
    
    private:
    Item data;
    btn * left_field;
    btn * right_field;

    public:
    
    Item data() const{
        return data;
    }

    Item data(){
        return data;
    }

    void set_data(const Item& data){
        this->data = data;
        return;
    }

    btn* left(){
        return left_field;
    }

    btn* left() const{
        return left_field;
    }

    btn* right() const{
        return right_field;
    }

    btn* right(){
        return right_field;
    }

    void set_left(const btn* field){
        left_field=field;
    }

    void set_right(const btn* field){
        right_field=field;
    }

    bool is_leaf(){
        if(left_field==NULL && right_field==NULL) return true;

        return false;
    }

    btn(){
        left_field=NULL;
        right_field=NULL;
    }

    btn(const Item & data, btn* l, btn* r){
        this->data = data;
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

