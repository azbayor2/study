#pragma once
#include <iostream>

void insertion_sort(int arr[], int size){
    if(size<=1) return;
    
    for(int i = 1; i<size; i++){
        int cur = arr[i];
        int idx = i;

        while(idx>0 && arr[idx-1]>cur){
            arr[idx] = arr[idx-1];
            idx--;
        }

        arr[idx] = cur;
    }

    return;
}