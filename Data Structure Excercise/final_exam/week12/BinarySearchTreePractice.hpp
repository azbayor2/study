#pragma once
#include "BinaryTreeNodePractice.hpp"
#include <iostream>


template<class Item>
class BinarySearchTree{
    private:

    BinaryTreeNode<Item> *Root;

    BinaryTreeNode<Item> * insert_node(BinaryTreeNode<Item> * node, Item & data){
        if(node==NULL){
            return new BinaryTreeNode<Item>(data);
        }

        if(data<=node->get_data()){
            node->set_left(insert_node(node->get_left(), data));
        }

        else if(data>node->get_data()){
            node->set_right(insert_node(node->get_right(), data));
        }

        return node;
    }

    BinaryTreeNode<Item> * serach_node(BinaryTreeNode<Item> * node, Item data){
        if(node==NULL) return NULL;

        if(data==node->get_data())
            return node;

        if(data<node->get_data()){
            return serach_node(node->get_left(), data);
        }

        else if(data>node->get_data())
            return serach_node(node->get_right(), data);

        return NULL;
    }

    BinaryTreeNode<Item> * find_max(BinaryTreeNode<Item> *node){
        BinaryTreeNode<Item> * cur = node;

        while(cur!=NULL && cur->get_right()!=NULL)
            cur = cur->get_right();

        return cur;
    }



    BinaryTreeNode<Item> * delete_node(BinaryTreeNode<Item> * node, Item data){
        if(node==NULL) return NULL;

        if(data<node->get_data()){
            node->set_left(delete_node(node->get_left(), data));
            return node;
        }

        else if(data>node->get_data()){
            node->set_right(delete_node(node->get_right(), data));
            return node;
        }

        else{
            if(node->get_left()==NULL){
                BinaryTreeNode<Item> * delNode = node;
                BinaryTreeNode<Item> *right = node->get_right();
                delete delNode;

                return right;
            }

            else{
                BinaryTreeNode<Item> * MAX = find_max(node->get_left());
                node->set_data(MAX->get_data());
                node->set_left(delete_node(node->get_left(), MAX->get_data()));
                return node;
            }
        }

        return node;
    }

    public:

    BinarySearchTree(BinaryTreeNode<Item> * init=NULL){
        Root = init;
    }

    void insert_data(Item data){
        Root = insert_node(Root, data);
        inorder(Root);
        return;
    }

    bool search_data(Item data){
        return serach_node(Root, data)!=NULL;
    }

    void delete_data(Item data){
        Root = delete_node(Root, data);
        inorder(Root);

        return;
    }

};