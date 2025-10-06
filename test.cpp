#include <iostream>

using namespace std;

int e = 17, N = 3233, d = 2753;

int cache[100001];

int power(int a, int b){
    if(cache[b]!=0) return cache[b];
    if(b==1) return a%N;
    int mid = b/2;
    int ret = power(a, mid)%N;
    ret = (ret*ret)%N;
    return cache[b] = (b%2==0 ? ret: (ret*a)%N);
}


int main(){

    while(1){
        int a,b;
        cin >> a;
        if(a==0) break;
        fill(cache, cache+100001, 0);
        int C = power(a, e);
        fill(cache, cache+100001, 0);
        int M = power(C, d);

        cout << C <<" " << M << "\n";
    }

    return 0;

}