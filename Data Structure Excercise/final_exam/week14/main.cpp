#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(){
    Graph<string> g;

    g.add_vertex("민수");
    g.add_vertex("지향");
    g.add_vertex("문정");
    g.add_vertex("지현");
    g.add_vertex("이상");
    g.add_vertex("성민");
    g.add_vertex("시은");

    g.add_edge(0,1,2);
    g.add_edge(0,2,9);
    g.add_edge(0,4,7);
    g.add_edge(1,3,3);
    g.add_edge(1,6,3);
    g.add_edge(3,0,5);
    g.add_edge(3,5,3);
    g.add_edge(3,6,1);
    g.add_edge(4,2,1);
    g.add_edge(4,5,10);

    DFS(g, 0);
    cout << endl;

    BFS(g, 0);
    cout << endl;

    dijkstra(g, 0);
    cout << endl;

    return 0;
}