#include <iostream>
#include "BTree.hpp"

using namespace std;

int main(){
    BTree<int, 2> bt;

    for(int i =1; i<=10; i++)
        bt.insert(i);

    return 0;
}