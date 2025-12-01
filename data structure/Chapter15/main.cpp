#include <iostream>
#include "digraph.hpp"
#include <vector>

using namespace std;

int main(){
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

<<<<<<< HEAD
    int * res = NULL;
    int * path = NULL;
=======
    g.neighbors(0);

    int *res=nullptr;
>>>>>>> 59009ea83a995512c8907c1c027fff7cbef579f5

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

    cout << endl;

    return 0;
}