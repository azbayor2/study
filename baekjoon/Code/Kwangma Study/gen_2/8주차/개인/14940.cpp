#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001], N, M, ans[1001][1001];
queue<pair<int, int>> q;
pair<int, int> start;
int mvx[4]={-1,0,1,0}; int mvy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j =0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]==2) start = {j, i};
        }
    q.push(start);
    while(q.size()!=0){
        pair<int, int> cur = q.front(); q.pop();
        for(int i =0; i<4; i++){
            pair<int, int> next = {cur.first+mvx[i], cur.second+mvy[i]};
            if(next.first<0 ||next.first>=M || next.second<0 || next.second>=N) continue;
            if(ans[next.second][next.first]!=0 || next==start || arr[next.second][next.first]==0) continue;
            ans[next.second][next.first]=ans[cur.second][cur.first]+1;
            q.push(next);
        }
    }
    arr[start.second][start.first]=0;
    for(int i=0; i<N; i++){
        for(int j =0; j<M; j++)
            cout << (ans[i][j]!=0 ? ans[i][j] : (arr[i][j]==0 ? 0:-1) )<< " ";
        cout << "\n";
    }
    return 0;
}
