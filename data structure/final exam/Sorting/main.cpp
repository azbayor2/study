#include <iostream>
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include <algorithm>
using namespace std;

int main(){
    int n;
    int *org, *arr1, *arr2;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    org = new int[n];
    arr1 = new int[n];
    arr2 = new int[n];


    for(int i =0; i<n; i++)
        cin >> org[i];

    copy(org, org+n, arr1);
    copy(org, org+n, arr2);

    selection_sort(arr1, n);
    insertion_sort(arr2, n);


    for(int i =0; i<n; i++)
        cout << arr1[i] << " ";

    cout << endl;

    for(int i =0; i<n; i++)
        cout << arr2[i] << " ";

    cout << endl;


    return 0;
}