#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, a;
int arr[100001];
map<int, int> m;
int v[100001];
int vcount;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =1; i<=N; i++)
        cin >> arr[i];

    for(int i =1; i<=N; i++){
        cin >> a;
        m[a] =i;
    }

//두 수열의 최장 공통 부분 수열이 있을 때
//하나를 기준 수열로 두고
//다른 수열은 저장된 숫자의 인덱스 번호가 증가해야함.
//(왼쪽에서 오른쪽으로 가기 때문)
//재정렬후 LIS 알고리즘 사용함.
    
    for(int i =1; i<=N; i++){
        int cur = m[arr[i]];
        if(vcount==0 || v[vcount-1]<cur){
            v[vcount++]=cur;
            continue;
        }

        int *p = upper_bound(v, v+vcount, cur);
        *p = cur;
    }

    cout << vcount << "\n";

    return 0;
    
}