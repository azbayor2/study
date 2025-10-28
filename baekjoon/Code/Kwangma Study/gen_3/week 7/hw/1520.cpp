#include <iostream>
using namespace std;

int cache[501][501];
int map[501][501];
int N, M;
int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};

int dfs(int x, int y){
    if(cache[y][x]!=-1) return cache[y][x];
    if(x==(M-1) && y==(N-1)) return 1;
    int cur =0;

    for(int i =0; i<4; i++){
        int nx = x+mvx[i];
        int ny = y+mvy[i];

        if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
        if(map[y][x]<=map[ny][nx]) continue;
        cur+=dfs(nx, ny);
    }

    return cache[y][x] = cur;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++)
            cin >> map[i][j];

    for(int i =0; i<501; i++)
        fill(cache[i], cache[i]+501, -1);

    cout << dfs(0,0) << "\n";

    return 0;
}