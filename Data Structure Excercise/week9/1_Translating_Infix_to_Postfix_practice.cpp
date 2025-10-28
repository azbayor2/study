#include <iostream>
#include <stack>
#include <string>
#include <cctype> 

using namespace std;

string infixToPostfixFullyParenthesized(const string& expr) {
    string ret = "";
    stack<char> s;

    for(char c: expr){
        switch(c){
            case '(':{
                s.push(c);
                break;
            }
            case '+': case '-': case '/': case '*':{
                s.push(c);
                break;
            }
            case ')': {
                while(s.top()!='('){
                    ret+=s.top();
                    s.pop();
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
    string expr = "((A+7)*(B/C))";
    string postfix = infixToPostfixFullyParenthesized(expr);
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}