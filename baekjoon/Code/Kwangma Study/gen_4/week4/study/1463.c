#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int minn(int x, int y){
    if(x>y) return y;
    return x;
}

int solve(int cur, int * arr){
    if(cur==1) return 0;
    if(cur==2 || cur==3) return 1;
    //printf("%d", arr[cur]);
    if(arr[cur]!=(1<<28)) return arr[cur];

    if(cur%3==0) arr[cur] = minn(arr[cur], solve(cur/3, arr)+1);
    if(cur%2==0) arr[cur] = minn(arr[cur], solve(cur/2, arr)+1);
    arr[cur] = minn(solve(cur-1, arr)+1, arr[cur]);
    //printf("%d", arr[cur]);
    return arr[cur];
}

int main(){
    int N;
    scanf("%d", &N);

    int * arr = (int*)malloc(sizeof(int)*1000001);
    for(int i =0; i<1000001; i++) arr[i] = 1<<28;

    printf("%d\n", solve(N, arr));

    return 0;

}