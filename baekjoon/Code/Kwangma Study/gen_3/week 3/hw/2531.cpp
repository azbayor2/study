#include <iostream>
using namespace std;

int count[3001], N, cur, K, sushi[3000001], D, coupon, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> D >> K >> coupon;
    count[coupon]++; cur++;
    for(int i =0; i<N; i++) cin >> sushi[i];

    int s=0, e=0;
    while((e-s)<K){
        if(count[sushi[e]]==0) cur++;
        count[sushi[e]]++; e++;
    }

    ans = max(ans, cur);

    for(s=1; s<N; s++){
        if(count[sushi[e]]==0) cur++;
        count[sushi[e]]++;
        e = (e+1)%N;

        count[sushi[s-1]]--;
        if(count[sushi[s-1]]==0) cur--;

        ans = max(ans, cur);
    }

    cout << ans << "\n";

    return 0;
}