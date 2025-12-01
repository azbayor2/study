#include <iostream>

using namespace std;

void printvertical(int cur){
    if(cur<0){
        cout << "-" << endl;
        printvertical(-cur);
    }

    else{
        if(cur==0) return;
        printvertical(cur/10);
        cout << cur%10 << endl;
    }
}

int main(){

    printvertical(-212121);
    cout << endl;

    printvertical(21394);
}