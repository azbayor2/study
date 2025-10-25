#include <iostream>

using namespace std;

int dp[10001];
int coin[101], N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i =0; i<N; i++) cin >> coin[i];
    dp[0]=1;
    for(int i =0; i<N; i++){
        for(int j =1; j<=K; j++){
            if(j-coin[i]<0) continue;
            dp[j]+=dp[j-coin[i]];
        }
    }
    cout << dp[K] << "\n";


    return 0;
}