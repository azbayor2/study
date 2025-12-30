#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int main(){
    string option[2] = {"꽃잎 맥주", "민들레 뜨락"};

    int random = rand();

    int res;
    for(int i =0; i<random; i++) res = rand();

    cout << "술집은?? ";
    cout << option[rand()%2] << "\n";

    return 0;
}