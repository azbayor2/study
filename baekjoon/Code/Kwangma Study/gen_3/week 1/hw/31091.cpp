#include <iostream>
using namespace std;

int over[500005], under[500005];
int N, ans, save[500001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int input;

    for(int i =0; i<N; i++){
        cin >> input;
        if(input>0) over[input]++;
        else under[-input]++;
    }

    for(int i =1; i<=N; i++){
        over[i]+=over[i-1];
        under[i]+=under[i-1];
    }

    for(int i =0; i<=N; i++){
        int temp;
        if(i==0){
            temp = over[i] + under[N];
        } else{
            temp = over[i] + under[N] - under[i-1];
        }
        temp = N-temp;
        if(temp == i){
            save[ans++] = i;
        }
    }

    cout << ans << "\n";

    for(int i =0; i<ans; i++){
        cout << save[i] << " ";
    }
    
    return 0;
}