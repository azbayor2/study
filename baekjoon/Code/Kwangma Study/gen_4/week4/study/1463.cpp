#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fill(arr, arr+1000001, 1<<27);
    cin >> N;

    arr[1] = 0;

    for(int i =1; i<=N; i++){
        if(i*2<=N)
            arr[i*2] = min(arr[i]+1, arr[i*2]);
        if(i*3<=N)
            arr[i*3] = min(arr[i]+1, arr[i*3]);
        if(i+1<=N)
            arr[i+1] = min(arr[i]+1, arr[i+1]);
    }

    cout << arr[N] << "\n";

    return 0;
}


/*
X=N -> X/3 X/2 X-1
X=1
X=2 -> X/3 X/2 X-1 count[X] = max(count[X-1], count[X/2], count[X/3])+1 count[2] = 1
count[6] = max(count[2], count[3], count[5])+1


*/