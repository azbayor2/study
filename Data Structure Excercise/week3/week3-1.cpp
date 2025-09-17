#include <iostream>
#include <array>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    array<array<int,11>,11> arr;
    int N;
    cin >> N;
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++) cin >> arr[i][j];

    int maindiag=0, subdiag=0;
    for(int i =0; i<N; i++){
        maindiag+=arr[i][i]; subdiag+=arr[i][N-1-i];
    }
    
    cout << "주대각선 합: " << maindiag << "\n" << "부대각선 합: " <<subdiag << "\n";
    cout << (maindiag==subdiag ? "두 대각선의 합은 같다": "두 대각선의 합은 다르다") << "\n";

    return 0;
}