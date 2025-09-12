	//한정연

#include <iostream>

using namespace std;

int N, M;
string input;
int ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    cin >> input;
    
    int i =0;
    
    while(i<M)
    {
        if(input[i]=='O'){
            i++;
            continue;
        }
        
        int cur = i+1;
        
        while(1)
        {
            if(cur+1<M && input[cur]=='O' && input[cur+1]=='I')
                cur+=2;
            else
                break;
        }
        
        int t = (cur-i)/2;  //'O' 개수만 남기기
        
        if(N<=t)
            ans+=(t-N+1);   //개수 카운트
        
        i = cur;
        continue;
    }
    
    
    cout << ans << "\n";
    
    return 0;
}