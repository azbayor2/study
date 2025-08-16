#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i =1; i<=20; i++)
        m[i]=0;
        
    cin >> N;
    string s;
    int input;
    
    for(int i =0; i<N; i++)
    {
        cin >> s;
        if(s=="add"){
            cin >> input;
            m[input]=1;
            continue;
        }
        else if(s=="remove"){
            cin >> input;
            m[input]=0;
            continue;
        }
        else if(s=="check"){
            cin >> input;
            cout << m[input] << "\n";
            continue;
        }
        else if(s=="toggle"){
            cin >> input;
            m[input] = m[input]==0? 1:0;
            continue;
        }
        else if(s=="all"){
            for(int i =1; i<=20; i++)
                m[i]=1;
            continue;
        }
        else if(s=="empty"){
            for(int i =1; i<=20; i++)
                m[i]=0;
            continue;
        }
    }
    
    return 0;
}
