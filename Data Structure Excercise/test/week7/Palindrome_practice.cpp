#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    //구현
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
