#include <iostream>
#include "sort.hpp"
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int *arr;

    cin >> n;

    arr = new int[n];

    for(int i =0; i<n; i++)
        cin >> arr[i];

    int *res1=NULL;
    int *res2=NULL;

    SelectionSort(arr, n, res1);
    InsertionSort(arr, n, res2);

    cout << "Selection Sort: ";
    for(int i =0; i<n; i++)
        cout << res1[i] << " ";

    cout << endl;

    cout << "Insertion Sort: ";
    for(int i =0; i<n; i++)
        cout << res2[i] << " ";

    cout << endl;

    sort(arr, arr+n);

    cout << "Answer: ";
    for(int i =0; i<n; i++) cout << arr[i] << " ";

    cout << endl;


    delete res1;
    delete res2;
    delete arr;

    return 0;
}