#pragma once
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class Item>
class Graph{
    public:
    static const int MAX = 100;

    private:
    Item label[MAX];
    int edges[MAX][MAX];
    int num_vertices;

    public:

    Graph(){
        for(int i =0; i<MAX; i++)
            for(int j =0; j<MAX; j++)
                edges[i][j]=0;
        num_vertices=0;
    }

    void add_vertex(Item t){
        if(num_vertices>=MAX) return;

        label[num_vertices++] = t;
        return;
    }

    void add_edge(int src, int dst, int cost){
        edges[src][dst] = cost;
    }

    int is_edge(int src, int dst){
        return edges[src][dst];
    }

    int size(){
        return num_vertices;
    }

    Item get_data(int idx){
        return label[idx];
    }
};

template<class Item>
void DFS(Graph<Item> & g, int start){
    bool visited[g.size()] = {0, };
    stack<int> s;

    s.push(start);

    while(s.size()){
        int cur = s.top(); s.pop();
        if(visited[cur]) continue;
        visited[cur]=true;

        cout << g.get_data(cur) << " ";
        for(int i = g.size()-1; i>=0; i--){
            if(visited[i]) continue;
            if(!g.is_edge(cur, i)) continue;
            s.push(cur);
        }
    }

    cout << endl;

    return;
}

template<class Item>
void BFS(Graph<Item> &g, int start){
    bool visited[g.size()] = {0, };
    queue<int> q;

    q.push(start);
    visited[start]=1;
    while(q.size()){
        int cur = q.front(); q.pop();
        cout << g.get_data(cur) << " ";

        for(int i =0; i<g.size(); i++){
            if(visited[i]) continue;
            if(!g.is_edge(cur, i)) continue;

            q.push(i);
            visited[i]=1;
        }
    }

    cout << endl;

    return;
}

template<class Item>
void dijkstra(Graph<Item> & g, int start){
    bool visited[g.size()] = {0, };
    int prev_node[g.size()];

    int dist[g.size()];
    fill(dist, dist+g.size(), 1<<29);

    dist[start]=0;

    for(int i =0; i<g.size(); i++){
        int cur = -1;
        int cur_dist = 1<<29;

        for(int j =0; j<g.size(); j++){
            if(visited[j]) continue;
            if(cur_dist>dist[j]){
                cur = j;
                cur_dist=dist[j];
            }
        }

        visited[cur] = true;

        for(int j=0; j<g.size(); j++){
            //if(visited[j]) continue;
            if(!g.is_edge(cur, j)) continue;

            int next_dist = cur_dist + g.is_edge(cur, j);

            if(next_dist<dist[j]){
                dist[j] = next_dist;
                prev_node[j]=cur;
            }
        }
    }

    cout << "거리: ";
    for(int i =0; i<g.size(); i++)
        cout << dist[i] << " ";

    cout << endl;

    for(int i =0; i<g.size(); i++){
        cout << g.get_data(i) << "까지 최단 거리: ";

        int cur = i;
        while(cur!=start){
            cout << g.get_data(cur) << " ";
            cur = prev_node[cur];
        }
        cout << g.get_data(cur) << endl;
    }

    return;
}