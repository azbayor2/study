#include <iostream>

using namespace std;

typedef long long ll;
ll N, K, arr[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;

    for(int i=1;i<=N ;i++){
        cin >> arr[i]; arr[i]+=arr[i-1];
    }
    ll ans=0;

    for(int i =1; (i+K-1)<=N; i++) ans = max(ans, arr[i+K-1]-arr[i-1]);
    cout << ans << "\n";

    return 0;
}