#include <iostream>
using namespace std;

int t[100], p[100], N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans[100] ={0, };
    cin >> N;

    for(int i =1;i<=N; i++){
        cin >> t[i] >> p[i];
    }

    for(int i =N; i>=1; i--){
        if(i+t[i]-1>N) ans[i] = ans[i+1];
        else ans[i] = max(ans[i+t[i]]+p[i], ans[i+1]);
    }

    cout << ans[1] << "\n";

    return 0;
}