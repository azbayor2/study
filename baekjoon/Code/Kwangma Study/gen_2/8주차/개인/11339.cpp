#include <iostream>
#include <map>

using namespace std;

map<string, int> m;
map<int, string> rm;
int N, M;
string s;
int mm;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i =1; i<=N; i++)
    {
        cin >> s;
        m[s]=i;
        rm[i]=s;
    }
    
    for(int i =0; i<M; i++)
    {
        mm=0;
        cin >> s;
        if(s[0]>='0' && s[0]<='9')
        {
            int len = s.size();
            int mult =1;
            for(int i =len-1; i>=0; i--)
            {
                int temp = (int)(s[i]-'0');
                mm+=temp*mult;
                mult*=10;
            }
            
            cout << rm[mm] << "\n";
        }
        
        else{
            cout << m[s] << "\n";
        }
    }
    
    return 0;
}