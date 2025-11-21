#include <iostream>

using namespace std;

int arr[11], N, K, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i =0; i<N; i++) cin >> arr[i];  //입력받기

    for(int i = N-1; i>=0; i--){   //큰 돈부터 계산
        ans+=K/arr[i];  //큰 돈을 뺄수 있을만큼 빼고 ans에 횟수 증감
        K%=arr[i];  //갱신

        if(K==0) break;
    }

    cout << ans << "\n";

    return 0;
}