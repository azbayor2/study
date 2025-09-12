#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
map<ll,ll> m;
ll P, Q, N;

ll dfs(ll cur)
{
    if(cur==0)
        return 1;
    
    if(m.find(cur)!=m.end())
        return m[cur];
        
    return m[cur] = dfs(cur/P) + dfs(cur/Q);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> P >> Q;
    
    cout << dfs(N) << "\n";
    
    return 0;
}