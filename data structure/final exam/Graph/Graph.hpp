#pragma once
#include <set>
#include <queue>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::size_t;
using std::set;
using std::queue;

template<class Item>
class Graph{
    public:

    static const int MAX=100;

    private:

    bool edges[MAX][MAX];
    Item labels[MAX];
    size_t num_vertices;

    public:

    Graph(){
        num_vertices = 0;
        for(int i=0; i<MAX; i++)
            for(int j =0; j<MAX; j++)
                edges[i][j]=0;
    }

    void add_vertex(const Item & label){
        assert(num_vertices<MAX);
        
        int new_vertex = num_vertices;

        for(int i =0; i<MAX; i++){
            edges[i][new_vertex]=0;
            edges[new_vertex][i]=0;
        }

        labels[new_vertex] = label;
        num_vertices++;
    }

    void add_edge(size_t src, size_t dest){
        assert(src<num_vertices && dest<num_vertices);

        edges[src][dest]=1;
    }

    set<size_t> get_neighbors(size_t v){
        assert(v<num_vertices);
        
        set<size_t> ret;
        for(int i =0; i<num_vertices; i++){
            if(edges[v][i])
                ret.insert(i);
        }

        return ret;
    }

    void remove_edge(size_t src, size_t dest){
        assert(src<num_vertices && dest<num_vertices);

        edges[src][dest]=0;

        return;
    }

    Item & operator[](size_t vertex){
        assert(vertex<num_vertices);

        return labels[vertex];
    }

    bool is_edge(size_t src, size_t dest){
        assert(src<num_vertices && dest<num_vertices);

        return edges[src][dest];
    }

    size_t size(){
        return num_vertices;
    }
};

template<class Item, class Process>
void real_dfs(Graph<Item> &g, Process f, size_t cur, bool visited[]){
    visited[cur] = 1;

    f(cur);

    set<size_t> neighbors = g.get_neighbors(cur);
    set<size_t>::iterator it;


    for(it = neighbors.begin(); it!=neighbors.end(); it++){
        if(visited[*it]) continue;

        real_dfs(g, f, *it, visited);
    }

    return;
}

template<class Item, class Process>
void dfs(Graph<Item> &g, Process f, size_t begin){
    assert(begin<g.size());

    bool visited[g.MAX] = {0, };

    real_dfs(g, f, begin, visited);
    std::cout << "\n";

    return;
}

template<class Item, class Process>
void bfs(Graph<Item> &g, Process f, size_t begin){
    assert(begin<g.size());

    queue<size_t> q;
    bool visited[g.MAX] = {0, };
    q.push(begin);

    visited[begin]=1;

    while(q.size()!=0){
        size_t cur = q.front(); q.pop();
        f(cur);

        set<size_t> neighbors = g.get_neighbors(cur);
        set<size_t>::iterator it;

        for(it=neighbors.begin(); it!=neighbors.end(); it++){
            if(visited[*it]) continue;

            visited[*it]= true;
            q.push(*it);
        }
    }

    std::cout << "\n";

    return;
}

template<class Item>
void dijkstra(Graph<Item> &g, vector<vector<int>> & cost, int start){
    bool visited[g.MAX] = {0, };
    int dist[g.MAX];
    std::fill(dist, dist+g.MAX, 1<<29);
    int path[g.MAX] = {0, };

    path[start] = start;
    dist[start] = 0;

    int count = 0;

    while(count<g.size()){
        //가장 짧은 것 찾기

        int cur_ver = 0;
        int cur_dist = 1<<29;

        for(int i =0; i<g.size(); i++){
            if(visited[i]) continue;
            if(cur_dist>dist[cur_ver]){
                cur_ver = i;
                cur_dist = dist[i];
            }
        }


        // 방문 처리하기
        visited[cur_ver] = 1;

        //이웃한 점

        set<size_t> neighbors = g.get_neighbors(cur_ver);
        set<size_t>::iterator it;

        for(it=neighbors.begin(); it!=neighbors.end(); it++){
            int next = *it;
            int next_dist = cur_dist + cost[cur_ver][*it];

            if(dist[next]>next_dist){
                dist[next] = next_dist;
                path[next] = cur_ver;
            }
        }

        count++;
    }


    for(int i =0; i<g.size(); i++)
        std::cout << dist[i] << " ";

    std::cout << "\n \n";

    for(int i =0; i<g.size(); i++){
        int cur = i;
        std::cout << i << ": ";

        while(1){
            std:: cout << cur << " ";
            if(cur==start) break;
            cur = path[cur];
        }

        std::cout << "\n";
    }

    return;
}