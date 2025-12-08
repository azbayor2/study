#include <iostream>
#include "BinaryTreeNodePractice.hpp"

using namespace std;

int main(){
    BinaryTreeNode<char> * Root = new BinaryTreeNode<char>('A');

    Root->set_left(new BinaryTreeNode<char>('B'));
    Root->set_right(new BinaryTreeNode<char>('C'));

    Root->get_left()->set_left(new BinaryTreeNode<char>('D'));
    Root->get_left()->set_right(new BinaryTreeNode<char>('E'));

    Root->get_right()->set_left(new BinaryTreeNode<char>('F'));

    Root->get_left()->get_left()->set_left(new BinaryTreeNode<char>('G'));


    print_children(Root);

    return 0;
}