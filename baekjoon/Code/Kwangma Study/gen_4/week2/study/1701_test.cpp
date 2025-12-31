#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    unordered_set<string> s;

    cin >> str;

    int len = str.size();
    int ans = 0;

    for(int i =0; i<len; i++)
        for(int j = i; j<len; j++){
            string sub_str = str.substr(i, j-i+1);
            if(s.find(sub_str)!=s.end()){
                ans = max(ans, j-i+1);
            }

            else
                s.insert(sub_str);
        }

    cout << ans << "\n";

    return 0;
}