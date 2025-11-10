#pragma once

template<class Item>
class binary_tree_node{
    private:
    Item data_field;
    binary_tree_node<Item> *left_field;
    binary_tree_node<Item> *right_field;
    

    public:
    binary_tree_node(const Item & item=0, binary_tree_node<Item> *left_field=nullptr, binary_tree_node<Item> *right_field = nullptr);
    //binary_tree_node(const Item & item=0);
    Item & data();
    const Item & data() const;
    binary_tree_node<Item> *& left();
    const binary_tree_node<Item>* left() const;
    binary_tree_node<Item> *& right();
    const binary_tree_node<Item> * right() const;
    void set_data(const Item & data);
    void set_left(binary_tree_node<Item> *node);
    void set_right(binary_tree_node<Item> *node);
    bool is_leaf();

};

template<class Item>
void tree_clear(binary_tree_node<Item> *& root);

template<class Item>
binary_tree_node<Item> * tree_copy(binary_tree_node<Item> *root);

template<class Item>  //bag with btreenode 사용
void bst_remove(binary_tree_node<Item>*& root_ptr, const Item & target);

template<class Item> //bag with btreenode 사용
void bst_remove_max(binary_tree_node<Item> *& root_ptr, Item & removed); //제거된 값을 removed에 반환
