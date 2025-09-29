#include <iostream>
using namespace std;

int dp[1001][11], N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i =0; i<10; i++) dp[1][i] =1;
    for(int i =2; i<=N; i++)
        for(int j =9; j>=0; j--){
            dp[i][j] = (dp[i][j+1]+dp[i-1][j])%10007;
        }
    int ans = 0;
    for(int i =0; i<10; i++) ans = (ans+dp[N][i])%10007;
    cout << ans << "\n";

    return 0;
}