#include <iostream>

using namespace std;
typedef long long ll;

ll sum[100001], N, M, K, ans[100001], student[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b;
    cin >> N >> M >> K;
    for(int i =0; i<M; i++){
        cin >> a >> b;
        sum[a]=b;
    }
    for(int i =1; i<=N; i++) sum[i]+=sum[i-1];
    for(int i =1; i<=K; i++){
        cin >> a; student[i]=a;
    }

    ll s = 1, e=N;

    for(int i =1; i<=K; i++){
        ll curpos = student[i];
        ll tempL = (s<=curpos ? sum[curpos]-sum[s-1]: 0);
        ll tempR = (curpos<=e ? sum[e]-sum[curpos-1]: 0);
        ll distL = curpos;
        ll distR = N-curpos+1;

        //1. 비교
        if(tempL<tempR){
            s = max(s, curpos);
            ans[i] = tempL;
        }

        else if(tempR<tempL){
            e = min(e, curpos);
            ans[i] = tempR;
        }
        //2. 같을 때 거리 비교
        else if(distL<distR){
            s = max(s, curpos);
            ans[i] = tempL;
        }

        else if(distR<distL){
            e = min(e, curpos);
            ans[i] = tempR;
        }
        //3. 거리도 같을때 왼쪽 선택
        else{
            s = max(s, curpos);
            ans[i] = tempL;
        }
    }

    for(int i =1; i<=K; i++)
        cout << ans[i] << "\n";

    return 0;
}