#include "BinaryTreeNode.hpp"
#include <iostream>

using namespace std;

int main(){
    BinaryTreeNode<char> * root = new BinaryTreeNode<char>('A');
    BinaryTreeNode<char> * node1 = new BinaryTreeNode<char>('B');
    BinaryTreeNode<char> * node2 = new BinaryTreeNode<char>('C');
    BinaryTreeNode<char> * node3 = new BinaryTreeNode<char>('D');
    BinaryTreeNode<char> * node4 = new BinaryTreeNode<char>('E');
    BinaryTreeNode<char> * node5 = new BinaryTreeNode<char>('F');
    BinaryTreeNode<char> * node6 = new BinaryTreeNode<char>('G');

    root->set_left(node1);
    root->set_right(node2);
    node1->set_left(node3);
    node1->set_right(node4);
    node2->set_left(node5);
    node2->set_right(node6);

    preorder_print(root); cout << endl;
    inorder_print(root); cout << endl;
    postorder_print(root);  cout << endl;


    return 0;

}