#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;

int main(){
    BinarySearchTree<int> bag;

    bag.insert(5);
    bag.insert(2);
    bag.insert(8);

    bag.insert(1);
    bag.insert(3);
    bag.insert(7);
    bag.insert(10);

    bag.insert(-1);

    bag.show_content();
    cout << endl;

    //bag.erase_one(5);
    bag.erase_one(2);
    bag.erase_one(3);
    bag.erase_one(1);
    bag.erase_one(-1);
    bag.show_content();
}