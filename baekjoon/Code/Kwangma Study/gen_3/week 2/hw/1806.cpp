#include <iostream>

using namespace std;

int N, M, arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int ans = 100001;

    for(int i =0; i<N; i++)
        cin >> arr[i];

    int s = 0, e=1, sum =arr[0];

    while(s<=e && e<=N){
        if(s==e){
            sum+=arr[e]; e++;
            continue;
        }
        
        if(sum>=M){
            ans = min(ans, e-s);
        }

        if(sum>M){
            sum-=arr[s]; s++; continue;
        }

        else{
            sum+=arr[e]; e++; continue;
        }

    }

    cout << (ans==100001 ? 0 : ans) << "\n";

    return 0;
}