#include "bag.h"
#include <cassert>
#include <algorithm>
//public

using namespace std;

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

void bag::operator+=(const bag & src){
    assert(this->size()+src.size()<=CAP);
    this->used+=src.size();

    copy(src.data, src.data+src.size(), data+used);

    return;

}