#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 26> arr1={0, };
    array<int, 26> arr2={0, };

    string s1, s2;
    cin >> s1 >> s2;

    for(int i =0; i<s1.size(); i++)
        arr1[s1[i]-'a']++;

    for(int i =0; i<s2.size(); i++)
        arr2[s2[i]-'a']++;

    cout << (arr1==arr2 ? "애너그램이다": "애너그램이 아니다") << endl;

    return 0;
}