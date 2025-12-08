#pragma once


void binary_search(int arr[], int n, int dest, bool &found, int &idx){
    int s = 0, e = n-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==dest){
            found = true; idx = mid;
            return;
        }

        else if(arr[mid]>dest){
            e = mid-1;
            continue;
        }

        else{
            s = mid+1;
            continue;
        }
    }

    found = 0;

    return;
}