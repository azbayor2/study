//한정연
#include <iostream>

using namespace std;

int arr[501][501];
int N, M, B;
int ans = 100000000;
int maxnn = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> B;
    int maxn = 0;
    
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++){
            cin >> arr[i][j];
            maxn = max(maxn, arr[i][j]);  //최대높이 저장
        }
        
    while(maxn>=0)  //최대 높이부터 1씩 빼가면서 남는 블록과 시간 계산기
    {
        int ttime =0; //걸리는 시간
        int count = 0; //배치해야되는 블록 개수 저장
        int tempB = B;
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
            {
                int ttt = maxn-arr[i][j];  //최대높이 - 현재 높이
                
                if(ttt>0){  //블록을 배치해야되면
                    ttime+=ttt;  //블록당 1초 추가
                    count+=ttt;   //배치해야되는 블록 추가
                }
                    
                else if(ttt<0){  //블록을 없애야되면
                    ttime+=(2*(-ttt));  //블록당 2초 추가
                    tempB+=(-ttt);   // 저장된 블록개수 추가
                }
            }
            
        if(ans>ttime && tempB>=count)  //최소 시간이고, 블록을 배치할 수 있을때
        {
            ans = ttime;
            maxnn = maxn;
        }
        
        maxn--;
    }
    
    cout << ans << " " <<  maxnn << "\n";
    
    return 0;
}