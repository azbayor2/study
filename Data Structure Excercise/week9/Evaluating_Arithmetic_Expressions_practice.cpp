#include <iostream>
#include <stack>
#include <string>
#include <cctype> // isdigit 함수를 사용하기 위함

using namespace std;

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluateExpression(const string& expr) {
    stack<char> ch;
    stack<int> i;

    for(char c: expr){
        if(isdigit(c)){
            i.push(c-'0');
        } else if(c=='('){
            continue;
        } else if(c==')'){
            char op = ch.top(); ch.pop();
            int right = i.top(); i.pop();
            int left = i.top(); i.pop();
            int ret = applyOp(left, right, op);
            i.push(ret);
        } else{
            ch.push(c);
        }
    }

    return i.top();
}

int main() {
    string expr = "(((6+9)/3)*(6-4))";
    cout << "Result of expression (" << expr << ") is: "
         << evaluateExpression(expr) << endl;
    return 0;
}