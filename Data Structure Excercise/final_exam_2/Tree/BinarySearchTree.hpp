#pragma once
#include "BinaryTreeNode.hpp"
#include <iostream>

using namespace std;

template<class Item>
class BinarySearchTree{
    private:
    BinaryTreeNode<Item> * Root;

    BinaryTreeNode<Item> * insert_node(BinaryTreeNode<Item> * root, Item data){
        if(root==NULL){
            return new BinaryTreeNode<Item>(data);
        }

        else if(root->get_data()>=data){
            root->set_left(insert_node(root->get_left(), data));
        }

        else if(root->get_data()<=data){
            root->set_right(insert_node(root->get_right(), data));
        }

        return root;
    }

    BinaryTreeNode<Item> * find_max(BinaryTreeNode<Item> * root){
        if(root->get_right()==NULL) return root;
        return find_max(root->get_right());
    }

    BinaryTreeNode<Item> * erase_node(BinaryTreeNode<Item> * root, Item data){
        if(root==NULL) return NULL;

        if(root->get_data()>data){
            root->set_left(erase_node(root->get_left(), data));
        }

        else if(root->get_data()<data){
            root->set_right(erase_node(root->get_right(), data));
        }

        else{
            if(root->get_left()==NULL){
                BinaryTreeNode<Item> *ret = root->get_right();
                delete root;
                return ret;
            }

            else{
                BinaryTreeNode<Item> *max_node = find_max(root->get_left());
                root->set_data(max_node->get_data());
                erase_node(root->get_left(), max_node->get_data());
            }

        }

        return root;
    }

    BinaryTreeNode<Item> * find_node(BinaryTreeNode<Item> * root, Item dest){
        if(root==NULL) return NULL;
        if(root->get_data()==dest) return root;
        else if(root->get_data()>dest) return find_node(root->get_left(), dest);
        else return find_node(root->get_right(), dest);

        return NULL;
    }


    public:

    BinarySearchTree(){
        Root=NULL;
    }

    void insert(Item ins){
        Root=insert_node(Root, ins);
    }

    void erase(Item ins){
        Root=erase_node(Root, ins);
    }

    bool find(Item ins){
        return find_node(Root, ins)!=NULL;
    }

    void print_tree(){
        print_child(Root);
    }
};