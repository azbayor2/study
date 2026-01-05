#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
vector<P> e[1001];
int N, M, a, b, c;

int * prev_node;
int max_sum = 1<<28;
int INF = 1<<28;

void dijkstra(int start){
    int arr[1001];
    int *prev = new int[1001];
    prev[start] = 0;
    fill(arr, arr+1001, INF);
    arr[start] = 0;
    priority_queue<P> q;

    q.push({0,start});

    while(q.size()){
        int cur = q.top().second;
        int cur_dist = -q.top().first; q.pop();

        if(cur_dist>arr[cur]) continue;
        for(P n: e[cur]){
            int next = n.first;
            int next_dist = cur_dist+n.second;

            if(next_dist>=arr[next]) continue;
            prev[next] = cur;
            arr[next] = next_dist;
            q.push({-next_dist, next});
        }
    }
    prev_node = prev;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<M; i++){
        cin >> a >> b >> c;
        e[a].push_back({b,c});
        e[b].push_back({a, c});
    }
    dijkstra(1);

    cout << N-1 << "\n";

    for(int i =1; i<=N; i++){
        if(prev_node[i]==0) continue;
        cout << i << " " << prev_node[i] << "\n";
    }

    return 0;
}
