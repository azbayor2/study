#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char> v;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int cur = 1, input=0;

    for(int i =0; i<N; i++){
        cin >> input;

        while(cur<=input){
            v.push_back('+');
            s.push(cur); cur++;
        }

        if(!s.size() || s.top()!=input){
            cout << "NO\n"; return 0;
        }
        
        v.push_back('-'); s.pop();
    }

    for(char cur: v) cout << cur << "\n";

    return 0;
}