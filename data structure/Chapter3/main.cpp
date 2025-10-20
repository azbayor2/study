//#include <iostream>
#include "bag.h"
#include "bag.cpp"
using namespace std;

int main(){
    bag b;
    for(int i =0; i<10; i++){
        b.insert(i);
        b.insert(i*i);
    }
    
}