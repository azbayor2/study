#include <iostream>
using namespace std;

typedef long long ll;

ll arr[100001], sum, N, M, ans=(ll)2<<60, local_max;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> arr[i];
        local_max = max(local_max, arr[i]);
        sum+=arr[i];
    }

    ll s = local_max, e=sum;

    while(s<=e){
        ll mid = (ll)(s+e)/2;
        int idx =0, count=0; ll temp=0, tempmax=0;
        while(idx<N){
            if((ll)temp+arr[idx]>mid){
                tempmax = max(temp, tempmax);
                temp=0;
                count++;
                continue;
            }
            temp+=arr[idx++];
        }
        if(temp!=0){
            count++;
            tempmax = max(temp, tempmax);
        }

        if(count<=M){
            ans = min(ans, tempmax);
            e = (ll)mid-1;
            continue;
        } else if(count>M){
            s = (ll)mid+1;
            continue;
        }
    }

    cout << ans << "\n";

    return 0;
}