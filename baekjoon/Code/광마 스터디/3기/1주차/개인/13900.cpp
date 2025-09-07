#include <iostream>
using namespace std;

typedef long long ll;

ll arr[100001], sum[100001], N, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    
    for(int i =N; i>1; i--){
        ans+=(arr[i]*sum[i-1]);
    }
    
    cout << ans << "\n";
    
    return 0;
}