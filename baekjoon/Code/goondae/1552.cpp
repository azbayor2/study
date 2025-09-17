#include <iostream>

using namespace std;

int N, mmax = -100000000, mmin = 100000000;
int arr[7][7];

void dfs(int start, int cur, int mask, int ans, int grp, bool flag){
    if(flag==1 && start==cur)
    {
        mask = mask | (1<<start); grp++;
        if(mask == ((1<<N)-1)){
            int temp = (grp%2)==0 ? -ans:ans;
            mmax = max(mmax, temp); mmin = min(mmin, temp);
            return;
        }
        else{
            for(int i =0; i<N; i++){
                if((mask &(1<<i))==0){
                    dfs(i, i, mask | (1<<i), ans, grp, 0);
                    break;
                }
            }
        }
        return;
    }

    
    for(int i = 0; i<N; i++){
        if((mask & (1<<i))!=0) continue;
        int next_mask = (flag==1) ? mask|(1<<cur):mask;
        dfs(start, i, next_mask, ans*arr[cur][i], grp, 1);
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    char c;

    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++){
            cin >> c;
            if(c>='0' && c<='9') arr[i][j] = (int)(c-'0');
            else arr[i][j] = -((int)(c-'A')+1);
        }
    dfs(0, 0, 0, 1, 0, 0);

    cout << mmin << "\n" << mmax << "\n";

    return 0;
}