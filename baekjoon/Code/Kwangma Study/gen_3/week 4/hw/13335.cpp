#include <iostream>
#include <queue>
using namespace std;
int N, M, K, arr[1001];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K; for(int i =0; i<N ;i++) cin >> arr[i];
    for(int i =0; i<M;i++) q.push(0);
    int cur=0, count=0, time=0, idx=0;
    while(idx<N){
        if(q.front()!=0){
            count--; cur-=q.front();
        }
        q.pop();

        if(count<M && ((cur+arr[idx])<=K)){
            count++; q.push(arr[idx]); cur+=arr[idx]; idx++;
        } 
        else q.push(0);
        time++;
    }
    while(q.size()!=0){
        time++; q.pop();
    }

    cout << time << "\n";

    return 0;
}