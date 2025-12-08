#include <iostream>
#include "BinarySearchTree.hpp"
#include "BinaryTreeNode.hpp"

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    BinarySearchTree<int> bst;


    int n, m, a;
    cin >> n >> m;

    for(int i =0; i<n; i++){
        cin >> a;
        bst.insert(a);
    }

    bst.print_tree();

    cout << endl;

    for(int i =0; i<m; i++){
        cin >> a;
        bst.erase(a);
        bst.print_tree();
        cout << endl;
    }

    return 0;
}