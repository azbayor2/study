#include <iostream>
using namespace std;

int N, M, arr[4], cur[4], ans;
string str;

//오른쪽의 배열 값이 왼쪽보다 무조건 크면 true 반환
bool comparr(const int arr1 [], const int arr2 []){
    for(int i =0; i<4; i++){
        if(arr1[i]>arr2[i]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> str;
    for(int i =0; i<4; i++) cin >> arr[i];

    int s=0, e=0;
    while(e<=N){
        if((e-s)==M){
            if(comparr(arr, cur)) ans++;  //현재의 acgt개수가 답의 조건 이상이면
        }
        if(e==N) break;
        switch(str[e++]){  //e 늘리기
            case 'A': cur[0]++; break;
            case 'C': cur[1]++; break;
            case 'G': cur[2]++; break;
            case 'T': cur[3]++; break;
        }
        while((e-s)>M){  //e를 늘려서 길이가 M이 초과됨-> M보다 작아질때까지 s 옮기기
            switch(str[s++]){
                case 'A': cur[0]--; break;
                case 'C': cur[1]--; break;
                case 'G': cur[2]--; break;
                case 'T': cur[3]--; break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}