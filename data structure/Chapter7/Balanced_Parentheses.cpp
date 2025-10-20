#include <iostream>
#include <stack>

using namespace std;

bool check(){
    cout << "enter expression: \n";
    stack<char> s;
    while(cin.peek()!='\n'){
        char c;
        cin >> c;
        switch(c){
            case '(': {
                s.push(c);
                break;
            }

            case ')': {
                if(s.size()==0)
                    return false;
                s.pop();
                break;
            }

            default:{
                break;
            }
        }
    }

    return s.size()==0 ? true: false;
}

int main(){
    cout << check() << endl;
    return 0;
}