#pragma once
#include <iostream>
using namespace std;

template<class Item>
class BinaryTreeNode{
    private:
    Item data;
    BinaryTreeNode<Item> * left_node;
    BinaryTreeNode<Item> * right_node;

    public:

    BinaryTreeNode(const Item & data, BinaryTreeNode<Item> *left=NULL, BinaryTreeNode<Item> *right=NULL){
        this->data = data;
        left_node = left;
        right_node = right;
    }

    Item& get_data(){
        return data;
    }

    void set_left(BinaryTreeNode<Item> *left){
        left_node = left;
    }

    void set_right(BinaryTreeNode<Item> *right){
        right_node = right;
    }

    BinaryTreeNode<Item> * get_left(){
        return left_node;
    }

    BinaryTreeNode<Item> * get_right(){
        return right_node;
    }

    void set_data(Item & data){
        this->data=data;
    }

    bool is_leaf(){
        return (left_node==NULL && right_node==NULL);
    }
};


template<class Item>
void print_children(BinaryTreeNode<Item> * Root){
    if(Root==NULL) return;

    cout << Root->get_data() <<"의 자식: ";

    if(Root->get_left()!=NULL)
        cout << Root->get_left()->get_data() << " ";

    if(Root->get_right()!=NULL)
        cout << Root->get_right()->get_data() << " ";

    cout << endl;

    print_children(Root->get_left());
    print_children(Root->get_right());
}


template<class Item>
void preorder(BinaryTreeNode<Item> * Root){
    if(Root==NULL) return;

    cout << Root->get_data() << endl;
    preorder(Root->get_left());
    preorder(Root->get_right());
}

template<class Item>
void inorder(BinaryTreeNode<Item> * Root){
    if(Root==NULL) return;

    inorder(Root->get_left());
    cout << Root->get_data() << endl;
    inorder(Root->get_right());
}

template<class Item>
void postorder(BinaryTreeNode<Item> * Root){
    if(Root==NULL) return;

    postorder(Root->get_left());
    postorder(Root->get_right());
    cout << Root->get_data() << endl;
}
