#include <iostream>
#include "BinarySearch.hpp"
#include "LinearSearch.hpp"
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n, *arr;

    cin >> n;
    arr = new int[n];

    for(int i =0; i<n ;i++) cin >> arr[i];

    sort(arr, arr+n);

    bool found;
    int idx;

    for(int i =0; i<10; i++){
        binary_search(arr, n, i, found, idx);
        cout << found << " " << idx << endl;

        linear_search(arr, n, i, found, idx);
        cout << found << " " << idx << endl << endl;
    }

    return 0;
}