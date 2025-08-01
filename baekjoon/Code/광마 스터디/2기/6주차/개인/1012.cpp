#include <iostream>
#include <queue>

using namespace std;

bool arr[51][51];
bool visited[51][51];
int mvx[4] = {1,-1,0,0};
int mvy[4] = {0,0,1,-1};


int T, a, b, ans, N, M, k;

void init()
{
    ans=0;
    for(int i =0; i<50; i++)
        for(int j =0; j<50; j++)
        {
            arr[i][j] = 0; visited[i][j]=0;
        }
        
    N=0; M=0; k=0;
    return;
}

void bfs(int x, int y)
{
    queue<pair<int , int>> q;
    q.push(make_pair(x,y));
    visited[y][x] = 1;
    
    while(q.size()!=0)
    {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i =0; i<4; i++)
        {
            int nx = cx+mvx[i];
            int ny = cy+mvy[i];
            
            if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
            if(arr[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            
            q.push(make_pair(nx, ny));
            visited[ny][nx]=1;
        }
    }
    
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    cin >> T;
    
    for(int i =0; i<T; i++)
    {
        init();
        cin >> M >> N >> k;
        for(int j=0; j<k; j++)
        {
            cin >> a >> b;
            arr[b][a] = 1;
        }
        
        for(int j=0; j<N; j++)
            for(int l=0; l<M; l++)
            {
                if(visited[j][l]==1 || arr[j][l]==0) continue;
                
                ans++;
                bfs(l,j);
            }
            
        cout << ans << "\n";
    }
}