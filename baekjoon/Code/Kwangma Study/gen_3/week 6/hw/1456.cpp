#include <iostream>
#include <vector>
using namespace std;

typedef long double ll;

bool not_prime[10000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long a, b, ans=0;
    cin >> a >> b;
    not_prime[0] = not_prime[1]=1;
    for(long long i =2; i<=10000000; i++){
        if(not_prime[i]) continue;
        for(long long j=2; i*j<=10000000; j++) not_prime[i*j]=1;
        ll calc = i*i;
        while(calc<=b){
            if(calc>=a) ans++;
            calc*=i;
        }
    }

    cout << ans << "\n";

    return 0;

}