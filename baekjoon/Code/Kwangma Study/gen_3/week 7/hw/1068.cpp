#include <iostream>
#include <vector>

using namespace std;

int N, E, R;
vector<int> e[51];
int ans =0;
bool visited[51];

void dfs(int cur){
    visited[cur]=1;
    int leaf_count=0;
    for(int next: e[cur]){
        if(next==E) continue;
        leaf_count++;
        dfs(next);
    }
    if(leaf_count==0) ans++;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int b;
    for(int i =0; i<N; i++){
        cin >> b;
        if(b==-1){
            R = i;
            continue;
        }
        e[b].push_back(i);
    }

    cin >> E;
    if(E==R) cout << 0 << "\n";
    else{
        dfs(R);
        cout << ans << "\n";
    }

    return 0;
}