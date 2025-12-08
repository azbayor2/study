#pragma once
#include <iostream>

using namespace std;

template<class Item>
class BinaryTreeNode{
    private:

    Item data;
    BinaryTreeNode<Item> * left;
    BinaryTreeNode<Item> * right;

    public:
    BinaryTreeNode(Item data, BinaryTreeNode<Item> * left=NULL, BinaryTreeNode<Item> * right=NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }

    void set_data(Item data){
        this->data = data;
    }

    void set_left(BinaryTreeNode<Item> * left){
        this->left = left;
    }

    void set_right(BinaryTreeNode<Item> * right){
        this->right = right;
    }

    BinaryTreeNode<Item> * get_left(){
        return left;
    }

    BinaryTreeNode<Item> * get_right(){
        return right;
    }

    Item& get_data(){
        return data;
    }
};

template<class Item>
void pre_order(BinaryTreeNode<Item> *t){
    if(t==NULL) return;
    cout << t->get_data() << " ";
    pre_order(t->get_left());
    pre_order(t->get_right());
}

template<class Item>
void in_order(BinaryTreeNode<Item> *t){
    if(t==NULL) return;
    in_order(t->get_left());
    cout << t->get_data() << " ";
    in_order(t->get_right());
}

template<class Item>
void post_order(BinaryTreeNode<Item> *t){
    if(t==NULL) return;
    post_order(t->get_left());
    post_order(t->get_right());
    cout << t->get_data() << " ";
}

template<class Item>
void print_child(BinaryTreeNode<Item> *t){
    if(t==NULL) return;

    cout << t->get_data() << "의 자식: ";
    if(t->get_left()!=NULL)
        cout << t->get_left()->get_data() << " ";

    if(t->get_right()!=NULL)
        cout << t->get_right()->get_data() << " ";

    cout << endl;

    print_child(t->get_left());
    print_child(t->get_right());
}