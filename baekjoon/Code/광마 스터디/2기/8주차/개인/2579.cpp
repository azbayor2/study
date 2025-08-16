#include <iostream>
using namespace std;
int arr[301], N, cache[3][301];
int dfs(int cur, int arg){
    if(cur==N) return arr[N];
    if(cur>N) return -1000000000;
    if(cache[arg][cur]!=0) return cache[arg][cur];
    int a=-1000000000, b;
    if(arg<2) a = dfs(cur+1, arg+1);
    b = dfs(cur+2, 1);
    return cache[arg][cur]=max(a, b)+arr[cur];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++) cin >> arr[i];
    cout << dfs(0,0) << "\n";
    return 0;
}