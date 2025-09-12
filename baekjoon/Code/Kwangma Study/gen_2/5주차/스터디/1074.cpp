//한정연
#include <iostream>

using namespace std;

int N, R, C;
int mvx[4] = {0,1,0,1}; //위치 1  2
int mvy[4] = {0,0,1,1}; //     3  4

int dfs(int r, int c, int cr, int cc, int size)
{
    if(size==1) return 0;
    int mid = size/2;
    
    for(int i =0; i<4; i++)
    {
        int ny = cr+mvy[i]*mid;
        int nx = cc+mvx[i]*mid;
        //cout << ny << nx;
        
        if(r>=ny && r<ny+mid && c>=nx && c<nx+mid)  //범위 안에 있으면
            return dfs(r, c, ny, nx, size/2)+mid*mid*i;  
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> R >> C;
    int temp = 1<<N;
    cout << dfs(R, C, 0, 0, temp);
    
    return 0;
    
}