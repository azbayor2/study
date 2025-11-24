#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int N, M;

bool find(int target){
    int start = 0, end = N-1;
    while(1){
        int mid = (start+end)/2;
        if(arr[mid]==target) return true;
        if(start>=end) break;
        if(arr[mid]>target){
            end = mid-1; continue;
        } else{
            start = mid+1; continue;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a;

    cin >> N;
    for(int i =0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    cin >> M;
    for(int i =0; i<M; i++){
        cin >> a;
        cout << find(a) << "\n";
    }

    return 0;
}