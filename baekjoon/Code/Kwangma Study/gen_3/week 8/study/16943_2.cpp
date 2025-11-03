#include <iostream>
using namespace std;

int N, K, w[51], ans;
bool used[51];

void dfs(int cw, int day){
    if(cw<500) return;
    if(day==(N+1)){
        ans++;
        return;
    }

    for(int i =0; i<N; i++){
        if(used[i]) continue;
        used[i]=1;
        dfs(cw-K+w[i], day+1);
        used[i]=0;
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    for(int i =0; i<N; i++) cin >> w[i];
    dfs(500, 1);

    cout << ans << "\n";

    return 0;
}