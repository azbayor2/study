#include <iostream>

using namespace std;

int N, M, arr[4], cur[4], ans;

bool comparr(const int arr1 [], const int arr2 []){
    // for(int i =0; i<4; i++) cout << arr2[i] << " ";
    // cout << "\n";
    for(int i =0; i<4; i++){
        if(arr1[i]>arr2[i]) return 0;
    }
    return 1;
}

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> str;
    for(int i =0; i<4; i++) cin >> arr[i];

    int s=0, e=0;
    while(e<=N){
        if((e-s)==M){
            if(comparr(arr, cur)) ans++;
        }
        if(e==N) break;
        switch(str[e]){
            case 'A': cur[0]++; break;
            case 'C': cur[1]++; break;
            case 'G': cur[2]++; break;
            case 'T': cur[3]++; break;
        }
        e++;
        while((e-s)>M){
            switch(str[s]){
                case 'A': cur[0]--; break;
                case 'C': cur[1]--; break;
                case 'G': cur[2]--; break;
                case 'T': cur[3]--; break;
            }
            s++;
        }
    }
    cout << ans << "\n";
    return 0;
}