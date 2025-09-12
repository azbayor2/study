//정연
#include <iostream>
using namespace std;
long long arr[102] = {0,1,1,1,2,2,}, T, N;
long long ang(int idx){
    if(idx<=5) return arr[idx];
    if(arr[idx]!=0) return arr[idx];
    return arr[idx]=ang(idx-1)+ang(idx-5);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ang(100);
    cin >> T;
    for(int i =0; i<T; i++){
        cin >> N; cout << arr[N] << "\n";
    }
    return 0;
}