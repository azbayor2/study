#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;
int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for(int i =0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++) m[arr[i]+arr[j]]++;

    for(int i = N-1; i>=0; i--){
        for(int j = i-1; j>=0; j--){
            if(m.find(arr[i]-arr[j])==m.end()) continue;
            cout << arr[i] << "\n";
            return 0;
        }
    }

    return 0;
}