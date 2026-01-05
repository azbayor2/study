#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
vector<P> e[10001];
int N, M, a, b, c;

int INF = 1<<28;

int dijkstra(int start){
    int arr[10001];
    fill(arr, arr+10001, INF);
    arr[start] = 0;
    priority_queue<P> q;

    q.push({0,start});

    while(q.size()){
        int cur = q.top().second;
        int cur_dist = -q.top().first; q.pop();
        if(cur==N) continue;

        if(cur_dist>arr[cur]) continue;

        for(P n: e[cur]){
            int next = n.first;
            int next_dist = cur_dist+n.second;
            if(next>N) continue;

            if(next_dist>=arr[next]) continue;
            arr[next] = next_dist;
            q.push({-next_dist, next});
        }

        if(arr[cur+1]<=cur_dist+1) continue;
        q.push({-(cur_dist+1), cur+1});
        arr[cur+1] = cur_dist+1;
        continue;
    }
    return arr[N];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i =0; i<M; i++){
        cin >> a >> b >> c;
        e[a].push_back({b,c});
    }

    cout << dijkstra(0) << "\n";

    return 0;
}
