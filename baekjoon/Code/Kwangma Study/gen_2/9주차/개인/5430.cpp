#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int T, N; string s1, s2; queue<int> q;
void game(){
    cin >> s1; cin >> N; cin >> s2; int cur=0;
    int arr[100001] = {0,};
    for(int j =0; j<N; j++){
        while(s2[cur]!=','){
            if(s2[cur]=='[') { cur++; continue;}
            else if(s2[cur]==']') { cur++; break; }
            q.push(s2[cur]-'0'); cur++;
        }
        int temp = 0;
        while(q.size()!=0) { temp+=(q.front()*pow(10, q.size()-1)); q.pop(); }
        arr[j]=temp;
        cur++;
    }
    //for(int j=0; j<N; j++) cout << arr[j] << " ";
    int start=0, end=N, len=s1.size(); bool flag=0;
    for(int j=0; j<len; j++){
        if(s1[j]=='R') {flag = (flag==0?1:0); continue;}
        else{
            if(start>=end){
                cout << "error\n";
                return;
            }
            switch(flag){
                case 0:{
                    start++; break;
                }
                case 1:{
                    end--; break;
                }
            }
        }
    }
    if(start==end){
        cout << "[]\n";
        return;
    }
    cout << "[";
    switch(flag){
        case 0:{
            for(int j=start; j<end-1; j++){
                cout << arr[j]<< ",";
            }
            cout << arr[end-1]<<"]\n";
            break;
        }
        case 1:{
            for(int j=end-1; j>=start+1; j--){
                cout << arr[j]<< ",";
            }
            cout << arr[start]<< "]\n";
            break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i =0; i<T; i++){
        game();
    }
    return 0;
}