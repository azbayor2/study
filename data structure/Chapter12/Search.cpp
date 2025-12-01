#include <iostream>
#include <algorithm>

using namespace std;

int linear_search(int arr[], int size, int dest){
    for(int i =0; i<size; i++){
        if(arr[i]==dest) return i;
    }

    return -1;
}

int binary_search(int arr[], int size, int dest){
    //precondition: arr is sorted in ascending order

    int s = 0, e = size-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==dest) return mid;

        if(arr[mid]>dest){
            e = mid-1;
            continue;
        } else{
            s = mid+1;
            continue;
        }
    }

    return -1;
}

int main(){
    int arr[10] = {1,3,5,10, 11, 19, 20};
    int size = 7;

    cout << binary_search(arr, size, 12);

    return 0;
}