#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    string ans; int ssize = s.size(); int cur =0, count=1; char c;
    while(cur<=ssize){
        if(cur==ssize){
            ans.push_back(c);
            ans.append(to_string(count));
            break;
        }
        if(cur==0){
            c = s.at(cur++);
            count++;
            continue;
        }

        if(c==s.at(cur)){
            count++; cur++;
            continue;
        }
        else{
            ans.push_back(c);
            ans.append(to_string(count));
            count=1; c = s.at(cur++);
        }
    }

    cout << ans << "\n";
}