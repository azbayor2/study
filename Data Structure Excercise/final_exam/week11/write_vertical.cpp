#include <iostream>

using namespace std;


void write_vertical(int num){
    if(num<0){
        cout << '-' << endl;
        write_vertical(-num);
        return;
    }

    if(num<10){
        cout << num << endl;
        return;
    }

    write_vertical(num/10);
    cout << num%10 << endl;
}


int main(){
    write_vertical(48212);

    return 0;
}