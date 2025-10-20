#include <iostream>
#include <string>
#include <array>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    array<int, 27> a1 = {0,};
    array<int, 27> a2 = {0, };

    for(int i =0; i<s1.size(); i++){
        a1[s1[i]-'a']++;
    }
    for(int i =0; i<s2.size(); i++){
        a2[s2[i]-'a']++;
    }

    cout << ((a1==a2)?"같다": "다르다") << endl;

    return 0;
}