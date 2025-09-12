#include <iostream>
#include <queue>
using namespace std;

char saved[4] = {'D','L','R','S'};

int s, e, T;

int D(int cur){
    return (cur*2)%10000;
}

int L(int cur){
    int temp = cur/1000;
    cur = cur*10+temp;
    return cur%10000;
}

int R(int cur){
    int temp = cur%10;
    cur = cur/10+(temp*1000);
    return cur%10000;
}

int S(int cur){
    cur--;
    return cur<0 ? cur+10000 : cur;
}

int (*calc[4])(int) = {D, L, R, S};

void game(){
    cin >> s >> e;
    queue<pair<int, string>> q;
    string str;
    q.push({s, str});
    bool visited[10001] = {0,};
    visited[s]=1;
    
    while(q.size()!=0){
        int cur = q.front().first;
        string curs = q.front().second; q.pop();
        for(int i =0; i<4; i++){
            int next = calc[i](cur);
            if(visited[next]) continue;
            if(next==e){
                cout << curs+saved[i] << "\n"; return;
            }
            q.push({next, curs+saved[i]}); visited[next]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i =0; i<T; i++) game();
    return 0;
}