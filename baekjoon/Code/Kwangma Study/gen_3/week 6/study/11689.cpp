#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool not_prime[1000001];
ll arr[1000001];

void find_prime(){
    not_prime[0] = 1;
    not_prime[1] = 1;
    for(int i =2; i<=1000000; i++)
        if(!not_prime[i])
            for(int j=2; j*i<1000000; j++)
                not_prime[i*j]=1;
}

ll gcd(ll n, ll k){
    if(k==0) return 1;
    return pow(n, k) - pow(n, k-1);
}

ll getans(ll n){
    for(int i =2; i<=1000000; i++){
        if(not_prime[i]) continue;
        while(n%i==0){
            arr[i]++;
            n/=i;
        }
    }

    ll ans = 1;
    if(n>=1000000) ans = n-1;
    for(int i =2; i<=1000000; i++){
        if(!not_prime[i])
            ans*=gcd(i, arr[i]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    find_prime();
    ll a;
    cin >> a;
    cout << getans(a) << "\n";

    return 0;
}