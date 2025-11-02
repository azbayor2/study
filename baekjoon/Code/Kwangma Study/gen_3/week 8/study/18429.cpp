#include <iostream>

using namespace std;

bool used[9];
int weight[9];
int N, K, ans;

void dfs(int count, int w){
    if(w<500) return;  //현재 중량이 500 밑으로 떨어지면 안됨
    if(count==N){    //N일이 지났을 때
        ans++; return;
    }
    for(int i =1; i<=N; i++){ 
        if(used[i]) continue;  //사용한 운동기구면 패스
        used[i]=1; dfs(count+1, w-K+weight[i]);  //사용표시, 현재-근손실+근증감
        used[i]=0;  //사용 표시 되돌리기 (백트래킹)
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    int a;
    for(int i =1; i<=N; i++){
        cin >> a; weight[i]=a;
    }

    for(int i =1; i<=N; i++){
        used[i]=1; //사용표시
        dfs(1, 500-K+weight[i]);  //1일차일 때
        used[i]=0; //백트래킹
    }

    cout << ans << "\n";

    return 0;
}