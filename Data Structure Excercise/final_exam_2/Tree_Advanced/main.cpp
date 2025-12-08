#include <iostream>
#include "Heap.hpp"

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    Heap h;
    h.insert(10);
    h.insert(6);
    h.insert(11);
    h.insert(15);
    h.insert(1);
    h.insert(2);
    h.insert(12);
    h.insert(19);
    h.insert(8);

    h.print();

    h.pop(); h.pop(); h.pop(); h.pop(); h.pop();
    h.print();

    return 0;
}