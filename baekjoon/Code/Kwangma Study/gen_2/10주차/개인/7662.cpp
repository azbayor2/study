#include <iostream>
#include <queue>
#include <map>

using namespace std;
long long T, N, input;
char args;

void game(){
    priority_queue<long long> q[2];  // 0: 최대  1: 최소
    map<long long, int> m[2];
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> args; cin >> input;
        if(args=='I'){
            q[0].push(input); q[1].push(-input);
        }
        else if(args=='D'){
            if(input==-1){
                while(q[1].size()!=0){
                    if(m[1].find(-q[1].top())==m[1].end() || m[1][-q[1].top()]==0) break;
                    m[1][-q[1].top()]--; q[1].pop();
                }
                if(q[1].size()!=0){
                    m[0][-q[1].top()]++; q[1].pop();
                }
            }
            
            else if(input==1){
                while(q[0].size()!=0){
                    if(m[0].find(q[0].top())==m[0].end() || m[0][q[0].top()]==0) break;
                    m[0][q[0].top()]--; q[0].pop();
                }
                if(q[0].size()!=0){
                    m[1][q[0].top()]++; q[0].pop();
                }
            }
        }
    }
    while(q[1].size()!=0){
        if(m[1].find(-q[1].top())==m[1].end() || m[1][-q[1].top()]==0) break;
        m[1][-q[1].top()]--; q[1].pop();
    }
    while(q[0].size()!=0){
        if(m[0].find(q[0].top())==m[0].end() || m[0][q[0].top()]==0) break;
        m[0][q[0].top()]--; q[0].pop();
    }
    
    if(q[0].size()==0 || q[1].size()==0){
        cout << "EMPTY" << "\n"; return;
    }
    
    else{
        cout << q[0].top() << " " << -q[1].top() << "\n";
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i =0; i<T; i++)
        game();
    return 0;
}