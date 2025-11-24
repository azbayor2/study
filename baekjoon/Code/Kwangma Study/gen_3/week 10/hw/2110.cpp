#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[200001], N, M, ans;
ll l=1, r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    sort(arr, arr+N);

    while(l<=r){
        ll cur_loc = arr[0];
        ll idx = 1;
        ll count =1;
        ll mid = (l+r)/2;
        ll temp_min = (ll)2<<30;

        while(idx<N){
            if((ll)cur_loc+mid>arr[idx]){
                idx++; continue;
            }
            count++;
            temp_min = min(temp_min, (ll)arr[idx]-cur_loc);
            cur_loc = arr[idx]; idx++;
        }

        if(count<M){
            r = mid-1;
            continue;
        } else if(count>=M){
            ans = max(ans, temp_min);
            l = mid+1; continue;
        }
    }

    cout << ans << "\n";

    return 0;
}


/*
    틀린 이유:
     1. 거리의 최대값을 구하는 건데 거리를 줄이고 있었음
     2. count>M 일 때 count 중 M개를 선택했을 때의 경우를 무시함
*/