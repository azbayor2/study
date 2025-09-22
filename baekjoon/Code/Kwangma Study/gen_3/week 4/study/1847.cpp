#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> v;
stack<int> s;
int arr[100001];
int N, input, cur=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i =0; i<N; i++) cin >> arr[i];

    for(int i =0; i<N; i++){
        input = arr[i];
        while(cur<input){
            s.push(++cur);
            v.push_back('+');
        }
        if(s.size()==0 || s.top()!=input){
            cout << "NO" << "\n";
            return 0;
        }
        s.pop(); v.push_back('-');
    }

    for(char c: v) cout << c << "\n";

    return 0;
}