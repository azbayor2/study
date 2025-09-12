//정연
#include <iostream>
#include <map>
using namespace std;
int T, N;
string s1, s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i =0; i<T; i++){
        cin >> N; map<string, int> m;
        int arr[31]={0,};
        int idx=0;
        for(int j=0; j<N; j++){
            cin >> s1 >> s2;
            if(m.find(s2)==m.end()) m[s2]=idx++;
            arr[m[s2]]++;
        }
        long long ans = 1;
        for(int i =0; i<idx; i++)
            ans*=(arr[i]+1);
        cout << ans -1 << "\n";
    }
}