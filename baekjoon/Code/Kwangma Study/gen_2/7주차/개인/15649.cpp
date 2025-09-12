//한정연
#include <iostream>

using namespace std;

int temp[9], cur, N, M; //temp: 현재까지 숫자 저장, cur: 배열 마지막 인덱스+1
bool used[9];

void dfs(int n, int m)  //(현재 수, m번째)
{
    if(m>M){  //M번째 수까지 채웠으면
        for(int i =0; i<cur; i++)
            cout << temp[i] << " ";  //배열 출력
        cout << "\n";
        return;
    }
    
    for(int start=1; start<=N; start++){  //다음 숫자(n~N까지 고르기)
        if(used[start]) continue;
        temp[cur++]=start; used[start]=1;//배열의 cur 인덱스에 숫자 추가
        dfs(start, m+1); cur--; used[start]=0;  //다음 숫자 고르기
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    dfs(1, 1);
    return 0;
}