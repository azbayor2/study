#include <iostream>
#include <vector>

using namespace std;

vector<int> e[2001];
bool visited[2001];
int N, M;
int max_depth = 0;

void dfs(int cur, int depth){
    visited[cur]=1;
    max_depth = max(max_depth, depth);
    if(max_depth>=4) return;
    
    for(int next: e[cur]){
        if(!visited[next]){
            dfs(next, depth+1);
        }
    }
    visited[cur]=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    int a, b;
    for(int i =0; i<M; i++){
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for(int i =0; i<N; i++){
        dfs(i, 0);
    }

    cout << (max_depth>=4 ? 1 : 0) << "\n";

    return 0;
}