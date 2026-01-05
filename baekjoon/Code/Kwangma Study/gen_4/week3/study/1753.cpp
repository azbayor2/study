#include <iostream>
#include <queue> 
#include <algorithm>
#include <string>

using namespace std;

//typedef long long ll;

vector<pair<int, int>> v[20001];
int V, E, S;

int INF = 1<<28;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> S;

    int a, b, c;

    for(int i =0; i<E; i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    priority_queue<pair<int, int>> q;

    int dist[20001];
    fill(dist, dist+20001, INF);
    dist[S] = 0;
    q.push({0,S});

    while(q.size()){
        int cur = q.top().second;
        int cur_dist = -q.top().first;
        q.pop();

        if(cur_dist>dist[cur]) continue;

        for(auto n: v[cur]){
            int next_dist = n.second + cur_dist;
            int next = n.first;

            if(next_dist>=dist[next]) continue;
            dist[next] = next_dist;
            q.push({-next_dist, next});
        }
    }

    for(int i =1; i<=V; i++){
        cout << (dist[i]==INF ? "INF" : to_string(dist[i])) << "\n";
    }

}
