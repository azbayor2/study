#include <iostream>

using namespace std;

int N, M, arr[100005], cur, ans=-(1<<30);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++) cin >> arr[i];

    int s=0, e=0;
    while(e<=N){
        if((e-s)==M){
            ans = max(cur, ans);
        }
        if(e==N) break;
        cur+=arr[e++];
        while((e-s)>M){
           cur-=arr[s++];
        }
    }
    cout << ans << "\n";
    return 0;
}