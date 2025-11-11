#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
int arr[301][301];
typedef pair<int, int> pp;
vector<pp> v;
int san=0;
int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};
map<int, int> rel[301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                v.push_back({j,i});
                san++;
            }
        }
    }
    int ttime = 0;

    while(san){
        bool visited[301][301] = {0,};
        queue<pp> b;
        int t_count=0;
        for(pp ppp: v){
            if(!arr[ppp.second][ppp.first]) continue;
            b.push(ppp); break;
            visited[ppp.second][ppp.first]=1;
            t_count++;
        }
        //예외처리 해야함
        while(b.size()){
            pp cur = b.front(); b.pop();
            for(int i =0; i<4; i++){
                pp next = {cur.first+mvx[i], cur.second+mvy[i]};
                if(next.first<0 || next.first>=M || next.second<0 || next.second>=N) continue;
                if(visited[next.second][next.first]) continue;
                if(!arr[next.second][next.first]) continue;

                visited[next.second][next.first]=1;
                t_count++;
                b.push(next);
            }
        }

        if(t_count!=san){
            cout << ttime << "\n";

            return 0;
        }

        ttime++;

        //빙산 없애기
        for(pp cur: v){
            if(!arr[cur.second][cur.first]) continue;
            int o_count = 0;
            for(int i =0; i<4; i++){
                pp side = {cur.first+mvx[i], cur.second+mvy[i]};
                if(side.first<0 || side.first>M || side.second<0 || side.second>=N) continue;
                if(arr[side.second][side.first]) continue;
                o_count++;
            }

            rel[cur.second][cur.first] = o_count;
        }

        for(pp cur: v){
            if(!arr[cur.second][cur.first]) continue;
            int t = arr[cur.second][cur.first] - rel[cur.second][cur.first];
            rel[cur.second][cur.first]=0;
            arr[cur.second][cur.first] = (t>=0 ? t: 0);
            if(arr[cur.second][cur.first]==0) san--;
        }        
    }

    cout << 0 << "\n";

    return 0;
}