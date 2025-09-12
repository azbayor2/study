//한정연

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, arr[500001];
ll mmin=10000, mmax=-10000;
priority_queue<pair<ll, ll>> q;  //<개수, 숫자>
map<ll, ll> m;   //
map<ll, bool> used;  //사용 여부 확인
double total;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i =0; i<N; i++){
        
        cin >> arr[i];
        mmin = min(mmin, arr[i]); mmax = max(mmax, arr[i]);
        if(m.find(arr[i])==m.end())
            m[arr[i]]=1;
            
        else
            m[arr[i]]++;
            
        total+=arr[i];
    }
    
    for(int i =0; i<N; i++)
    {
        if(used.find(arr[i])==used.end())
        {
            used[arr[i]]=1;
            q.push(make_pair(m[arr[i]], -arr[i]));
        }
    }
    
    pair<ll, ll> f = q.top(); q.pop();
    pair<ll, ll> s = q.top(); q.pop();
    
    ll most = f.first==s.first? -s.second : -f.second;
    
    cout << (ll)round(total/N) << "\n";
    sort(arr, arr+N);
    cout << arr[N/2] << "\n";
    cout << most << "\n";
    cout << mmax-mmin << "\n";
    
    //multiset
    return 0;      
}