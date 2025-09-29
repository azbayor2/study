#include <iostream>

using namespace std;

//typedef long long ll;

int dp[10001][101];
int coin[101], N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i =0; i<N; i++) cin >> coin[i];
    for(int i =0; i<N; i++) dp[0][i] =1;

    for(int i=1; i<=K; i++){
        for(int j =0; j<N; j++){
            dp[i][j] = ((i-coin[j])>=0) ? dp[i-coin[j]][j] + dp[i][j-1] : dp[i][j-1];
        }
    }
   
    cout << dp[K][N-1] << "\n";

    return 0;
}