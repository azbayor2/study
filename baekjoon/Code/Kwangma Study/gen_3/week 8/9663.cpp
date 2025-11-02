#include <iostream>
#include <queue>

using namespace std;

bool visit[16][16];
int mvx[3] = {1,1,1};  //오른쪽, 윗대각선, 아랫대각선
int mvy[3] = {1,0,-1};
int N, ans;

void dfs(int x, int y){
    if(x==(N-1)){
        ans++;
        return;
    }
    queue<pair<int, int>> q;

    
    for(int j =0; j<3; j++){  //x,y에 뒀을 때 방문할 수 없는 좌표 저장
        for(int i =1; i<N; i++){
            int nx = x + mvx[j]*i;
            int ny = y + mvy[j]*i;
            if(nx>=N || nx<0 || ny>=N || ny<0) break;
            if(visit[ny][nx]) continue;
            visit[ny][nx]=1;
            q.push({nx, ny});  //백트래킹을 위해 저장
        }
    }
    

    for(int i =0; i<N; i++){ //방문할 수 있으면 dfs진행
        if(!visit[i][x+1]) dfs(x+1, i);  
    }

    while(q.size()){  //백트래킹
        pair<int, int> cur = q.front(); q.pop();
        visit[cur.second][cur.first]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =0; i<N; i++) dfs(0,i);

    cout << ans << "\n";

    return 0;
}
