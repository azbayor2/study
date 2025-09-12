#include <iostream>
#include <queue>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

map<int, ll> dist[1001];
int N, M, bb, ee;
vector<int> v[1001];
ll dist_t[1001];

void dijkstra()
{
    priority_queue<pair<ll, int>> q;
    dist_t[bb]=0;
    
    q.push({0,bb});
    
    while(q.size()!=0)
    {
        int cur = q.top().second;
        ll curdist = -q.top().first;
        q.pop();
        if(dist_t[cur]<curdist) continue;
        
        for(int next:v[cur])
        {
            ll nextdist = curdist + dist[cur][next];
            if(dist_t[next]<=nextdist) continue;
            dist_t[next] = nextdist;
            q.push({-nextdist, next});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=0; i<1001; i++)
        dist_t[i] = 10000000000000;
    
    cin >> N >> M;
    ll a, b, c;
    
    for(int i =0; i<M; i++)
    {
        cin >> a >> b >> c;
        if(dist[a].find(b)==dist[a].end())
            v[a].push_back(b);
        
        dist[a][b] = dist[a].find(b)==dist[a].end() ? c: min(dist[a][b], c);
    }
    
    cin >> bb >> ee;
    
    dijkstra();
    
    cout << dist_t[ee] << "\n";
    
    
    return 0;
    
}


