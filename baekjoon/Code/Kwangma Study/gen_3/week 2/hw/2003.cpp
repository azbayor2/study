#include <iostream>
using namespace std;

typedef long long ll;

ll N, M, arr[10005], s, e=1, sum, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M; for(int i=0; i<N; i++) cin >> arr[i];
    sum = arr[0];
    while(s<=e && e<=N){
        if(s==e){
            sum+=arr[e++]; continue;
        }
        if(sum==M) ans++;
        if(sum<M) sum+=arr[e++];
        else sum-=arr[s++]; 
    }

    cout << ans << "\n";
    return 0;
}