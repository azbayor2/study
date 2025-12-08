#include <iostream>
#include "Graph.hpp"
#include <vector>

using namespace std;

void func(int cur){
    cout << cur << endl;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e, a, b, c;
    vector<vector<int>> cost;
    Graph<int> g;

    cin >> v >> e;
    cost.resize(v);

    for(int i =0; i<v; i++)
        cost[i].resize(v);
    
    for(int i =0; i<v; i++)
        g.add_vertex(i);

    for(int i =0; i<e; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        g.add_edge(a, b);
    }

    bfs(g, func, 0);
    dfs(g, func, 0);
    dijkstra(g, cost, 0);


    return 0;
}