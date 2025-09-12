#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> v;  //무게, 만족도
typedef pair<int, int> pp;  //일일히 쓰기 귀찮아서 매크로 같은 느낌
int dp[1500][10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    
    int a, b, c;
    v.push_back(pp{0,0});  //더미
    
    for(int i =0; i<N; i++)
    {
        cin >> a >> b >> c;
        int mult = 1;
        while(c-mult>0)  //2^n 으로 쪼갤 수 있을때
        {
            v.push_back(make_pair(a*mult, b*mult));  //2^n 기준으로 물건을 묶음
            c-=mult;
            mult*=2;
        }
        
        v.push_back(make_pair(a*c, b*c));  //남은 개수를 묶어서 저장
    }
    
    int thing_count = v.size();
    
    for(int i =1; i<=thing_count; i++)   //dp
    {   
        
        int cur_weight = v[i].first;
        int cur_happy = v[i].second;
        
        for(int j =1; j<=K; j++)
            dp[i][j] = (j<cur_weight)? dp[i-1][j] : max(dp[i-1][j], dp[i-1][j-cur_weight]+cur_happy);
    }
    
    cout << dp[thing_count][K] << "\n";
        
    return 0;
}