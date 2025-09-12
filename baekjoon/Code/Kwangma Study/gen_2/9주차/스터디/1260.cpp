//정연
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> v[1001];
bool visited[2][1001], is_in[1001][1001]; int N, M, K, a, b;
bool rev_comp(int a, int b){
    if(a>b) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        if(is_in[a][b]) continue;
        v[a].push_back(b); v[b].push_back(a); is_in[a][b]=1; is_in[b][a]=1;
    }
    for(int i =1; i<=N; i++) sort(v[i].begin(), v[i].end(), rev_comp);
    stack<int> s; queue<int> q;
    s.push(K); q.push(K); visited[1][K]=1;
    while(s.size()!=0){
        int cur = s.top(); s.pop(); if(visited[0][cur]) continue;
        cout << cur << " ";
        visited[0][cur]=1;
        for(int next: v[cur]){
            s.push(next);
        }
    } cout << "\n"; for(int i =1; i<=N; i++) sort(v[i].begin(), v[i].end());
    while(q.size()!=0){
        int cur = q.front(); q.pop(); cout << cur << " ";
        for(int next: v[cur]){
            if(visited[1][next]) continue;
            q.push(next); visited[1][next]=1;
        }
    }
    return 0;
}