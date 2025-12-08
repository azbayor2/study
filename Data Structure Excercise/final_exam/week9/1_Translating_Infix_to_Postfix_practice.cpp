#include <iostream>
#include <stack>
#include <string>
#include <cctype> 

using namespace std;

string infixToPostfixFullyParenthesized(const string& expr) {
    stack<char> s;
    string res = "";

    for(char c: expr){
        if(c=='(') continue;
        else if(c=='+' || c=='-' || c=='*' || c=='/')
            s.push(c);

        else if(c==')'){
            res+=s.top();
            s.pop();
        }

        else{
            res+=c;
        }
    }

    return res;
}

int main() {
    string expr = "((A+7)*(B/C))";
    string postfix = infixToPostfixFullyParenthesized(expr);
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}