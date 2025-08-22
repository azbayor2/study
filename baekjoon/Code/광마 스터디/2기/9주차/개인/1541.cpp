#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
string s; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s; int len = s.size(); ll ans=0, cur = 0, temp=0;
    queue<int> q; bool flag=0;
    while(cur<len){
        temp=0;
        if(s[cur]>='0' && s[cur]<='9'){
            while(s[cur]>='0' && s[cur]<='9') { q.push(s[cur]-'0'); cur++;};
            while(q.size()!=0){
                temp+=(q.front()*pow(10, q.size()-1)); q.pop();
            }
            if(flag==0) ans+=temp;
            else ans-=temp;
            continue;
        }
        else if(s[cur]=='-')  flag=1;
        cur++; continue;
    }
    
    cout << ans << "\n";
    return 0;
}