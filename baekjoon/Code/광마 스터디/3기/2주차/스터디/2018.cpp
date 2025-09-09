#include <iostream>

using namespace std;

int N, s=1, e=2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int count =0, cur=1;

    while(e>=s && e<=N+1){
        if(e==s){
            cur+=e; e++; continue;
        }
        if(cur==N) count++;

        if(cur<=N){
            cur+=e; e++;
        }
        else{
            cur-=s; s++;
        }
    }

    cout << count << "\n";

    return 0;
}