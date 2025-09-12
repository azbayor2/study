//정연
#include <iostream>

using namespace std;

typedef long long ll;


bool used[1001];
int idx;
ll arr[1001];
ll input[1001];
ll N, M;
ll MAX = -1000000000, MIN=1000000000;

void dfs(ll cur, ll calc)
{
    if(cur>N-2)
    {
        MAX = max(MAX, calc);
        MIN = min(MIN, calc);
        //cout << calc << "\n";
        return;
    }
    
    //cout << calc << "\n";
    
    for(int i =0; i<idx; i++)
    {
        if(used[i]) continue;
        used[i] = 1;
        //cout << arr[i] << "\n";
        switch(arr[i])
        {
            case 0:{
                dfs(cur+1, calc+input[cur+1]);
                break;
            }
            case 1:{
                dfs(cur+1, calc-input[cur+1]);
                break;
            }
            case 2:{
                dfs(cur+1, calc*input[cur+1]);
                break;
            }
            case 3:{
                dfs(cur+1, calc/input[cur+1]);
                break;
            }
        }
        used[i] = 0;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i =0; i<N; i++)
        cin >> input[i];
        
    for(int i =0; i<4; i++)
    {
        cin >> M;
        for(int j=0; j<M; j++)
            arr[idx++] = i;
    }
    
    //for(int i =0; i<idx; i++)
    //    cout << arr[i];
    
    dfs(0, input[0]);
    
    cout << MAX << "\n";
    cout << MIN << "\n";
    
    return 0;
}