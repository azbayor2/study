#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int> q; int N, input;
    cin >> N;
    for(int i =0; i<N; i++){
        cin  >> input;
        switch(input){
            case 0:{ cout << (q.size()!=0 ? q.top() : 0)<< "\n"; if(q.size()!=0) q.pop(); break;}
            default:{ q.push(input); break;}
        }
    }
    return 0;
}