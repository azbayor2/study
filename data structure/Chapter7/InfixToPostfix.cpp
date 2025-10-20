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
    char c;
    stack<char> s;
    cout << "enter infix notated expression\n";
    string ans = "";
    while(cin.peek()!='\n'){
        c = cin.peek();
        switch(c){
            case ' ':{
                cin.ignore();
                break;
            }
            case PLUS: case MINUS:{
                cin.ignore();
                while(s.size() && (s.top()!=LEFT_PAREN)){
                    ans+=s.top(); ans+=' '; s.pop();
                }
                s.push(c);
                break;
            }

            case MULT: case DIV:{
                cin.ignore();
                while(s.size() && s.top()!=LEFT_PAREN && (s.top()==MULT || s.top()==DIV)){
                    ans+=s.top(); ans+=' '; s.pop();
                }
                s.push(c);
                break;
            }

            case LEFT_PAREN:{
                cin.ignore();
                s.push(c);
                break;
            }

            case RIGHT_PAREN: {
                cin.ignore();
                while(s.size() && s.top()!=LEFT_PAREN){
                    ans+=s.top(); ans+=' '; s.pop();
                }
                s.pop();
                break;
            }

            default: {
                double d;
                cin >> d;
                ans+=to_string(d);
                ans+=' ';
                break;
            }
        }
    }

    while(s.size()){
        ans+=s.top(); ans+=' ';
        s.pop();
    }

    return ans;
}

int main(){
    cout << evaluate() << endl;
    return 0;
}