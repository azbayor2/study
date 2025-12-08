#include <iostream>
#include <stack>

using namespace std;

int prior(char c){
    if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/') return 2;
    
    return -1;
}

int calc(int a, int b, char c){
    switch(c){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }

    return -1;
}


bool expression_parenthesis_eval(string expr){
    stack<char> s;
    for(char c: expr){
        if(c=='('){
            s.push(c);
            continue;
        }

        else if(c==')'){
            if(!s.size()) return false;
            s.pop();
        }
    }

    if(s.size()) return false;
    return true;
}


string full_paren_inorder_to_postorder(string expr){
    string ret = "";
    stack<char> s;
    for(char c: expr){
        if(c=='(') continue;
        else if(c==')'){
            ret+=s.top();
            s.pop();
            continue;
        }
        else if(c=='+' ||c=='-' ||c=='*' ||c=='/') s.push(c);
        else if(c==' ') continue;
        else
            ret+=c;
    }

    return ret;
}

string inorder_to_postorder(string expr){
    stack<char> op;
    string ret="";

    for(char c: expr){

        if(c=='('){
            op.push(c);
            continue;
        }

        else if(c==')'){
            while(op.size() && op.top()!='('){
                ret+=op.top(); op.pop();
            }
            op.pop();
        }

        else if(c==' ') continue;

        else if(c=='+' || c=='-'){
            while(op.size() && op.top()!='('){
                ret+=op.top(); op.pop();
            }
            op.push(c);
            continue;
        }

        else if(c=='*' || c=='/'){
            while(op.size() && op.top()!='(' && prior(op.top())==2){
                ret+=op.top(); op.pop();
            }
            op.push(c);
            continue;
        }

        else ret+=c;
    }

    while(op.size()){
        ret+=op.top(); op.pop();
    }

    return ret;

}

int evel_full_paren_expr(string expr){
    stack<int> num;
    stack<char> op;

    for(char c:expr){
        if(isalnum(c)){
            num.push(c-'0');
            continue;
        }

        else if(c=='+' ||c=='-' ||c=='*' ||c=='/'){
            op.push(c);
            continue;
        }

        else if(c=='(') continue;

        else if(c==')'){
            int b = num.top(); num.pop();
            int a = num.top(); num.pop();
            char oper = op.top(); op.pop();

            num.push(calc(a, b, oper));
            continue;
        }
    }

    return num.top();
}


int main(){

    string expr1 = "(((6+9)/3)*(6-4))";
    string expr2 = "((X + Y * (Z + 7)) * (A + B))";
    string expr3 = "((X + Y * (Z + 7) * (A + B))";
    string expr4 = "((A+7)*(B/C))";
    string expr5 = "a+b*c-d/(e+f)";


    cout << expression_parenthesis_eval(expr2) << endl;
    cout << expression_parenthesis_eval(expr3) << endl;

    cout << full_paren_inorder_to_postorder(expr4) << endl;

    cout << inorder_to_postorder(expr5) << endl;

    cout << evel_full_paren_expr(expr1) << endl;

    return 0;

}

