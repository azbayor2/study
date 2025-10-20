#include <iostream>
#include <array>

using namespace std;

int main(){
    array<array<int, 11>, 11> arr = {0,};
    int N;
    cin >> N;

    for(int i =0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }

    int main_diag=0, sub_diag=0;

    for(int i =0; i<N; i++){
        main_diag+=arr[i][i];
        sub_diag+=arr[i][N-i-1];
    }

    cout << "주대각선: " << main_diag << endl;
    cout << "보조대각선: " << sub_diag << endl;
    cout << "두 대각선의 길이는 " << ((main_diag==sub_diag) ? "같다": "다르다") << endl;

    return 0;

}