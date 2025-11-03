#include <iostream>
#include "BTreeNode.h"
#include "BtreeNode.cpp"

using namespace std;

string DEPTH = "-";

//재귀함수로 구현


template<class Item>
void pre_order(const binary_tree_node<Item>* cur){
    if(cur==nullptr) return;

    cout << cur->data() << "\n";
    pre_order(cur->left());
    pre_order(cur->right());
    
    return;
}


template<class Item>
void in_order(const binary_tree_node<Item>* cur){
    if(cur==nullptr) return;

    in_order(cur->left());
    cout << cur->data() << "\n";
    in_order(cur->right());
    
    return;
}


template<class Item>
void post_order(const binary_tree_node<Item>* cur){
    if(cur==nullptr) return;

    post_order(cur->left());
    post_order(cur->right());
    cout << cur->data() << "\n";
    
    return;
}

template<class Item>
void backward_in_order(const binary_tree_node<Item>* cur, int depth){
    if(cur==nullptr) return;
    backward_in_order(cur->right(), depth+1);
    string c = ""; for(int i =0; i<depth; i++) c+=DEPTH;
    cout << c << cur->data() << "\n";
    backward_in_order(cur->right(), depth+1);
    
    return;
}


int main(){
    binary_tree_node<char> *headptr = new binary_tree_node<char>(0,nullptr, nullptr);

    headptr->set_data('*');
    headptr->set_left(new binary_tree_node<char>('+', NULL, NULL));
    headptr->set_right(new binary_tree_node<char>('-', nullptr, nullptr));
    headptr->left()->set_left(new binary_tree_node<char>('3', nullptr, nullptr));
    headptr->left()->set_right(new binary_tree_node<char>('y', nullptr, nullptr));
    headptr->right()->set_left(new binary_tree_node<char>('2', nullptr, nullptr));
    headptr->right()->set_right(new binary_tree_node<char>('x', nullptr, nullptr));

    backward_in_order(headptr, 0);

    return 0;
}