#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    int s, e, N;
    cin >> N;

    for(int i =0; i<N; i++){
        cin >> str;
        s=0, e = str.size()-1;
        int ans  = 0;
        while(s<e){
            if((e-s)<=3 && str[s]!=str[e]){
                if(e-s>=2){
                    if(str[s]==str[e-1] || str[s+1]==str[e]){
                        ans++; break;
                    }
                    else{
                        ans=2; break;
                    }
                }
                else{
                    ans++;
                    break;
                }
                
            }
            
            if(str[s]==str[e]){
                s++; e--; continue;
            }
            if((s<e-1) && str[s]==str[e-1] && (s+1<e-2) && str[s+1]==str[e-2]){
                e--; ans++; continue;
            }
            if((s+1<e) && str[s+1]==str[e] && (s+2<e-1) && str[s+2]==str[e-1]){
                s++; ans++; continue;
            }
            ans=2; break;
        }
        if(ans>=2) ans = 2;

        cout << ans << "\n";
    }
    
    return 0;
}