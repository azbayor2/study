#include <iostream>
#include <map>
using namespace std;
map<string, string> m;
int N, M;
string s1, s2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> s1 >> s2;
        m[s1]=s2;
    }
    for(int i =0; i<M; i++){
        cin >> s1;
        cout << m[s1] << "\n";
    }
    return 0;
}