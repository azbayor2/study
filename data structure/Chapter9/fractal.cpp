#include <iostream>
#include <random>

using namespace std;

void display(int num){
    cout << num << endl;
    return;
}

void make_fractal(int left, int right, int width, int epsilon){
    if(width<=epsilon){
        display(right);
        return;
    }

    int mid = (left+right)/2;
    mid+=(rand()%10-5);

    make_fractal(left, mid, width/2, epsilon);
    make_fractal(mid, right, width/2, epsilon);
}


int main(){
    make_fractal(4, 10, 8, 1);

    return 0;
}