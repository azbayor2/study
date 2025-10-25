#include <iostream>

using namespace std;

int solve(int l, int r){
    int a = l, b = r;
    if(a<b) swap(a, b);
    while(a%b!=0){
        a = a%b;
        swap(a,b);
    }

    return l*r/b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int a, b;
    for(int i =0; i<t; i++){
        cin >> a >> b;
        cout << solve (a, b) << "\n";
    }
    return 0;
}