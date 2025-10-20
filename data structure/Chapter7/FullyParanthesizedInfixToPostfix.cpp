#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define LEFT_PAREN '('
#define RIGHT_PAREN ')'

string evaluate(){
    stack<char> s;
    string ans = "";
    char c;
    cout << "input fully paranthesized infix expression\n";
    while(cin.peek()!='\n'){
        c = cin.peek();
        switch(c){
            case ' ':{
                cin.ignore();
                break;
            }
            case PLUS: case MINUS: case MULT: case DIV: case LEFT_PAREN:{
                s.push(c);
                cin.ignore();
                break;
            }
            case RIGHT_PAREN:{
                cin.ignore();
                while(s.top()!=LEFT_PAREN){
                    ans+=s.top(); ans+=' '; s.pop();
                }
                s.pop();
                break;
            }
            default:{
                double num;
                cin >> num;

                ans+=to_string(num);
                ans+=' ';
                break;
            }
        }
    }

    return ans;
}

int main(){
    cout << evaluate() << endl;
    return 0;
}