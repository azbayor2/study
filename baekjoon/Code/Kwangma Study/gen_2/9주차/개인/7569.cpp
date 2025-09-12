#include <iostream>
#include <queue>
using namespace std;
typedef struct{
    int x; int y; int z;
} coord;
int arr[101][101][101], ans=1, N, M, H, to_riped;  //zyx
int mvx[6]={0,1,0,-1,0,0}, mvy[6]={1,0,-1,0,0,0}, mvz[6]={0,0,0,0,1,-1};
queue<coord> q;

int main(){
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    for(int h=0; h<H; h++)
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
            {
                cin >> arr[h][i][j];
                if(arr[h][i][j]==1) q.push({j, i, h});
                if(arr[h][i][j]==0) to_riped++;
            }
    while(q.size()!=0){
        coord cur= q.front(); q.pop();
        for(int i =0; i<6; i++){
            coord next = {cur.x+mvx[i], cur.y+mvy[i], cur.z+mvz[i]};
            if(next.x<0 || next.x>=M || next.y<0 || next.y>=N || next.z<0 || next.z>=H) continue;
            if(arr[next.z][next.y][next.x]!=0) continue;
            ans = arr[cur.z][cur.y][cur.x]+1; to_riped--;
            arr[next.z][next.y][next.x] = ans; q.push(next);
        }
    }
    cout << (to_riped==0? ans-1 : -1) << "\n";
    return 0;
}