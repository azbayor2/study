#include <iostream>
#include <cmath>

using namespace std;

int A, B, num[10], len, ans=-1;
bool used[10];

void dfs(int digit, int C){
    if(C>=B) return; //현재 C가 B보다 크면 버림
    if(digit==0){  //다 선택했으면
        ans = max(ans, C); return;  //큰 값 갱신
    }
    for(int i =0; i<len; i++){
        if(used[i]) continue;  //이미 사용했으면
        used[i]=1; //사용 표시
        dfs(digit-1, C+num[i]*pow(10, digit-1));  //다음 자릿 수 갱신 (내림차순)
        used[i]=0;   //백트래킹
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;;
    int cur = A;
    int idx = 0;
    while(cur){
        num[idx++] = cur%10;
        cur/=10;
    }
    len = idx;

    for(int i =0; i<len; i++){  
        if(num[i]==0) continue;  //첫번째 자리숫자가 0이면 패스
        used[i]=1; dfs(len-1, num[i]*pow(10, len-1)); //시작
        used[i]=0;  //백트래킹
    }

    cout << ans << "\n";

    return 0;
}