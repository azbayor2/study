//한정연
#include <iostream>
#include <queue>

using namespace std;

bool arr[51][51];
bool visited[51][51];

int mvx[8] = {0,1,0,-1, 1, 1, -1,-1};
int mvy[8] = {1,0,-1,0, 1,-1, 1, -1};
int N, M;

void init()
{
    for(int i =0; i<51; i++)
        for(int j =0; j<51; j++)
            visited[i][j]=0;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x]=1;
    
    while(q.size()!=0)
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i =0; i<8; i++)
        {
            int nx = cx+mvx[i];
            int ny = cy+mvy[i];
            
            if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
            if(arr[ny][nx]==0) continue;
            
            if(visited[ny][nx]) continue;
            
            visited[ny][nx]=1;
            q.push(make_pair(nx, ny));
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(1)
    {
        cin >> M >> N;
        if(N==0 && M==0) break;
        
        init();
        int ans = 0;
        
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
                cin >> arr[i][j];
                
        queue<pair<int, int>> q;
        
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
            {
                if(visited[i][j] || !arr[i][j]) continue;
                ans++;
                bfs(j, i);
            }
        
        cout << ans << "\n";
    }
    
    return 0;
}