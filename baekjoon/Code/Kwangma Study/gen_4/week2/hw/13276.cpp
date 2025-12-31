#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string s, a, b;
unordered_set<string> sset;

void kmp(string s1, string s2, vector<int> & v){
    int jump[2001] = {0, };
    int j =0;
    for(int i =1; i<s2.size(); i++){
        while(j>0 && s2[i]!=s2[j]) j = jump[j-1];
        if(s2[i]==s2[j]) jump[i]=++j;
    }

    j=0;
    for(int i =0; i<s1.size(); i++){
        while(j>0 && s1[i]!=s2[j]) j = jump[j-1];
        if(s1[i]==s2[j]){
            if(j==s2.size()-1){
                v.push_back(i);
                j=jump[j]; continue;
            }
            j++;
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> a >> b;
    vector<int> v1, v2;

    kmp(s, a, v1); kmp(s, b, v2);

    for(int i: v1)
        for(int j : v2){
            int sta = i-a.size()+1;
            int en = j-b.size()+1;
            
            if(i>j || en<sta) continue;
            sset.insert(s.substr(sta, en-sta+1));
        }

    cout << sset.size() << "\n";

    return 0;
}
