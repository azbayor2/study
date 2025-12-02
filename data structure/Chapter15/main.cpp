#include <iostream>
#include "digraph.hpp"
#include <vector>

using namespace std;

void func(int v){

    cout << v << endl;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int vertices, edges, a, b, cost;

    cin >> vertices >> edges;
    graph<int> g;
    vector<vector<int>> weight;
    weight.resize(100);
    for(int i =0; i<100; i++)
        weight[i].resize(100);

    for(int i =0; i<vertices; i++)
        g.add_vertex(i);

    for(int i =0; i<edges; i++){
        cin >> a >> b >> cost;
        g.add_edge(a, b);
        weight[a][b] = cost;
    }

    int * res = NULL;
    int * path = NULL;

    dijkstra(g, 0, weight, res, path);

    for(int i =0; i<vertices; i++){
        int start = i;
        while(1){
            cout << start << " ";
            if(start==0) break;
            start = path[start];
        }

        cout << "length: " << res[i] << "\n";
    }

    cout << endl << endl;

    cout << "dfs: " << endl;
    dfs(func, g, 0);

    cout << endl << endl;

    cout << "bfs: " << endl;
    bfs(func, g, 0);

    return 0;
}