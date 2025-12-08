#pragma once
#include <iostream>

void selection_sort(int arr[], int size){
    
    if(size<=1) return;
    
    for(int i = size-1; i>0; i--){
        //가장 큰 것 찾기
        int idx =0, cur = arr[0];
        for(int j =1; j<=i; j++)
            if(cur<arr[j]){
                idx = j;
                cur = arr[j];
            }

        //맨 뒷자리랑 swap 하기
        
        std::swap(arr[idx], arr[i]);
    }

    return;
}