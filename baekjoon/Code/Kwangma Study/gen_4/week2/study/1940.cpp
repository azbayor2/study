#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[15001];
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    for(int i =0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    int i =0; int j = N-1;
    int temp;
    while(i<j){
        temp = arr[i]+arr[j];
        if(temp>M){
            j--; continue;
        } else if(temp<M){
            i++; continue;
        } else{
            ans++;
            i++; j--;
            continue;
        }
    }

    cout << ans << "\n";

    return 0;
}