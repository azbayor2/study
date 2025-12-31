#include <iostream>
using namespace std;

string str;
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    cin >> str;
    int len = str.size();
    int jump[5001] = {0, };
    for(int k =0; k<len; k++){
        int j = k; 
        jump[k]=k;   

        for(int i = k+1; i<len; i++){
            while(j>k && str[i]!=str[j]) j = jump[j-1];

            if(str[i] == str[j]){
                ans = max(ans, j-k+1);
                jump[i] = j+1;
                j++;
            }
            else jump[i] = j;
        }
    }

    cout << ans << "\n";

    return 0;
}