#include <iostream>
#include <array>

using namespace std;

int main(){
    array<array<int, 11>, 11> arr = {0, };
    int N, a;
    cin >> N;

    for(int i =0; i<N ;i++)
        for(int j =0; j<N; j++)
            cin >> arr[i][j];

    int pri=0, sub=0;

    for(int i =0; i<N; i++){
        pri+=arr[i][i];
        sub+=arr[i][N-1-i];
    }

    cout << "주대각선 합: " << pri<< endl;
    cout << "부대각선 합: " << sub << endl;

    cout << (pri==sub ? "두 합은 같다": "두 합은 다르다") << endl;

    return 0;
}