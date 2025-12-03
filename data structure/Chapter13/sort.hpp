#pragma once
#include <iostream>
#include <algorithm>


void SelectionSort(int arr[], int size, int *&res){
    
    if(res!=NULL) delete res;
    res = new int[size];

    std::copy(arr, arr+size, res);
    
    for(int i = size-1; i>0; i--){
        //가장 큰 값 찾기
        int idx=-1, cur= -1<<28;

        for(int j =0; j<=i; j++){
            if(cur<res[j]){
                idx = j;
                cur = res[j];
            }
        }

        std::swap(res[idx], res[i]);
    }

    return;
}


void InsertionSort(int arr[], int size, int *&res){
    if(res==NULL) delete res;

    res = new int[size];
    std::copy(arr, arr+size, res);
    
    for(int i =1; i<size; i++){
        int j= i;
        int mov = res[i];
        while(j>0 && res[j-1]>mov){
            res[j] = res[j-1];
            j--;
        }
        res[j] = mov;
    }

    return;
}