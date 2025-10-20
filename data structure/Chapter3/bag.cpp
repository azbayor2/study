#include "bag.h"
#include <cassert>

//public

bag::bag(){
    used=0;
}

void bag::insert(int val){
    assert(used<CAP);
    data[used++]=val;
}

void bag::remove(int val){
    size_t index =0;
    while(index<used && data[index]!=val) index++;
    if(index==used) return;

    used--;
    data[index] = data[used];
}

size_t bag::size() const {
    return used;
}

int bag::occurrences(int target) const{
    int count = 0;
    for(int i =0; i<used; i++){
        if(data[i]==target) count++;
    }
    return count;
}