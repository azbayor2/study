#include <iostream>

using namespace std;

int main(){
    
    float coin;
    int arr[100005] = {0,}, N;
    cin >> coin;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    int coinc = (int)(coin/0.99f);
    coinc = (coinc>=2 ? 2:coinc);
    int s=0, e=0, count = 0, ans=0, t1=0, t2=0;
    
    while(s<=e && e<=N+1){
        if(ans<(e-s)){
            ans = e-s;
            t1 = s; t2 = e;
        }
        if(arr[e]==0){
            if(count>=coinc){
                while(arr[s]!=0) s++;
                s++; e++; continue;
            } else{
                e++;
                count++; continue;
            }
        }
        e++;
    }
    int maxc = 0;
    for(int i=t1; i<t2; i++) maxc = max(maxc, arr[i]);
    
    
    cout << ans << "\n" << maxc << "\n";
    
    return 0;
    
}