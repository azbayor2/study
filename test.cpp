#include <iostream>

using namespace std;

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    int s1len = s1.size(), s2len = s2.size();
    if(s1len<s2len) swap(s1, s2);

    int mmin = min(s1len, s2len);
    int mmax = max(s1len, s2len);
    bool temp=0;

    for(int i =0; i<mmax; i++){
        if(i<mmin){
            if(temp==1){
                if(s1[s1len-i-1]=='1'){
                    s1[s1len-i-1]='0';
                }else{
                    s1[s1len-i-1]='1';
                    temp=0;
                }
            }
            if(s1[s1len-i-1]=='1' & s2[s2len-i-1]=='1'){
                temp=1;
                s1[s1len-i-1] = '0';
            }
            else if(s1[s1len-i-1]=='0' && s2[s2len-1-i]=='0'){
                continue;
            }
            else{
                s1[s1len-i-1] = '1';
            }
        }

        else{
            if(s1[s1len-i-1])
        }
    }

    
    


    
    
}