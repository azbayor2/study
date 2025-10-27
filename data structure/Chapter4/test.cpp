#include <iostream>

using namespace std;

void func(const int * ptr){
    int n = 20;
    ptr = &n;

    return;
}

int main(){
    int n =20;
    func(&n);

    return 0;
}