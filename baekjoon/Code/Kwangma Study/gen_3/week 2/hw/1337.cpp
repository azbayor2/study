#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[51], s=0, e=0, ans=100;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i =0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    
    while(s<=e && e<N){
        ans = min(ans, (5-(e-s+1)));
        e++; if(e==N) break;
        while(arr[e]-arr[s]>=5) s++;
    }

    cout << ans << "\n";

    return 0;
}