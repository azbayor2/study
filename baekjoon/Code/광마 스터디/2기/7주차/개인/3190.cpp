#include <iostream>
#include <vector>
#define LEFT 0
#define RIGHT 2
#define DOWN 3
#define UP 1

using namespace std;

int mvx[4] = {-1,0,1,0};  //좌 상 우 하
int mvy[4] = {0,-1,0,1};

typedef pair<int, int> p;

typedef struct {
    int len = 1;
    vector<p> body;
    int dir = RIGHT;
    bool is_alive=1;
} snake;

snake S;

bool apple[101][101];
bool temp[101][101];
char dir[10001]; //앞으로의 방향 저장
int N, K, X;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    char c;
    
    cin >> N >> K;
    for(int i =0; i<K; i++)  //사과 위치 저장장
    {
        cin >> a >> b;
        apple[a][b] = 1;
    }
    
    cin >> X;
    
    for(int i =0; i<X; i++)  //시간에 따른 방향 저장 
    {
        cin >> a >> c;
        dir[a] = c;
    }
    
    S.body.push_back(p{1,1});
    
    int ttime = 0;
    
    while(ttime<10000)
    {
        //1. 방향 검사
        //cout << S.body[S.len-1].second <<" " << S.body[S.len-1].first << " "<< S.dir << "\n";
        
        if(dir[ttime]=='D' || dir[ttime]=='L')
        {
            switch(dir[ttime]){
                case 'L': {
                    S.dir--;
                    S.dir%=4;
                    //cout << S.dir << " ";
                    if(S.dir<0) S.dir+=4;
                    break;
                }
                
                case 'D': {
                    S.dir++;
                    S.dir%=4;
                    break;
                }
            }
        }
        
        //2. 벽 검사 
        p c = S.body[S.len-1];
        int nx = c.second+mvx[S.dir];
        int ny = c.first+mvy[S.dir];
        
        if(nx<=0 || nx>N || ny<=0 || ny>N){  //다음이 벽이면 
            ttime++;
            break;
        }
        
        //3. 사과 검사
        
        if(apple[ny][nx]){
            S.body.push_back({ny, nx});
            S.len++;
            apple[ny][nx]=0; //사과를 먹었으니까 
            ttime++;
            continue;
        }
        
        //4. 죽었는지 확인(순간적으로 길이가 +1이 되기 때문에 먼저 검사)
        
        S.body.push_back(p{ny, nx});
        
        for(p pp: S.body)
        {
            if(temp[pp.first][pp.second]){
                S.is_alive=0;
                break;
            }
            
            temp[pp.first][pp.second]=1;
        }
        
        if(S.is_alive==0){
            ttime++;
            break;
        }
        
        for(p pp: S.body)
            temp[pp.first][pp.second]=0;
        
        S.body.pop_back();
        
        //5. 이동하기
        
        for(int i =0; i<S.len-1; i++)
            S.body[i] = S.body[i+1];
            
        S.body[S.len-1] = p{ny, nx};
        
        
        ttime++;
    }
    
    cout << ttime << "\n";
    
    
    return 0;
}
