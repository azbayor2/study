#include <iostream>
#include "BinarySearchTreePractice.hpp"
#include <iostream>

using namespace std;


int main(){
    BinarySearchTree<int> bst;

    int n, a;
    cin >> n;

    for(int i =0; i<n; i++){
        cin >> a;
        bst.insert_data(a);
        cout << endl;
    }

    cout << bst.search_data(6) << endl;
    cout << bst.search_data(7) << endl;
    cout << bst.search_data(9) << endl;

    cout << endl;

    bst.delete_data(7);
    cout << endl;
    bst.delete_data(1);
    cout << endl;
    bst.delete_data(5);
    cout << endl;

    return 0;
}