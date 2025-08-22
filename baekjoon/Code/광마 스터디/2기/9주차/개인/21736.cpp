#include <iostream>
#include <queue>
using namespace std;
string board[601]; int N, M; bool visited[601][601];
pair<int, int> doyeon; queue<pair<int, int>> q;
int mvx[4]={0,1,0,-1}, mvy[4]={-1,0,1,0}, ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> board[i]; int temp = board[i].find('I');
        if(temp!=string::npos) doyeon = { temp, i};
    }
    q.push(doyeon); visited[doyeon.second][doyeon.first]=1;
    while(q.size()!=0){
        pair<int, int> p = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pair<int, int> next = {p.first+mvx[i], p.second+mvy[i]};
            if(next.first<0 || next.first>=M || next.second<0 || next.second>=N) continue;
            if(visited[next.second][next.first]) continue;
            if(board[next.second][next.first]=='X') continue;
            if(board[next.second][next.first]=='P') ans++;
            q.push(next); visited[next.second][next.first]=1;
        }
    }
    if(ans==0) cout << "TT" << "\n"; else cout << ans << "\n";
    return 0;
}