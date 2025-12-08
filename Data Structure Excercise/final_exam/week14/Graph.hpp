#pragma once
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


template<class Item>
class Graph{
    public:

    static const int MAX = 100;

    private:
    Item labels[MAX];
    int edges[MAX][MAX];
    int vertices_count;

    public:

    Graph(){
        for(int i=0; i<MAX;i++)
            for(int j =0; j<MAX;j++)
                edges[i][j]=0;

        vertices_count=0;
    }

    void add_vertex(Item label){
        labels[vertices_count++] = label;
        return;
    }

    void add_edge(int src, int dest, int cost=1){
        if(src>=vertices_count || dest>=vertices_count) return;
        edges[src][dest]=cost;

        return;
    }

    int size(){
        return vertices_count;
    }

    int is_edge(int src, int dest){
        return edges[src][dest];
    }

    Item get_val(int src){
        return labels[src];
    }
};

template<class Item>
void DFS(Graph<Item> &G, int start){
    bool visited[G.MAX] = {0, };

    stack<int> s;
    s.push(start);

    while(s.size()){
        int cur = s.top(); s.pop();
        if(visited[cur]) continue;
        visited[cur]=true;

        cout << G.get_val(cur) << " ";

        for(int i =G.size()-1; i>=0; i--){
            if(visited[i]) continue;
            if(!G.is_edge(cur, i)) continue;
            s.push(i);
        }
    }

    cout << endl;

    return;
}

template<class Item>
void BFS(Graph<Item> &G, int start){
    bool visited[G.MAX] = {0, };
    queue<int> q;

    q.push(start);
    visited[start]=1;

    while(q.size()){
        int cur = q.front(); q.pop();

        cout << G.get_val(cur) << " ";

        for(int i = 0; i<G.size(); i++){
            if(visited[i]) continue;
            if(!G.is_edge(cur, i)) continue;
            visited[i] = true;
            q.push(i);
        }
    }

    cout << endl;

    return;
}

template<class Item>
void dijkstra(Graph<Item> &G, int start){
    int dist[G.MAX];
    bool visited[G.MAX];

    fill(dist, dist+G.size(), 1<<29);

    dist[start] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, start});

    while(q.size()){
        int curnode = q.top().second;
        int curdist = -q.top().first;
        q.pop();

        if(curdist>dist[curnode]) continue;

        for(int i =0; i<G.size(); i++){
            if(!G.is_edge(curnode, i)) continue;

            int nextdist = curdist+G.is_edge(curnode, i);

            if(nextdist>=dist[i]) continue;
            dist[i] = nextdist;
            q.push({-nextdist, i});
        }
    }

    for(int i =0; i<G.size(); i++)
        cout << dist[i] << " ";

    cout << endl;

    return;
}

