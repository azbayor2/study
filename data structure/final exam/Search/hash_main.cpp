#include <iostream>
#include "HashTable.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    HashTable<item> ht;

    ht.insert({1,});
    ht.insert({2, });
    ht.insert({10001,});
    ht.insert({1, });


    ht.erase({10000001, });
    ht.erase({1,});

    return 0;
}