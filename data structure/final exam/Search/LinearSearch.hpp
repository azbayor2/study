#pragma once

void linear_search(int arr[], int n, int dest, bool &found, int &idx){
    for(int i =0; i<n; i++)
        if(arr[i]==dest){
            found = 1;
            idx = i;
            return;
        }

    found = 0;
    return;
}