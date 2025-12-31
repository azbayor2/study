#include <iostream>

using namespace std;

int dp[1010][1010];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B;

    cin >> A >> B;

    int len_A = A.length();
    int len_B = B.length();

    for(int i =1; i<=len_A; i++)
        for(int j = 1; j<=len_B; j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(A[i-1]==B[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }

    cout << dp[len_A][len_B] << "\n";

    return 0;
}