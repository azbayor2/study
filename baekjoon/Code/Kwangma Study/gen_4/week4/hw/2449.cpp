#include <iostream>
#include <algorithm>

using namespace std;

int arr[201], cache[201][201], N, K;

int solve(int s, int e){
    if(cache[s][e]!=-1) return cache[s][e];
    if(s==e) return 0;
    cache[s][e] = 1<<28;

    for(int i = s+1; i<=e; i++){
        int left = solve(s, i-1);
        int right = solve(i, e);

        int temp = left+right;
        temp+=((arr[s]==arr[i])? 0:1);
        cache[s][e] = min(cache[s][e], temp);
    }

    return cache[s][e];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i =0; i<N ;i++) cin >> arr[i];
    for(int i =0; i<201; i++) fill(cache[i], cache[i]+201, -1);

    cout << solve(0, N-1) << "\n";

    return 0;
}