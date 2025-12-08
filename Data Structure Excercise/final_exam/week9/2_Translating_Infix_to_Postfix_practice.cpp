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
        if(c=='+'||c=='-'){
            while(s.size() && s.top()!='(' && precedence(s.top())>=1){
                ret+=s.top();
                s.pop();
            }
            s.push(c);
            continue;
        }

        else if(c=='(')
            s.push(c);

        else if(c==')'){
            while(s.size() && s.top()!='('){
                ret+=s.top();
                s.pop();
            }
            s.pop();
        }

        else if(c=='*'||c=='/'){
            while(s.size() && s.top()!='(' && precedence(s.top())>=2){
                ret+=s.top();
                s.pop();
            }
            s.push(c);
        }

        else
            ret+=c;
    }

    while(s.size()){
        ret+=s.top();
        s.pop();
    }

    return ret;
}

int main() {
    string expr = "((A+7)*(B/C))";
    string postfix = infixToPostfix(expr);
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}