#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef pair<int, int> p;

int mvx[5] = {0,0,0,-1,1};
int mvy[5] = {0,-1,1,0,0};

typedef struct {
    p cur_pos;
    bool is_alive;
    int cur_dir;
    vector<int> prior_dir[5];
} shark;

shark Sharks[401];

p smell_board[21][21];
int shark_pos[21][21];
queue<pair<p, p>> q;  //상어 번호, 방향, 다음 좌표

int N, M, k;
int alive_shark;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); std::cout.tie(0);

    for(int i =0; i<21; i++)
        for(int j =0; j<21; j++)
            smell_board[i][j] = {0,0};

    cin >> N >> M >> k;
    alive_shark=M;

    int input;

    for(int i =1; i<=N; i++)
        for(int j =1; j<=N; j++)
        {
            cin >> input;
            shark_pos[i][j] = input;
            if(input==0) continue;
            Sharks[input].cur_pos = p{j, i};
            Sharks[input].is_alive=1;
        }

    for(int i =1; i<=M; i++)  //현재 방향 저장
    {
        cin >> input;
        Sharks[i].cur_dir = input;
    }

    for(int i = 1; i<=M; i++)   //방향 우선순위 저장
        for(int j =1; j<=4; j++)
            for(int l = 0; l<4; l++)
            {
                cin >> input;
                Sharks[i].prior_dir[j].push_back(input);
            }
            
    int ttime=0;
    while(ttime<=1000)
    {
        for(int i =1; i<=N; i++)   //상어 위치 초기화;
            for(int j =1; j<=N; j++)
                shark_pos[i][j] = 0;
        
        for(int i =1; i<=M; i++)  //냄새 마킹
        {
            shark sk = Sharks[i];
            if(sk.is_alive==0) continue; //죽었으면 넘어감
            smell_board[sk.cur_pos.second][sk.cur_pos.first] = p{i, k};  //초기 냄새 4초
        }

        for(int i =1; i<=M; i++)  //상어 이동
        {
            shark sk = Sharks[i];
            if(sk.is_alive==0) continue; //죽었으면 넘어감

            int nx=0, ny=0, ndir; //다음 방향
            int tx=0, ty=0, tdir; // 임시 방향

            for(int l = 0; l<4; l++)
            {
                int j = sk.prior_dir[sk.cur_dir][l]; //현재 방향에 따라 다음 방향을 우선순위에 따라
                int nnx = sk.cur_pos.first + mvx[j];
                int nny = sk.cur_pos.second + mvy[j];
                int nndir = j;

                if(nnx<1 || nnx >N || nny <1 || nny>N) continue; //보드 밖으로 나갔을 때
                if(smell_board[nny][nnx].first == i){  //자기 냄새일 때
                    if(tx==0 && ty==0){
                        tx=nnx; ty=nny; tdir=nndir; continue;
                    }
                }
                if(smell_board[nny][nnx].second!=0) continue; //냄새가 있을 때
                nx = nnx; ny= nny; ndir=nndir; break;
            }

            if(nx==0 && ny==0){  //냄새가 있을 때 자기 냄새로 감
                nx=tx; ny=ty; ndir = tdir;
            }
            
            q.push({{i, ndir}, {nx, ny}}); //queue에 임시 저장
        }

        while(q.size()!=0)  //이동 및 죽이기
        {
            int cur_shark = q.front().first.first;
            int ndir = q.front().first.second;
            p npos = q.front().second;
            q.pop();

            if(shark_pos[npos.second][npos.first]!=0) //상어가 있을 때
            {
                if(shark_pos[npos.second][npos.first]<cur_shark){
                    Sharks[cur_shark].is_alive=0; alive_shark--;  //죽이기
                    continue;
                }
                else{
                    Sharks[shark_pos[npos.second][npos.first]].is_alive=0; alive_shark--;  //죽이기
                    shark_pos[npos.second][npos.first] = cur_shark;  //차지하기
                    Sharks[cur_shark].cur_pos = npos;
                    Sharks[cur_shark].cur_dir = ndir;
                    continue;
                }
            }

            else{  //상어가 없을 때
                shark_pos[npos.second][npos.first] = cur_shark;
                Sharks[cur_shark].cur_pos = npos;
                Sharks[cur_shark].cur_dir = ndir;
                continue;
            }
        }

        for(int i =1; i<=N; i++)    //냄새 시간 갱신
            for(int j =1; j<=N; j++)
            {
                if(smell_board[i][j].second>0){ //냄새가 있을 때
                    smell_board[i][j].second--;
                    if(smell_board[i][j].second==0)  //냄새시간이 0이 되면 바로 없애줌
                        smell_board[i][j].first = 0;
                }
            }
            
        ttime++;
        if(alive_shark==1) break;
    }

    std::cout << (ttime>1000 ? -1 : ttime) << "\n";

    return 0;
}