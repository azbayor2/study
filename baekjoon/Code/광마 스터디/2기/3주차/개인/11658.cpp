#include <iostream>

using namespace std;

int arr[1025][1025];
int seg_tree[5000][5000];
int N, M;

void init_segx(int y1, int y2, int x1, int x2, int nodey, int nodex)
{
    if(x1==x2)
    {
        if(y1==y2)
        {
            seg_tree[nodey][nodex] = arr[y1][x1];
            return;
        }
        
        seg_tree[nodey][nodex] = seg_tree[nodey*2][nodex] + seg_tree[nodey*2+1][nodex];
        return;
    }
    
    int midx = (x1+x2)/2;
    
    init_segx(y1, y2, x1, midx, nodey, nodex*2);
    init_segx(y1, y2, midx+1, x2, nodey, nodex*2+1);
    
    seg_tree[nodey][nodex] = seg_tree[nodey][nodex*2] + seg_tree[nodey][nodex*2+1];
}

void init_segy(int y1, int y2, int nodey)
{
    if(y1==y2)
    {
        init_segx(y1, y2, 1, N, nodey, 1);
        return;
    }
    
    int midy = (y1+y2)/2;
    init_segy(y1, midy, nodey*2), init_segy(midy+1, y2, nodey*2+1);
    init_segx(y1, y2, 1, N, nodey, 1);
    
    return;
}

void seg_updatex(int y1, int y2, int x1, int x2, int b, int a, int n, int nodey, int nodex)
{
    if(x1==x2)
    {
        if(x1!=a) return;
        if(y1==y2)
        {
            seg_tree[nodey][nodex] = n;
            return;
        }
        
        seg_tree[nodey][nodex] = seg_tree[nodey*2][nodex] + seg_tree[nodey*2+1][nodex];
        return;
    }
    
    if(x1>a || x2<a) return;
    
    int midx = (x1+x2)/2;
    seg_updatex(y1, y2, x1, midx, b, a, n, nodey, nodex*2);
    seg_updatex(y1, y2, midx+1, x2, b, a, n, nodey, nodex*2+1);
    
    seg_tree[nodey][nodex] = seg_tree[nodey][nodex*2] + seg_tree[nodey][nodex*2+1];
    
    return;
}

void seg_updatey(int y1, int y2, int b, int a, int n, int nodey)
{
    if(y1==y2)
    {
        if(y1!=b) return;
        seg_updatex(y1, y2, 1, N, b, a, n, nodey, 1);
        return;
    }
    
    if(y1> b || y2<b) return;
    
    int midy = (y1+y2)/2;
    seg_updatey(y1, midy, b, a, n, nodey*2);
    seg_updatey(midy+1, y2, b, a, n, nodey*2+1);
    
    seg_updatex(y1, y2, 1, N, b, a, n, nodey, 1);
    
    return;
}

int get_ansx(int y1, int y2, int x1, int x2, int b1, int b2, int a1, int a2, int nodey, int nodex)
{
    if(x1>a2 || x2<a1) return 0;
    
    if(x1>=a1 && x2<=a2)
        return seg_tree[nodey][nodex];
    
    int midx = (x1+x2)/2;
    return get_ansx(y1, y2, x1, midx, b1, b2, a1, a2, nodey, nodex*2) + get_ansx(y1, y2, midx+1, x2, b1, b2, a1, a2, nodey, nodex*2+1);
}

int get_ansy(int y1, int y2, int b1, int b2, int a1, int a2, int nodey)
{
    if(y1>b2 || y2<b1) return 0;
    
    if(y1>=b1 && y2<=b2) return get_ansx(y1, y2, 1, N, b1, b2, a1, a2, nodey, 1);
    
    int midy = (y1+y2)/2;
    
    return get_ansy(y1, midy, b1, b2, a1, a2, nodey*2) + get_ansy(midy+1, y2, b1, b2, a1, a2, nodey*2+1);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i =1; i<=N; i++)
        for(int j =1; j<=N; j++)
            cin >> arr[j][i];
            
    init_segy(1, N, 1);
    
    int a, b, c, d, e;
    
    for(int i =0; i<M; i++)
    {
        cin >> a;
        if(a==0)
        {
            cin >> b >> c >> d;
            seg_updatey(1, N, c, b, d,1);
            continue;
        }
        
        cin >> b >> c >> d >> e;  //x1 y1 x2 y2
        cout << get_ansy(1, N, c, e, b, d, 1) << "\n";
    }
    
    return 0;
}