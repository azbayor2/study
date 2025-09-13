#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100005], M, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> M;
    sort(arr, arr+N);
    int s=0, e=N-1;
    while(s<e){
        int sum = arr[s]+arr[e];
        if(sum==M) ans++;
        if(sum<=M) s++;
        else e--;
    }
    cout << ans << "\n";
    return 0;
}