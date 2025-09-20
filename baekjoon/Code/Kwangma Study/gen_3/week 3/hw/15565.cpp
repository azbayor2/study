#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> arr;
int input;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i =0; i<N; i++){
        cin >> input;
        if(input==1) arr.push_back(i);
    }

    int ans = 10e7;
    int ssize = arr.size();

    for(int i =0; i<(ssize-K+1); i++)
        ans = min(ans, arr[i+K-1] - arr[i]+1);

    cout << (ans==10e7 ? -1: ans) << "\n";

    return 0;
}