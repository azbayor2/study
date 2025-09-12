#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll arr[10];
vector<ll> v[10];
ll N;

ll get_gcd(ll a, ll b)
{
    if(b>a) swap(a, b);
    
    while(1)
    {
        if(a%b==0) break;
        a = a%b;
        swap(a, b);
    }
    
    return b;
}

void dfs(ll cur, ll prev, ll mult)
{
    arr[cur]*=mult;
    for(ll next: v[cur])
    {
        if(next==prev) continue;
        dfs(next, cur, mult);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b, c, d;
    
    //초기화
    
    for(ll i=0; i<10; i++)
        arr[i] = 1;
        
    cin >> N;
    
    for(ll i =0; i<N-1; i++)
    {
        cin >> a >> b >> c >>d;
        
        ll maxx = min(c, d);
        for(ll i =maxx; i>1; i--)
        {
            if(c%i!=0 || d%i!=0) continue;
            
            c/=i; d/=i;
            break;
        }
        
        ll f = arr[a]*d;
        ll s = arr[b]*c;
        
        ll gcd = get_gcd(f, s);
        f/=gcd;
        s/=gcd;
        
        dfs(a, -1, s); dfs(b, -1, f);
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(ll i =0; i<N; i++)
        cout << arr[i] << " ";
        
    return 0;
    
}