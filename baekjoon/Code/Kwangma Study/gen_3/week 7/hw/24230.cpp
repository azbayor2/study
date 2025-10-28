#include <iostream>
#include <vector>

using namespace std;

vector<int> e[200001];
int color[200001];
bool visited[200001];
int ans =0;
int N;

void dfs(int cur, int col){
    int nextc = col;
    visited[cur]=1;
    if(col!=color[cur]){
        ans++;
        nextc = color[cur];
    }

    for(int next: e[cur]) if(!visited[next]) dfs(next, nextc);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i =1; i<=N; i++) cin >> color[i];
    int a, b;
    for(int i =0; i<N-1; i++){
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans << "\n";

    return 0;
}