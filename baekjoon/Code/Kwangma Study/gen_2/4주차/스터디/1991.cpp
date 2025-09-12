//한정연
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[28];

int N;

void pre(int cur){
    
    if(cur+'A'=='.') return;
    
    cout << (char)(cur+'A');
    for(int next: v[cur]) pre(next);
    
    return;
}

void in(int cur) {
    
    if(cur+'A'=='.') return;
    
    in(v[cur][0]);
    cout << (char)(cur+'A');
    in(v[cur][1]);
    
    return;
}

void post(int cur) {
    
    if(cur+'A'=='.') return;
    
    for(int next: v[cur])
        post(next);
        
    cout << (char)(cur+'A');
        
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    char a, b, c;
    
    for(int i =0; i<N; i++){
        
        cin >> a >> b >> c;
        v[a-'A'].push_back(b-'A');
        v[a-'A'].push_back(c-'A');
        
    }
    
    pre(0); cout << "\n";
    in(0); cout << "\n";
    post(0); cout << "\n";

    return 0;
}