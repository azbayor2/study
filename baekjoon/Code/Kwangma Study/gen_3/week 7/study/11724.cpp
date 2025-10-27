#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, E;
vector<int> e[1001];
bool visited[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> E;
    int a, b;
    for(int i =0; i<E; i++){
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    stack<int> s;
    
    int count = 0;
    for(int i =1; i<=N; i++){
        if(visited[i]) continue;
        count++;
        s.push(i);
        while(s.size()){
            int cur = s.top(); s.pop();
            if(visited[cur]) continue;
            visited[cur]=1;
            for(int next: e[cur]){
                if(visited[next]) continue;
                s.push(next);
            }
        }
    }

    cout << count << "\n";

    return 0;
}
