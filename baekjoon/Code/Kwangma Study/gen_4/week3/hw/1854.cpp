#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K, a, b, c;
typedef long long ll;
vector<pair<int, ll>> v[1001];

void dijkstra(priority_queue<ll> *& in){
    priority_queue<pair<ll, int>> q;
    priority_queue<ll> * dist = new priority_queue<ll>[1001];

    dist[1].push(0);
    q.push({0,1});

    while(q.size()){
        int cur = q.top().second;
        ll cur_dist = -q.top().first;
        q.pop();

        for(pair<int, ll> n: v[cur]){
            int next = n.first;
            ll next_dist = cur_dist + n.second;

            if(dist[next].size()<K){
                q.push({-next_dist, next});
                dist[next].push(next_dist);
                continue;
            } else if(dist[next].top()>next_dist){
                dist[next].pop();
                q.push({-next_dist, next});
                dist[next].push(next_dist);
            }
        }
    }

    in = dist;
    return;
}

int main(){
    cin >> N >> M >>K;
    for(int i =0; i<M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    priority_queue<ll> * q;

    dijkstra(q);

    for(int i =1; i<=N; i++){
        cout << (q[i].size()==K ? q[i].top(): -1) << "\n";
    }

    return 0;
}