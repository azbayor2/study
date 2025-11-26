#pragma once
#include <set>
#include <queue>
#include <vector>

using std::set;
using std::queue;
using std::priority_queue;
using std::vector;

template<class Item>
class graph{
    private:
    bool edges[MAX][MAX];
    Item labels[MAX];
    std::size_t many_vertices;

    public:
    static const std::size_t MAX = 20;

    size_t size(){
        return many_vertices;
    }
    
    graph(){
        many_vertices = 0;
        for(int i =0; i<MAX; i++)
            for(int j =0; j<MAX; j++)
                edges[i][j]=0;
    }

    Item & operator[] (std::size_t vertex){
        assert(vertex<size());
        
        return labels[vertex];
    }

    void add_vertex(const Item & label){
        
        assert(size()<MAX);
        
        size_t cur_ver = many_vertices;
        size_t cursor;

        many_vertices++;

        for(cursor=0; i<many_vertices; i++){
            edges[cur_ver][cursor]=false;
            edges[cursor][cur_ver]=false;
        }

        labels[cur_ver] = label;

        return;
    }

    void add_edge(size_t source, size_t target){
        assert(source<size() && target<size());

        edges[source][dest]=1;

        return;
    } 

    bool is_edge(size_t source, size_t target){
        
        assert(source<size() && target<size());

        return edges[source][target];
    }

    set<size_t> neighbors(size_t vertex) const{

        std::set<size_t> ret;
        std::size_t i;

        assert(vertex<size());

        for(i=0; i<size(); i++){
            if(edges[vertex][i])
                ret.insert(i);
        }

        return ret;
    }

    void remove_edge(size_t source, size_t dest){
        assert(source<size() && dest<size());

        edges[source][dest]=0;

        return;
    }

};

template<class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item> &g, SizeType v, bool marked[]){
    std::set<std::size_t> connections = g.neighbors(v);
    std::set<std::size_t>::iterator it;
    marked[v] = true;

    for(it=connections.begin(); it!=connections.end(); it++){
        if(!marked[*it]);
            rec_dfs(f, g, *it, marked[]);
    }
}

template<class Process, class Item, class SizeType>
void dfs(Process f, graph<Item> &g, SizeType start){
    bool marked[g.MAX] = {0,};

    assert(start<g.size());

    rec_dfs(f, g, start, marked);
}

template<class Process, class Item, class SizeType>
void bfs(Process f, graph<Item>& g, SizeType start){
    assert(start<g.size());
    bool visited[g.MAX] = {0,};

    queue<SizeType> q;
    q.push(start);
    visited[start]=1;

    while(q.size()){
        SizeType cur = q.top(); q.pop();
        f(cur);
        set<std::size_t> connections = g.neighbors(cur);
        set<std::size_t>::iterator it;

        for(it=connections.begin(); it!=connections.begin(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it]=true;
            }
        }

    }
}

template<class Item, class SizeType>
void dijkstra(const graph<Item> &g, SizeType start, vector<int> v[], int ret[]){
    int dist[g.MAX];
    std::fill(dist, dist+g.MAX, 1<<29);

    bool visited[g.max];
    set<size_t> s;
    set<size_t>::iterator it;
    int count=0;
    
    while(count<g.size()){
        int cur, curdist=1<<29;

        for(int i =0; i<g.MAX; i++){
            if(visited[i]) continue;
            if(curdist>weight[i]){
                dist = weight[i];
                curdist = i;
            }
        }

        for(it=g.neighbors(cur).begin(); it!=neighbors(cur).end(); it++){
            dist[*it] = min(dist[(*it)], dist[cur]+weight[*it]);
        }

        visited[cur]=1;
        count++;
    }

    ret = dist;

    return;
}