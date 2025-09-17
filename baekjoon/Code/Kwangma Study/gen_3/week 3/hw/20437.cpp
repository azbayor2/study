#include <iostream>
#include <vector>
using namespace std;

int T;


void find(){
    int N; string s;
    cin >> s; cin >> N;

    vector<int> v[26];

    int ssize=s.size();
    for(int i =0; i<ssize; i++) v[(int)(s[i]-'a')].push_back(i);

    int mmin=100000, mmax=0;

    for(int i =0; i<26; i++){
        int vlen = v[i].size();
        if(vlen<N) continue;
        
        for(int j =0; j<=(vlen-N); j++){
            int curlen = v[i][j+N-1]-v[i][j]+1;
            mmin = min(mmin, curlen);
            mmax = max(mmax, curlen);
        }
    }

    if(mmax==0) cout << -1 << "\n";
    else cout << mmin << " " << mmax << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    cin >> T;
    for(int i =0; i<T; i++) find();

    return 0;
}