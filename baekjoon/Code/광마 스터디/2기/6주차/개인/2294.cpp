#include <iostream>

using namespace std;


int dp[101][10001];
int coin[101];
int N, K;
bool is_in[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    int idx = 0, input=0;
    
    for(int i =0; i<N; i++){
        cin>> input;
        if(is_in[input]) continue;
        coin[idx++] = input;
        is_in[input]=1;
    }
        
    for(int i =0; i<=K; i++)
    {
        if(i%coin[0]==0)
            dp[0][i] = i/coin[0];
        else
            dp[0][i]=-1;
    }
    
    for(int i =1; i<idx; i++)
        for(int j =1; j<=K; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(coin[i]>j) continue;
            int temp = dp[i][j-coin[i]];
            if(temp!=-1 && dp[i-1][j]!=-1)
                dp[i][j] = min(temp+1, dp[i-1][j]);
            else if(temp!=-1)
                dp[i][j] = temp+1;
        }
        
    cout << dp[idx-1][K] << "\n";
    
    return 0;
}