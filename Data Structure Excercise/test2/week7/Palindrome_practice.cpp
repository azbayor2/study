#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    string news = "";
    for(char c: s){
        if(c==' ') continue;
        news+=c;
    }

    int starts =0, ends=news.size()-1;

    while(starts<=ends){
        if(news[starts]==news[ends]){
            starts++; ends--;
            continue;
        }
        return false;
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
