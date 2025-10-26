#include <iostream>

using namespace std;

typedef long long ll;

ll dp[31];
ll dp2[31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[0]=1; dp[1]=1; dp[2]=3;
    for(int i =3; i<=30; i++)
        dp[i] = dp[i-1] + dp[i-2]*2;

    dp2[0] = 1; dp2[1] = 1; dp2[2] = 3; dp2[3] = 1;
    for(int i =4; i<=30; i++)
        dp2[i] = dp2[i-2] + dp2[i-4]*2;

    int a;
    cin >> a;
    cout << (dp[a]-dp2[a])/2 + dp2[a] << "\n";

    return 0;
}