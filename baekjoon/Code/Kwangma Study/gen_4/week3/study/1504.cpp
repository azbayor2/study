#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, E, u, v;
typedef pair<int, int> P;
vector<pair<int, int>> cost[801];
int INF = 1<<28;

int * dijkstra(int start){
    int * dist = new int[801];
    fill(dist, dist+801, INF);

    dist[start]=0;
    priority_queue<P> q;

    q.push({0,start});

    while(q.size()){
        int cur = q.top().second;
        int cdist = -q.top().first; q.pop();

        if(cdist>dist[cur]) continue;

        for(P next: cost[cur]){
            int next_p = next.first;
            int nextdist = cdist+next.second;

            if(nextdist>=dist[next_p]) continue;
            dist[next_p] = nextdist;
            q.push({-nextdist, next_p});
        }
    }

    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> E;
    int a, b, c;
    for(int i =0; i<E; i++){
        cin >> a >> b >> c;
        cost[a].push_back({b,c});
        cost[b].push_back({a,c});
    }
    cin >> u >> v;

    int * d1 = dijkstra(1);   //1기준
    int * d2 = dijkstra(u);  //u 기준
    int * d3 = dijkstra(v);   //v 기준

    //1. 1 - u - v - N
    int dist_d1 = d1[u] + d2[v] + d3[N];

    //2. 1 - v - u - N
    int dist_d2 = d1[v] + d3[u] + d2[N];


    cout << (min(dist_d1, dist_d2) >= INF ? -1: min(dist_d1, dist_d2)) << "\n";

    return 0;
}