#include <iostream>

using namespace std;

string s1, s2;
int N;
int jump[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    char c;

    for(int i =0; i<N; i++){
        cin >> c;
        s1+=c;
    }

    for(int i =0; i<N; i++){
        cin >> c;
        s2+=c;
    }

    int t=0;
    for(int i =1; i<N; i++){  //s2 전처리
        while(t>0 && s2[i]!=s2[t]) t = jump[t-1];

        if(s2[i]==s2[t]){
            jump[i]=++t;
            continue;
        }
    }

    int start_loc = 0, ans = 0; t =0;

    for(int i =0; start_loc<N; i++){   //시작점이 N보다 작을때까지만 검사함 
        while(t>0 && s1[i%N]!=s2[t]){   //원형수열이기 때문에 N-1로 시작하는 문자열까지 검사
            t = jump[t-1];
            start_loc = i-t;
        }
        if(start_loc>=N) break;

        if(s1[i%N]==s2[t]){
            if(t==N-1){
                ans++;
                t = jump[t];
                start_loc = (i+1) - t;
                continue;
            }
            t++;
        }
        else start_loc++;
    }

    int gcd=0;

    if(ans!=0){  //약분하기  (유클리드 호제법 -> gcd 구하기)
        int a = ans;
        int b = N;

        while(b%a!=0){   //a<b
            b = b%a;
            swap(a,b);
        }
        gcd = a;
        ans/=gcd;
        N/=gcd;
    }

    cout << ans << "/" << N << "\n";

    return 0;
}