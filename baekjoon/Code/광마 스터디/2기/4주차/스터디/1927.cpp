//한정연
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int input;
    
    for(int i =0; i<N; i++)
    {
        cin >> input;
        if(input==0)
        {
            if(q.size()==0){
                cout << 0 << "\n";
                continue;
            }
            
            cout << -q.top() << "\n";
            q.pop();
            continue;
        }
        
        q.push(-input);
    }
    
    return 0;
}