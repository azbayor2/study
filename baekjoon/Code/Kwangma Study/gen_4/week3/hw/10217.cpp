#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int T, N, M, K, a, b, c, d;
vector<pair<int, pair<int, int>>> e[101];   //end, cost, time
priority_queue<pair<int, pair<int, int>>> q;   //cost, end, time

const int INF = 1<<28;

string dijkstra(){
    
    pair<int, int> dist[101];

    for(int i =0; i<101; i++) dist[i] = {INF, INF};   //cost, time
    dist[1] = {0,0};
    q.push({0,{1,0}});

    while(q.size()){
        int cur = q.top().second.first;
        int cur_time = q.top().second.second;
        int cur_cost = -q.top().first;
        q.pop();
        if(cur_time>dist[cur].second && cur_cost >= dist[cur].first) continue;

        for(pair<int, pair<int, int>> n: e[cur]){
            int next = n.first;
            int next_cost = cur_cost + n.second.first;
            int next_time = cur_time + n.second.second;

            if(next_cost>M) continue;
            if(next_time>dist[next].first) continue;
            if(next_time==dist[next].first && next_cost>=dist[next].second) continue;
            q.push({-next_cost, {next, next_time}});
            dist[next] = {next_cost, next_time};
        }
    }

    return dist[N].first==INF ? "Poor KCM": to_string(dist[N].first);
}

int main(){
    cin >> T;
    for(int i =0; i<T; i++){
        cin >> N >> M >> K;
        for(int i =0; i<K; i++){
            cin >> a >> b >> c >> d;
            e[a].push_back({b, {c,d}});
        }

        cout << dijkstra() << "\n";
    }

    return 0;
}