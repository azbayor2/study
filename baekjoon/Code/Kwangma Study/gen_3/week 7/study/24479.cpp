#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> s;
int countt =0;
int visit_num[100001];
bool visited[100001];

int N, E, S;
vector<int> e[100001];

bool sort_desc(int a, int b){
    if(a>b) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> E >> S;

    int a, b;
    for(int i =0; i<E; i++){
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for(int i =0; i<100001; i++)
        sort(e[i].begin(), e[i].end(), sort_desc);

    s.push(S);

    while(s.size()){
        int cur = s.top(); s.pop();
        if(visited[cur]) continue;
        visited[cur]=1;
        visit_num[cur] = ++countt;

        for(int next: e[cur]){
            if(visited[next]) continue;
            s.push(next);
        }
    }

    for(int i =1; i<=N; i++)
        cout << visit_num[i] << "\n";

    return 0;
}