#include <iostream>
#include <stack>
#include <string>
#include <cctype> 

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& expr) {
    string ret = "";
    stack<char> s;
    for(char c: expr){
        switch(c){
            case '+': case '-':{
                while(s.size() && s.top()!='('){
                    ret+=s.top();
                    s.pop();
                }
                s.push(c);
                break;
            }

            case '*': case '/': {
                while(s.size() && (s.top()=='*' || s.top()=='/') && s.top()!='('){
                    ret+=s.top();
                    s.pop();
                }
                s.push(c);
                break;
            }

            case ')':{
                while(s.size() && s.top()!=')'){
                    ret+=s.top(); s.pop();
                }
                s.pop();
                break;
            }
            default: {
                ret+=c;
                break;
            }
        }
    }

    while(s.size()){
        ret+=s.top(); s.pop();
    }

    return ret;
}

int main() {
    string expr = "A+B*C-D/E";
    string postfix = infixToPostfix(expr);
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}