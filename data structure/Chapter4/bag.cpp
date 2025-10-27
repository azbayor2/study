#include "bag.h"
#include <cassert>
#include <algorithm>
//public

using namespace std;

bag::bag(const int & inits){
    used=0;
    data = new int[inits];
    CAP = inits;
}

void bag::insert(int val){
    if(used==CAP)
        reserve(used+1);
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
    if(used+src.used>CAP)
        reserve(used+src.used);
    
    copy(src.data, src.data+src.used, data+used);
    used+=src.used;
}

bag::bag(const bag & src){
    data = new int[src.CAP];
    used =0;
    CAP = src.CAP;

    copy(src.data, src.data+used, data);

    return;
}

bag::~bag(){
    delete [] data;
    return;
}

void bag::operator=(const bag & src){

    if(this == &src)
        return;

    if(CAP<src.CAP){
        delete [] data;
        data = new int[src.CAP];
        CAP = src.CAP;
    }

    copy(src.data, src.data+src.used, data);
    used = src.used;
}

void bag::reserve(int new_cap){
    if(new_cap ==CAP)
        return;

    if(new_cap<used)
        new_cap = used;

    int *temp = new int[new_cap];
    copy(data, data+used, temp);
    delete [] data;
    data = temp;
    CAP = new_cap;
}

bag bag::operator+(const bag &b1){
    bag ret(size()+b1.size());
    ret+=*this;
    ret+=b1;
    return ret;
}