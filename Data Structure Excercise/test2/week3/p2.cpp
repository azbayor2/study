#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 1;
    string ans= "";

    for(int i =0; i<s.size(); i++){
        if((i+1)<s.size() && s[i]==s[i+1]){
            count++;
            continue;
        }
        ans+=s[i];
        ans+=to_string(count);
        count=1;

    }

    cout << ans << endl;

    return 0;
}