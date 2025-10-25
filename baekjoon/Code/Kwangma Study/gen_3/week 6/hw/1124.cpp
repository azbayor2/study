#include <iostream>
#include <vector>

using namespace std;

bool not_prime[1001];
vector<int> prime;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    not_prime[0]=1; not_prime[1]=1;
    for(int i =2; i<=1000; i++)
        if(!not_prime[i]){
            prime.push_back(i);
            for(int j=2; j*i<=1000; j++) not_prime[i*j]=1;
        }

    int a, b, ans=0;
    cin >> a >> b;

    for(int i =a; i<=b; i++){
        int cur = i, count=0;
        for(int j: prime){
                while(cur%j==0){
                    count++;
                    cur/=j;
                }
        }
        if(cur!=1) count++;

        if(!not_prime[count]) ans++;
    }

    cout << ans << "\n";

    return 0;
}