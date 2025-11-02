#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool not_prime[10000001];
vector<int> prime;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    not_prime[0] = not_prime[1] = 1;
    for(int i =2; i<=10000000; i++){
        if(!not_prime[i]){
            prime.push_back(i);
            for(int j =2; j*i<=10000000; j++)
                not_prime[i*j]=1;
        }
    }

    int N;
    cin >> N;

    for(int cur: prime){
        if(cur<N) continue;

        string s = to_string(cur);
        string rev;
        for(auto cur = s.rbegin(); cur!=s.rend(); cur++){
            rev+=*cur;
        }
        // cout << s << " " << rev << "\n";

        if(s==rev){
            cout << cur << "\n";
            return 0;
        }
        
    }

    return 0;
}