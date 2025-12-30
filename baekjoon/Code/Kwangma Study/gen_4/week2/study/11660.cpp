#include <iostream>

using namespace std;

typedef long long ll;

ll sum[1026][1026];
int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i =1; i<=N; i++){
        for(int j =1; j<=N; j++){
            cin >> sum[i][j];
            sum[i][j]+=(sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]);
        }
    }

    int a, b, c, d;

    for(int i =0; i<M; i++){
        cin >> a >> b >> c >> d;

        cout << sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1] << "\n";
    }
    

    return 0;
}