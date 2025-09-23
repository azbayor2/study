#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
string s;
typedef pair<int, int> p;
queue<p> q;
vector<p> v;

bool sortp(p &p1, p&p2){
    if(p1.first < p2.first) return true;
    else if(p1.first > p2.first) return false;
    else if(p1.second < p2.second) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> s;
        v.push_back({s.size(), i});
    }
    sort(v.begin(), v.end(), sortp);

    long long ans=0;
    for(p cur: v){
        while(q.size()!=0 && (q.front().first < cur.first || (cur.second-q.front().second)>K)) q.pop();
        ans+=q.size(); q.push(cur);
    }

    cout << ans << "\n";

    return 0;
}