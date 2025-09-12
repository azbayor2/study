//한정연
#include <iostream>
#include <cmath>

using namespace std;

int cache[50001];  //

int dfs(int n)  //현재의 수가 쪼개질 수 있는 최소의 개수를 반환
{   
    
    if(n==0) return 0;
    int &p = cache[n];
    if(p!=0) return p;
    int sq = sqrt(n);
    int ret = 50001;
    
    for(int i =sq; i>=1; i--)
        ret = min(ret, dfs(n-(i*i))+1);
    
    return p=ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    cout << dfs(n) << "\n";
    
    return 0;
}