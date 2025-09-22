#include <iostream>

using namespace std;

typedef struct _chess{
    int change1;   // (0,0) 이 흰색일 때 뒤집어야 되는것의 개수를 저장
    int change2;   // (0,0) 이 검정색일 때 뒤집어야 되는것의 개수를 저장
    
    _chess operator+(_chess right){
        return {this->change1+right.change1, this->change2+right.change2};
    }
    
    _chess operator-(_chess right){
        return {this->change1-right.change1, this->change2-right.change2};
    }
    
} chess;

chess Chess[2001][2001];
int N, M, K;

int ans = 4000000;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    
    char c;
    
    for(int i =1; i<=N; i++)
        for(int j =1; j<=M; j++){
            cin >> c;
            if((i+j)%2==0){   //짝수일 때
                if(c=='W') Chess[i][j] = {0,1}; //흰색이면 
                else Chess[i][j] = {1,0};        //검정색이면
            }
            else{
                if(c=='B') Chess[i][j] = {0,1};   //검정색이면
                else Chess[i][j] = {1,0};     //흰색이면
            }
            Chess[i][j] = Chess[i][j-1]+Chess[i-1][j]+Chess[i][j]-Chess[i-1][j-1];   //누적 합
        }
        
    for(int i =1; i+K-1<=N; i++){
        for(int j =1; j+K-1<=M; j++){
            chess temp = Chess[i+K-1][j+K-1]-Chess[i-1][j+K-1] - Chess[i+K-1][j-1] + Chess[i-1][j-1];
            ans = min(ans, min(temp.change1, temp.change2));
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}

