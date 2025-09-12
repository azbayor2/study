#include <iostream>
using namespace std;
typedef long long ll;
ll arr[10001], N, K, ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i =0; i<N; i++) cin >> arr[i];
    ll start = 1, end = ((ll)1<<31) -1 ;
    while(end>=start){
        ll cur = (ll)(start+end)/2, count=0;
        for(int i =0; i<N; i++) count+=(arr[i]/cur);
        if(count<K){
            end = cur-1; continue;
        }
        else{
            ans = max(ans, cur);
            start = cur+1;
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}