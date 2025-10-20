#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool evaluate(){
    string str;
    cout << "문자열 입력\n";
    stack<char> s;
    queue<char> q;
    cin >> str;
    for(int i =0; i<str.size(); i++){
        s.push(str[i]);
        q.push(str[i]);
    }

    while(q.size() && s.size()){
        if(q.front()!=s.top())
            return false;

        q.pop(); s.pop();
    }

    return true;
}

int main(){
    cout << evaluate() << endl;

    return 0;
}