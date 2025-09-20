#include <iostream>

using namespace std;

int N, M, arr[100005], cur, ans=-(1<<30); //합이 최대 --> 나올수 있는 최솟값보다 더 작게 설정

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i =0; i<N; i++) cin >> arr[i];  //입력

    int s=0, e=0;  //s 이상 e미만

    while(e<=N){
        if((e-s)==M){   //윈도우의 길이가 M이면 답 갱신
            ans = max(cur, ans);
        }
        if(e==N) break;  //e가 N에 도달했으면 종료 (e가 넘어갔으면)

        cur+=arr[e++]; //다음 인덱스 선택
        while((e-s)>M){   //e를 늘리는 바람에 길이가 M보다 길어졌으므로 줄여줌
           cur-=arr[s++];
        }
    }
    cout << ans << "\n";
    return 0;
}