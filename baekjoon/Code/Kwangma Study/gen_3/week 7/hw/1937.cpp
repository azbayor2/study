#include <iostream>
using namespace std;

int wood[501][501];
int cache[501][501];

int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};
int N, ret;

int dfs(int curx, int cury){
    int ans = 1;
    int nextx=0, nexty=0;
    for(int i =0; i<4; i++){
        nextx = curx+mvx[i];
        nexty = cury+mvy[i];

        if(nextx<0 || nexty<0 ||nextx>=N || nexty>=N) continue;
        if(wood[cury][curx]>=wood[nexty][nextx]) continue;
        if(cache[nexty][nextx]!=0) ans = max(ans, 1+cache[nexty][nextx]);
        else    ans = max(ans, 1+dfs(nextx, nexty));
    }
    ret = max(ret, ans);
    return cache[cury][curx]=ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    cin >> N;
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
            cin >> wood[i][j];

    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++){
            if(cache[i][j]==0) dfs(j, i);
        }
    

    cout << ret << "\n";

    return 0;
}
