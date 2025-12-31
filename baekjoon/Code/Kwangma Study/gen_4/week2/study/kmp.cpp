#include <iostream>
#include <string>
#include <vector>

using namespace std;

string find_str;  //패턴
string from_str;  //검색 대상
int jump[1000001] = {0, };  //전처리 배열
vector<int> loc;

void KMP_init(){
    int j =0;
    int find_str_size = find_str.size();

    for(int i = 1; i<find_str_size; i++){
        while(j>0 && find_str[i]!=find_str[j]) j = jump[j-1];

        if(find_str[i]==find_str[j]){
            jump[i] = j+1; j++;
        }

        else jump[i]=0;
    }
}

int find_pattern(){
    int ans=0;
    int j =0;
    int find_str_size = find_str.size();
    int from_str_size = from_str.size();

    for(int i =0; i<from_str_size; i++){
        while(j>0 && find_str[j]!=from_str[i]) j = jump[j-1];

        if(find_str[j]!=from_str[i]) continue;

        if(j==(find_str_size-1)){
            ans++;
            j = jump[j];
            continue;
        }
        j++;
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    getline(cin, from_str);
    getline(cin, find_str);

    KMP_init();

    cout << find_pattern() << "\n";
    for(int cur: loc){
        cout << cur+1 << " ";
    }
    cout << "\n";

    return 0;
}