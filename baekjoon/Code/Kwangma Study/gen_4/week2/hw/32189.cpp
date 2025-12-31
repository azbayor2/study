#include <iostream>
#include <algorithm>

using namespace std;

string s;

int s_len;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    s_len = s.length();

    int *arr[3001];
    for(int i =0; i<3001; i++){
        arr[i] = new int[3001];
        fill(arr[i], arr[i]+3001, 0);
    }

    for(int i =0; i<s_len-1; i++){  //i j 는 문자열 인덱스 ij -> arr[i+1][j+1]
        int pivot = arr[i][i+1];
        for(int j = i+1; j<s_len; j++){
            arr[i+1][j+1] = max(arr[i+1][j], arr[i][j+1]-pivot);
            if(s[i]==s[j])
                arr[i+1][j+1] = max(arr[i+1][j+1], arr[i][j]-pivot+1);
        }
    }

    for(int i =1; i<=s_len; i++){
        for(int j =1; j<=s_len; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}