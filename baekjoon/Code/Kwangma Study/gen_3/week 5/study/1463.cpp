#include <iostream>

using namespace std;

#define MAX 100000000

int dp[1000001], N;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp[2] = 1; dp[3] = 1;

    for(int i=4; i<=N; i++){
        //a에는 -1했을 때, b는 2로 나눌 때, c는 3으로 나눌 때
        int a = MAX, b = MAX, c = MAX;
        a = dp[i-1]+1;
        b = i%2==0 ? dp[i/2]+1: b;
        c = i%3==0 ? dp[i/3]+1: c;

        //최솟값 저장
        dp[i] = min(a, min(b,c));
    }

    cout << dp[N] << "\n";

    return 0;
}