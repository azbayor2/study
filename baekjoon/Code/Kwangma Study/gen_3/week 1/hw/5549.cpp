#include <iostream>

using namespace std;

typedef struct _worldmap{
    int jungle=0;
    int ice=0;
    int ocean=0;

    _worldmap operator+(_worldmap S){
        return {this->jungle+S.jungle, this->ice+S.ice, this->ocean+S.ocean};
    }

    _worldmap operator-(_worldmap S){
        return {this->jungle-S.jungle, this->ice-S.ice, this->ocean-S.ocean};
    }
} worldmap;

worldmap World[1001][1001];

char C, input;
int N, M, K, a, b, c, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i =1; i<=N; i++){
        for(int j =1; j<=M; j++){
            cin >> C;
            switch(C){
                case 'J':{
                    World[i][j] = {1,0,0};
                    break;
                }

                case 'I':{
                    World[i][j] = {0,1,0};
                    break;
                }

                case 'O':{
                    World[i][j] = {0,0,1};
                    break;
                }
            }

            World[i][j] = World[i][j]+World[i-1][j]+World[i][j-1]-World[i-1][j-1];
        }
    }

    for(int i =0; i<K; i++){
        cin >> a >> b >> c >> d; 
        worldmap temp = World[c][d]-World[a-1][d]-World[c][b-1] + World[a-1][b-1];
        cout << temp.jungle << " " << temp.ocean << " " << temp.ice << "\n";
    }

    return 0;
}