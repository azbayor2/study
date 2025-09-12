#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N ;i++) cin >> arr[i];
    sort(arr, arr+N);
    int ans = 2000000000;
    int s = 0, e=1;
    while(s<=e && e<N){
        if(s==e){
            e++; continue;
        }
        int temp = arr[e] - arr[s];
        if(temp>=M){
            ans = min(ans, temp);
            s++;
        }
        else{
            e++;
        }
    }

    cout << ans << "\n";

    return 0;
}