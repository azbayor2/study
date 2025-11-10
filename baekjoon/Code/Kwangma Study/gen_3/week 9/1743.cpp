#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool visited[101][101];
bool map[101][101];
int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};
int ans, N, M, K;
typedef pair<int, int> pp;
vector<pp> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    int a, b;
    for(int i =0; i<K; i++){
        cin >> a >> b;
        v.push_back({b,a});  //쓰레기 위치 저장
        map[a][b] = 1;  //쓰레기 위치 표기
    }

    for(pp cur: v){   //모든 쓰레기에 대해 시도
        if(visited[cur.second][cur.first]) continue;  //방문했으면 스킵
        visited[cur.second][cur.first]=1; //방문처리
        queue<pp> q; q.push(cur);
        int count = 1;

        while(q.size()){ //bfs시행
            pp c = q.front(); q.pop();
            for(int i =0; i<4; i++){
                pp n = {c.first+mvx[i], c.second+mvy[i]};  //다음 좌표 방문
                if(n.first>M || n.second>N || n.first<=0 || n.second<=0) continue;  //지도 안에 있는지 검사
                if(!map[n.second][n.first]) continue;  //방문 할 수 있는지 검사
                if(visited[n.second][n.first]) continue;  //방문 했는지 검사

                count++;  //개수 추가
                visited[n.second][n.first]=1;  //방문 처리
                q.push(n);
            }
        }

        ans = max(ans, count);
    }

    cout << ans << "\n";

    return 0;
}