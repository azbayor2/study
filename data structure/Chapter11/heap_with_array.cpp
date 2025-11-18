#include "heap_with_array.h"


template<class Item>
void heap_with_array<Item>::add_item(const Item & d){
    heap[count++] = d;
    int cur = count;
    while(cur!=0){
        int par = (cur-1)/2;
        if(heap[par]>heap[cur]) break;
        swap(heap[par], heap[cur]);
        cur = par;
    }

    return;
}

template<class Item>
Item heap_with_array<Item>::get_item(){
    return heap[0];
}

template<class Item>
void heap_with_array<Item>::delete_item(){
    if(count==1){
        count--;
        return;
    }

    heap[0] = heap[--count];

    int cur = 0;
    while(cur<count){
        int c1 = cur*2+1;
        int c2 = cur*2+2;

        if(c1<count && c2<count){
            if(heap[c1]>heap[c2]){
                if(heap[c1]<heap[cur]) break;
                swap(heap[c1], heap[cur]);
                cur=c1; continue;
            } else{
                if(heap[c2]<heap[cur]) break;
                swap(heap[c2], heap[cur]);
                cur=c2; continue;
            }
        }

        else if(c1<count && c2>=count){
            if(heap[c1]<heap[cur]) break;
            swap(heap[c1], heap[cur]);
            cur = c1; continue;
        }

        else break;
    }

    return;
}