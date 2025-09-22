#include <iostream>
#include <stack>

using namespace std;
typedef pair<int, int> p;  //num, index
stack<p> s;
int N, input, ans[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i =0; i< N; i++){
        cin >> input;
        while(s.size()!=0 && s.top().first<input){
            ans[s.top().second] = input; s.pop();
        }
        s.push({input, i});
    }

    while(s.size()!=0){
        ans[s.top().second] = -1; s.pop();
    }

    for(int i =0; i<N; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}