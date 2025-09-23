#include <iostream>
using namespace std;
typedef long long ll;
ll T, N, M, K;
void solve(){
    cin >> N >> M >> K;
    ll arr[100001] = {0,}, ans=0, temp=0;
    for(int i =0; i<N; i++){
        cin >> arr[i];
        temp+=arr[i];
    }
    ll sum=0, s=0, e=0;

    while(s<=e && s<N){
        if((e-s)==M && sum<K) ans++;
        if((s==(N-1) && s!=e)|| ((e==N) && (N==M))) break;
        sum+=arr[e%N]; e++;
        while((e-s)>M){
            sum-=arr[s%N]; s++;
        }
    }
    cout << ans << "\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i =0; i<T; i++) solve();
    return 0;
}

/*
틀린 이유:
1. N==M 일때
2. N 이 1일 때

*/