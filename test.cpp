#include <queue>
#include <vector>

int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};

void bfs(int x, int y){
    //...
    for(int i =0; i<4; i++){
        int nx = x+mvx[i];
        int ny = y+mvy[i];
        //1. 주어진 범위 안에 있는지 검사
        //2. 방문한 노드인지
        //3. 탐색에서 주어진 조건을 만족하는지  
    }
}