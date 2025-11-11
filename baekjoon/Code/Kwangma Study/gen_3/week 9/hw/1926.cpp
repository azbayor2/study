#include <iostream>
#include <queue>

using namespace std;

bool arr[501][501];
int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};
int N, M;
int countt, mmax;
typedef pair<int, int> pp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++) cin >> arr[i][j];

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            if(!arr[i][j]) continue;
            countt++;
            int cur_size=1;
            queue<pair<int, int>> q;
            q.push({j,i}); arr[i][j]=0;
            while(q.size()){
                pp cur = q.front(); q.pop();
                for(int i=0; i<4; i++){
                    pp next = {cur.first+mvx[i], cur.second+mvy[i]};
                    if(next.first<0 || next.first>=M || next.second<0 || next.second>=N) continue;
                    if(!arr[next.second][next.first]) continue;
                    q.push(next); arr[next.second][next.first]=0;
                    cur_size++;
                }
            }

            mmax = max(mmax, cur_size);
        }
    }

    cout << countt << "\n" << mmax << "\n";


    return 0;
}