#pragma once
#include <iostream>

using namespace std;

class Heap{
    private:
    int data[100];
    int data_count;

    public:
    Heap(){
        data_count=0;
    }

    void insert(int ins){
        data[data_count] = ins;
        int cur = data_count;

        while(cur>0){
            int par = (cur-1)/2;
            if(data[par]>data[cur]) break;
            swap(data[cur], data[par]);
            cur = par;
        }
        
        data_count++;
    }

    int front(){
        return data[0];
    }

    void pop(){
        data_count--;
        data[0] = data[data_count];
        int cur = 0;

        while(cur<data_count){
            int left = cur*2+1;
            int right = cur*2+2;

            if(left>=data_count) break;

            int swap_child = left;
            if(right<data_count){
                if(data[left]<data[right])
                    swap_child = right;
            }

            if(data[cur]>data[swap_child]) break;
            swap(data[cur], data[swap_child]);
            cur = swap_child;
        }
    }

    void print(){
        for(int i =0; i<data_count; i++)
            cout << data[i] << " ";
        cout << endl;

        return;
    }

};