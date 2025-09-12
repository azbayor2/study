#include <iostream>
#include <stack>

using namespace std;

int N, K;

stack<int> s;
int count;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    int coin;
    for(int i =0; i<N; i++)
    {
        cin >> coin;
        s.push(coin);
    }
    
    while(K>0)
    {
        int cur;
        while(s.size()!=0)
        {
            cur = s.top();
            s.pop();
            if(K>=cur) break;
        }
        
        count+=(K/cur);
        K=K%cur;
    }
    
    cout << count << "\n";
    
    return 0;
}