#pragma once
#include "BinaryTreeWithNode.hpp"

template<class Item>
class BinarySearchTree{
    public:
    typedef binary_tree_node<Item> btn;
    typedef BinarySearchTree<Item> bst;

    private:
    btn * Root;

    size_t Size(const btn *Root){
        if(Root==NULL) return 0;
        return 1+Size(Root->left()) + Size(Root->right());
    }

    size_t Count(const btn *Root, const Item & data){
        if(Root==NULL) return 0;

        size_t ret = 0;
        if(Root->data()==data) ret++;

        return ret+Count(Root->left(), data) + Count(Root->right(), data);
    }

    void bst_remove(btn *& Root, const Item & rem){
        if(Root==NULL) return;
        
        //1. 작을 때
        if(rem<Root->data())
            bst_remove(Root->left(), rem);

        //2. 클 때
        else if(rem>Root->data())
            bst_remove(Root->right(), rem);

        //3. 목적 노드일 때
        else if(rem==Root->data()){

            //3-1 왼쪽 노드가 없을 때
            if(Root->left()==NULL)
            {
                btn *temp = Root;
                Root = Root->right();
                delete temp;
                return;
            }

            //3-2 왼쪽 노드가 존재할 때
            else{
                bst_remove_max(Root->left(), Root->data());
                return;
            }
        }

    }

    void bst_remove_max(btn *&Root, Item & rem){
        //예외처리
        if(Root==NULL) return;

        //1. 오른쪽 노드가 없으면
        if(Root->right()==NULL){
            btn *temp = Root;
            rem = Root->data();

            Root = Root->left();

            delete temp;
            return;
        }

        //2. 오른쪽 노드가 있으면
        else{
            bst_remove_max(Root->right(), rem);
            return;
        }

        return;
    }

    void insert_all(btn * Root){
        if(Root==NULL) return;

        insert(Root->data());
        insert_all(Root->left());
        insert_all(Root->right());
    }


    public:

    BinarySearchTree(){
        Root = NULL;
    }

    BinarySearchTree(const bst & src){
        Root = tree_copy(src.Root);
    }

    void operator=(const bst & src){
        tree_clear(Root);
        Root = tree_copy(src.Root);
    }

    void operator+=(const bst & src){
        if(&src==this){
            btn *temp = tree_copy(src.Root);
            insert_all(temp);
            return;
        }

        insert_all(src.Root);

        return;
    }

    void insert(const Item & data){
        btn * ins = new btn(data, NULL, NULL);
        if(this->Root==NULL){
            Root=ins;
            return;
        }

        btn *cur = Root;

        while(cur!=NULL){
            if(data<cur->data()){
                if(cur->left()==NULL){
                    cur->set_left(ins);
                    return;
                }
                cur = cur->left();
                continue;
            }

            else{
                if(cur->right()==NULL){
                    cur->set_right(ins);
                    return;
                }
                cur= cur->right();
                continue;
            }
        }

        return;
    }

    void erase_one(const Item & data){
        if(!count(data)) return;

        bst_remove(this->Root, data);

        return;
    }

    void erase_all(const Item & data){
        while(count(data))
            bst_remove(this->Root, data);

        return;
    }

    size_t size(){
        return Size(this->Root);
    }

    size_t count(const Item & data){
        return Count(Root, data);
    }

    void show_content(){
        show_tree(Root, 0);
    }

};