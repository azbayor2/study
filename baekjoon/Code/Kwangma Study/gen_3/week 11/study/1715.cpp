#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

priority_queue<ll> q;  //우선순위 큐
ll N, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N; ll input;
    for(int i =0; i<N; i++){
        cin >> input; q.push(-input);  //오름차순으로 정렬하기 위해 음수로 저장
    }

    while(q.size()>=2){
        ll a = -q.top(); q.pop(); //가장 작은 수
        ll b = -q.top(); q.pop();  //두번째로 작은 수
        ans+=(a+b);   //계산 후 ans에 증감
        q.push(-(a+b));  //새로 만든 수 우선순위큐에 넣기
    }

    cout << ans << "\n";

    return 0;
}