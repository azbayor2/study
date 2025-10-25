#include <iostream>
using namespace std;

bool arr[1000001];

void init(){
    arr[0]=1; arr[1]=1;

    for(int i =2; i<=1000000; i++){
        if(!arr[i]){
            for(int j =2; i*j<=1000000; j++) arr[i*j]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int a, b;
    cin >> a >> b;

    for(int i =a; i<=b; i++)
        if(!arr[i]) cout << i << "\n";

    return 0;
}