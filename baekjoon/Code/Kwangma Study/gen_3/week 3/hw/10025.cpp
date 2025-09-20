#include <iostream>
using namespace std;

typedef long long ll;

ll N, K, arr[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    ll a, b;
    for(int i =0; i<N; i++){
        cin >> a >> b;
        arr[b]=a;
    }

    for(int i=1; i<=1000000; i++)
        arr[i]+=arr[i-1];

    ll ans=0, llen = (K>500000 ? 1000000:2*K);

    for(int i =0; (i+llen)<=1000000; i++){
        ll sum = (i==0 ? arr[i+llen]: arr[i+llen]-arr[i-1]);
        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}