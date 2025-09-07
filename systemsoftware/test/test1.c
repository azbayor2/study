#include <stdio.h>

int main(){

    int i;
    fprintf(stdout, "a");
    scanf("%d", &i);
    fprintf(stdout, "hi");
    fprintf(stderr, "error");
    fprintf(stdout, "world");
    
    return 0;
}