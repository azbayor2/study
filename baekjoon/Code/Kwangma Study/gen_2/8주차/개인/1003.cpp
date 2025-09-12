#include <iostream>
using namespace std;
typedef pair<int,int> p;
p pp[41];
bool visited[41];
int N, m;
p fibonacci(int cur)
{
    if(cur==1){
        return pp[1]={0,1};
    }
    if(cur==0){
        return pp[0]={1,0};
    }
    
    if(visited[cur]) return pp[cur];
    visited[cur]=1;
    p a = fibonacci(cur-1);
    p b = fibonacci(cur-2);
    pp[cur]={a.first+b.first, a.second+b.second};
    return pp[cur];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fibonacci(40);
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> m; cout << pp[m].first << " " << pp[m].second << "\n";
    }
    return 0;
}