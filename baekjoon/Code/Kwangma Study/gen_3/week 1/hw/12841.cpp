#include <iostream>
using namespace std;

typedef long long ll;

ll leftr[100001], rightr[100001], cross[100001], N, ans, ans_sum=(1ll<<60);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =1; i<=N; i++)
        cin >> cross[i];

    for(int i =2; i<=N; i++){
        cin >> leftr[i];
        leftr[i]+=leftr[i-1];
    }

    for(int i =2; i<=N; i++){
        cin >> rightr[i];
        rightr[i]+=rightr[i-1];
    }

    for(int i=1; i<=N; i++){
        ll temp = leftr[i]+cross[i]+rightr[N]-rightr[i];
        if(temp<ans_sum){
            ans_sum = temp;
            ans = i;
        }
    }

    cout << ans << " " << ans_sum << "\n";

    return 0;
}