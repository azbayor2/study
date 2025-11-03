#include <iostream>
#include <cmath>

using namespace std;

int N, M, arr[10], ans=-1, max_idx;
bool used[10];

void dfs(int cur, int idx){
    if(cur>M) return;
    if(idx==0){
        ans = max(ans, cur);
        return;
    }

    for(int i =0; i<max_idx; i++){
        if(used[i]) continue;
        used[i]=1;
        dfs(cur + arr[i]*pow(10, idx-1), idx-1);
        used[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int t = N, cnt=0;
    while(t){
        arr[cnt++]=t%10;
        t/=10;
    }
    max_idx = cnt;

    for(int i =0; i<max_idx; i++){
        if(arr[i]==0) continue;
        used[i]=1;
        dfs(arr[i]*pow(10, max_idx-1), max_idx-1);
        used[i]=0;
    }

    cout << ans << "\n";

    return 0;
}