#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& expr) {
    stack<char> s;
    for(char c: expr){
        if(c=='(') s.push(c);
        else if(c==')'){
            if(s.size()) s.pop();
            else return false;
        } 
    }

    if(s.size()) return false;

    return true;
}

void printResult(const string& expr) {
    if (isBalanced(expr)) {
        cout << "The expression \"" << expr << "\" is Balanced." << endl;
    }
    else {
        cout << "The expression \"" << expr << "\" is Not Balanced." << endl;
    }
}

int main() {
    string expr1 = "((X + Y * (Z + 7)) * (A + B))";
    string expr2 = "((X + Y * (Z + 7) * (A + B))";
    
    printResult(expr1);
    printResult(expr2);

    return 0;
}