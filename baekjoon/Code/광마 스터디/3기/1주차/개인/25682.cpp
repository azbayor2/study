#include <iostream>

using namespace std;

#define BLACK 'B'
#define WHITE 'W'

typedef struct __chess{
    int white=0;
    int black=0;

    __chess operator+(__chess right){
        return {this->white+right.white, this->black+right.black};
    }

    __chess operator-(__chess right){
        return {this->white-right.white, this->black-right.black};
    }
} chess;

chess Chess[2001][2001];
int N, M, K, big, small;
char c[2001][2001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> c[i][j];
            if(c[i][j]==WHITE){
                Chess[i][j] = {1,0};
            } else{
                Chess[i][j] = {0,1};
            }

            Chess[i][j] = Chess[i][j]-Chess[i-1][j]-Chess[i][j-1]+Chess[i-1][j-1];
        }
    }

    if(K%2==0){
        big = K*K/2;
        small = K*K/2;
    } else{
        big = K*K/2+1;
        small = K*K/2;
    }

    for(int i =1; i+K-1<=N; i++){
        for(int j=1; j+K<=M; j++){
            chess cur = Chess[i+K-1][j+K-1] - Chess[i-1][j+K-1] - Chess[i+K-1][j-1] + Chess[i-1][j-1];
            int count_black = big, count_white = small;
            if(c[i][j]==WHITE) swap(count_black, count_white);

            
        }
    }
}
