#include <iostream>

using namespace std;
int arr[2][2][3], N, a,b,c;  //min, max

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        arr[0][i%2][0] = min(a+arr[0][(i+1)%2][0], a+arr[0][(i+1)%2][1]);
        arr[0][i%2][1] = min(b+arr[0][(i+1)%2][0], min(b+arr[0][(i+1)%2][1], b+arr[0][(i+1)%2][2]));
        arr[0][i%2][2] = min(c+arr[0][(i+1)%2][1], c+arr[0][(i+1)%2][2]);
        arr[1][i%2][0] = max(a+arr[1][(i+1)%2][0], a+arr[1][(i+1)%2][1]);
        arr[1][i%2][1] = max(b+arr[1][(i+1)%2][0], max(b+arr[1][(i+1)%2][1], b+arr[1][(i+1)%2][2]));
        arr[1][i%2][2] = max(c+arr[1][(i+1)%2][1], c+arr[1][(i+1)%2][2]);
    }

    cout << max(arr[1][(N+1)%2][0], max(arr[1][(N+1)%2][1],arr[1][(N+1)%2][2])) << " " << min(arr[0][(N+1)%2][0], min(arr[0][(N+1)%2][1],arr[0][(N+1)%2][2])) << "\n";

    return 0;
}