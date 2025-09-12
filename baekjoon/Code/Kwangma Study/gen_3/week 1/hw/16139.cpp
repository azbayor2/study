#include <iostream>
using namespace std;

string s;
int arr[27][200001];
int N, a, b, len;
char c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    len = s.size();

    for(int i =1; i<=len; i++){
        arr[(int)(s[i-1]-'a')][i]++;
        for(int j =0; j<26; j++)
            arr[j][i]+=arr[j][i-1];
    }

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> c >> a >> b;
        cout << arr[(int)(c-'a')][b+1] - arr[(int)(c-'a')][a] << "\n";
    }

    return 0;
}
