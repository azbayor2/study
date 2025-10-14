#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int start = 0, end = s.size()-1;
    while(start<s.size() && end>=0){
        while(start<s.size() && s[start]==' ')
            start++;
        while(end>=0 && s[end]==' ')
            end--;

        if(start>=s.size() && end<=0) return true;
        if(s[start]!=s[end]) return false;
        start++; end--;
    }

    return true;
}

int main() {
    string input;
    cout << "문자열 입력: ";
    getline(cin, input);

    if (isPalindrome(input))
        cout << "→ 회문입니다." << endl;
    else
        cout << "→ 회문이 아닙니다." << endl;

    return 0;
}
