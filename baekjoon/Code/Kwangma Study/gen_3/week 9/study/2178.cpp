#include <iostream>
#include <queue>

using namespace std;

int visited[101][101];
int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};
string map[101];
int N, M, ans;
typedef pair<int, int> pp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for(int i =0; i<N; i++)
        cin >> map[i];

    queue<pp> q;

    visited[0][0]=1;  //방문 처리
    q.push({0,0});

    while(q.size()){
        pp cur = q.front(); q.pop();   //맨 앞 원소 뺴기
        if(cur.second==(N-1) && cur.first==(M-1)) break;  //검사하는 곳이 목표 지점인지 확인
        for(int i =0; i<4; i++){
            pp next = {cur.first + mvx[i], cur.second+ mvy[i]};  //4방면 중 한 곳 방문
            if(next.first>=M || next.first<0|| next.second>=N || next.second<0) continue;  //지도 안에 있는지 검사
            if(map[next.second][next.first]=='0') continue;  //방문할 수 있는 경로인지 검사
            if(visited[next.second][next.first]) continue;  //방문 된 곳인지 검사
            visited[next.second][next.first] = visited[cur.second][cur.first]+1;  //방문 처리
            q.push(next);  //큐에 저장
        }
    }

    cout << visited[N-1][M-1] << "\n";

    return 0;

}