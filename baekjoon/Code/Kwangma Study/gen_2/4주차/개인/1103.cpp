#include <iostream>

using namespace std;

bool visited[51][51];
int cache[51][51];
int board[51][51];
int N, M;

int mv_x[4] = {0,1,0,-1};
int mv_y[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
    int &p = cache[y][x];
    if(p!=0)
        return p;
        
    visited[y][x] = 1;
    int num = board[y][x];
    
    for(int i =0; i<4; i++)
    {
        int nextx = x + num*mv_x[i];
        int nexty = y + num*mv_y[i];
        
        if(nextx<0 || nextx>=M || nexty<0 || nexty>=N || board[nexty][nextx]==0)
        {
            p = (p==-1) ? p : max(p, 1);
            continue;
        }
        
        if(visited[nexty][nextx])
        {
            p =-1;
            visited[y][x] = 0;
            return p;
        }
        
        int res = dfs(nextx, nexty);
        p = (res==-1)? -1: max(p, res+1);
        
        if(p==-1) return p;
    }
    
    visited[y][x]=0;
    return p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    char input;
    
    cin >> N >> M;
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++)
        {
            cin >> input;
            board[i][j] = (input=='H') ? 0: input-'0';
        }
        
    cout << dfs(0,0) << "\n";
    
    return 0;
    
}