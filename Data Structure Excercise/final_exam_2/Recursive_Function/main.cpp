#include <iostream>
using namespace std;

void print_vertical(int num){
    if(num<0){
        cout << '-' << endl;
        print_vertical(-num);
        return;
    }

    if(num<10){
        cout << num << endl;
        return;
    } else{
        print_vertical(num/10);
        cout << num%10 << endl;
        return;
    }

    return;
}


int main(){
    print_vertical(-48923);
    cout << endl;

    print_vertical(5321);
    cout << endl;


    return 0;
}