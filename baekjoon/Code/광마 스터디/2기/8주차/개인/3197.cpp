#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> p;

typedef struct{
    int first;
    int second;
    int ttime;
} info;  //x,y,시간 저장 

queue<info> icebreak; //얼음이 녹는 위치 저장
queue<p> meet[2]; //짝수/홀수시간으로 나눠서 백조가 현 위치에서 갈수 있는 최대 위치까지 저장
string s[1501]; //판 저장
int N, M, mvx[4]={-1,0,1,0}, mvy[4]={0,1,0,-1};  //입력 크기, 이동 방향 저장
p b1; bool m[1501][1501]; //백조의 위치, 백조의 방문 여부 저장

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N; i++){
        cin >> s[i];
        int loc = s[i].find('L');
        if(loc!=-1) b1 = {loc, i}; //백조의 위치 저장 (아무거나)
        for(int j=0; j<M; j++)
            if(s[i][j]!='X') icebreak.push({j,i,0}); //물위치 큐에 넣기(이 때 백조도 물임)
    }
    //cout << icebreak.size() << "\n";  //디버깅코드
    meet[0].push(b1); m[b1.second][b1.first]=1; //백조방문표기 및 queue에 넣기(한마리 기준으로)
    int ttime = 0; //진행 시간
    while(icebreak.size()!=0){
        while(meet[ttime%2].size()!=0){  //백조가 만날 수 있는지 검사 및 다음 타임에 녹는 얼음으로 인해 갈 수 있는 위치 저장, 시간의 홀짝성 이용.
            p cur = meet[ttime%2].front(); meet[ttime%2].pop();
            for(int i =0; i<4; i++){
                p next = {cur.first+mvx[i], cur.second+mvy[i]};
                if(next.first<0 || next.first>=M || next.second<0 || next.second>=N) continue;
                if(m[next.second][next.first]==1) continue; 
                if(s[next.second][next.first]=='L'){ //만약에 다른 백조를 만났으면
                    cout << ttime << "\n";
                    return 0;
                }
                if(s[next.second][next.first]=='X'){ //다음 시간에 갈 수 있는 위치 queue에 저장 및 방문 표기
                    meet[(ttime+1)%2].push(next);
                    m[next.second][next.first]=1;
                    continue;
                }
                m[next.second][next.first]=1;
                meet[ttime%2].push(next);
            }
        }
        //cout << meet[(ttime+1)%2].size() << "ttime\n";   //디버깅 코드
        while(icebreak.size()!=0 && icebreak.front().ttime==ttime){    //얼음 녹이기 시뮬레이션
            info cur = icebreak.front(); icebreak.pop();
            for(int i =0; i<4; i++){
                info next = {cur.first+mvx[i], cur.second+mvy[i], ttime+1};
                if(next.first<0 || next.first>=M || next.second<0 || next.second>=N) continue;
                if(s[next.second][next.first]=='.') continue;
                s[next.second][next.first]= (s[next.second][next.first]=='L'? 'L': '.'); icebreak.push(next);  //백조의 표기는 유지하기
            }
        }
        ttime++;
    }
    return 0;
}