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
    stack<int> num;
    stack<char> op;

    for(char c: expr){
        if(c>='0' && c<='9'){
            num.push((int)(c-'0'));
        }

        else if(c=='(') continue;

        else if(c=='+'||c=='-'||c=='*'||c=='/'){
            op.push(c);
        }

        else if(c==')'){
            int right = num.top(); num.pop();
            int left = num.top(); num.pop();

            char oper = op.top(); op.pop();

            int res = applyOp(left, right, oper);
            num.push(res);
        }
    }

    return num.top();
}

int main() {
    string expr = "(((6+9)/3)*(6-4))";
    cout << "Result of expression (" << expr << ") is: "
         << evaluateExpression(expr) << endl;
    return 0;
}