#include <iostream>
#include <string>
#include <array>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    array<int, 26> arr1 = {0,};
    array<int, 26> arr2 = {0,};

    string s1, s2;

    cin >> s1 >> s2;
    int s1_size = s1.size(), s2_size = s2.size();

    for(int i=0; i<s1_size; i++) arr1[(int)(s1.at(i)-'a')]++;
    for(int i=0; i<s2_size; i++) arr2[(int)(s2.at(i)-'a')]++;
    bool flag=0;

    //array 끼리 비교할 수 있음??
    for(int i =0; i<26; i++){
        if(arr1[i]!=arr2[i]){
            flag=1; break;
        }
    }

    cout << (arr1==arr2 ? "응\n": "아니오\n");

    cout << (flag==0 ? "애너그램이다": "애너그램이 아니다") << "\n";

    return 0;
}