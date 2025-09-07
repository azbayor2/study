#include <iostream>
using namespace std;

int arr[1025][1025], N, M, K, a,b, c, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j =1; j<=M; j++){
            cin >> arr[i][j];
            arr[i][j]+=(arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]);
        }
    }
    cin >> K;

    for(int i =0; i<K; i++){
        cin >> a >> b >> c >> d;
        cout << arr[c][d]-arr[a-1][d]-arr[c][b-1] + arr[a-1][b-1] << "\n";
    }

    return 0;
}