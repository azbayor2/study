#include <iostream>

using namespace std;

int dp[101][100001];
pair<int, int> input[101];
int N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int a, b;
    for(int i =1; i<=N; i++){
        cin >> a >> b;
        input[i] = {a,b};
    }

    for(int i = 1; i<=K; i++){
        for(int j =1; j<=N; j++){
            if(i-input[j].first<0){
                dp[j][i]= dp[j-1][i];
                continue;
            }
            dp[j][i] = max(dp[j-1][i], input[j].second+dp[j-1][i-input[j].first]);
        }
    }

    cout << dp[N][K] << "\n";

    return 0;
}