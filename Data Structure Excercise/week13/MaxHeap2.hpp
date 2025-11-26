#pragma once
#include <vector>
#include <iostream>

using namespace std;

class max_heap{
    vector<int> v;
    int num;

    max_heap(){
        v.resize(10000);
    }

    void upward_heapifaction(int n){
        if(n==0) return;

        int par = (n-1)/2;
        if(v[par]<v[n]){
            swap(v[par], v[n]);
            upward_heapifaction(par);
        }

        return;
    }

    void push(int n){
        v[num++] = n;
        upward_heapifaction(n);
    }

    void downward_heap(int n){
        if(n==(num-1)) return;
        int c1 = n*2+1;
        int c2 = n*2+2;
        int sel=c1;

        if(c2<num){
            if(v[c1]<v[c2]) swap()
        }
    }

    int pop(){
        int ret = v[0];
        num--;
        if(num==0) return ret;

        v[0] = v[num];
    
    }


};