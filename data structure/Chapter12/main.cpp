#include <iostream>
#include "Table.hpp"

using namespace std;

int main(){
    Table<SomeData> tb;


    tb.insert({2,});

    tb.insert({23, });

    tb.insert({230, });

    tb.insert({102, });

    tb.insert({1002, });

    tb.erase(2);

    return 0;
}