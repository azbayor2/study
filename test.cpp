#include <iostream>

using namespace std;

void kmp_init(string str){
    
}


int main(){
    string find_str = "hello";  //찾는 문자
    string from_str = "helloadlakddhellfiadfhelhello";  //찾는 대상

    int count = 0;
    for(int i =0; i<from_str.size(); i++){
        for(int j=0; j<find_str.size(); j++){
            if(find_str[i]!=from_str[j]) break;
            if(j==(find_str.size()-1))
                count++;
        }
    }

    cout << count << "\n";

    return 0;
}