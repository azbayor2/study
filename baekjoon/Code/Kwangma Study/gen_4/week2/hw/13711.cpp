#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, a;
int arr[100001];
map<int, int> m;
int v[100001];
int vcount;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =1; i<=N; i++)
        cin >> arr[i];

    for(int i =1; i<=N; i++){
        cin >> a;
        m[a] =i;
    }


    
    for(int i =1; i<=N; i++){
        int cur = m[arr[i]];
        if(vcount==0 || v[vcount-1]<cur){
            v[vcount++]=cur;
            continue;
        }

        int *p = upper_bound(v, v+vcount, cur);
        *p = cur;
    }

    cout << vcount << "\n";

    return 0;
    
}