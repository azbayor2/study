#include <iostream>

using namespace std;

int sum[100001], N, M, a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> sum[i];
        sum[i]+=sum[i-1];
    }

    cin >> M;
    for(int i =0; i<M; i++){
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }

    return 0;
}