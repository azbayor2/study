#include <iostream>

using namespace std;

int dp[20];
pair<int, int> input[20];  //걸리는 일 수, 돈
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int a, b;
    for(int i =1; i<=N; i++){
        cin >> a >> b;
        input[i] = {a,b};   //입력 저장
    }
    
    for(int i=N; i>0; i--){
        if(input[i].first+i-1>N){  //선택할 수 없을 때
            dp[i] = dp[i+1];   //다음 날의 값을 저장함 
            continue;
        }

        //선택했을때 값과 선택하지 않았을 때의 값을 비교해서 큰 값을 저장
        dp[i] = max(input[i].second + dp[input[i].first+i], dp[i+1]);
    }

    cout << dp[1] << "\n";

    return 0;
}