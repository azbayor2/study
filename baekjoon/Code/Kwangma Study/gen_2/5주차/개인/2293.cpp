#include <iostream>

using namespace std;

int N, k;
int arr[101];
int cache[2][10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> k;
    
    for(int i =1; i<=N; i++)
        cin >> arr[i];
        
    
    for(int m =1; m<=N; m++){
        for(int j =1; j<=k; j++)
        {
            int i = m%2;
            int cur = arr[m];
            for(int start =0; start<=j; start+=cur)
            {
                if(start==0){
                    cache[i][j] = cache[(i==1?0:1)][j];
                    continue;
                }
                if(start==j) {
                    cache[i][j]++;
                    continue;
                }
                
                cache[i][j]+=cache[(i==1? 0:1)][j-start];
            }
        }
    }
        
    cout << cache[(N%2? 1:0)][k] << "\n";
    
    return 0;
}