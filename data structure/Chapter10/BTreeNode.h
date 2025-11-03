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