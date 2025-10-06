#include <iostream>

using namespace std;

int fibonacci_1(int N){ 
    int arr[1000001] = {0, };
    arr[0] = 1; arr[1]=1;

    for(int i =2; i<=N; i++)
        arr[i] = arr[i-1]+arr[i-2];

    return arr[N];
}

int cache[1000001];  //메모이제이션 배열

int fibonacci_2(int N){
    
    if(cache[N]!=0) return cache[N];
    if(N==0 || N==1) return cache[N]=N;

    return cache[N] = fibonacci_2(N-1) + fibonacci_2(N-2);
}