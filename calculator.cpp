#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <cctype>

using namespace std;

#define DECIMAL '.'
#define RIGHT_PARENTHESIS '('
#define LEFT_PARENTHESIS ')'
#define ADD '+'
#define SUBS '-'
#define MULT '*'
#define DIV '/'

string InfixToPostfix(istream &is){
    stack<char> operators;
    string ans;

    while(is && is.peek()!='\n'){
        
        // if(is.peek()== ' '){
        //     char c; is >> c;
        //     continue;
        // }
        if(isdigit(is.peek()) || is.peek()==DECIMAL){   //숫자이면
            int d;
            is >> d;
            ans+=to_string(d);
            continue;
        }

        else if(is.peek()=='('){    //   (  이면
            char c;
            is >> c;
            operators.push(c);
            continue;
        }

        else if(is.peek()==')'){   //   ) 이면
            char c; is>> c;
            while(operators.top()!=LEFT_PARENTHESIS){
                ans+= operators.top();
                operators.pop();
            }
            operators.pop();
            continue;
        }

        else{
            char c;
            is >> c;
            switch(c){
                case ADD: case SUBS:{
                    while(!operators.empty() && (operators.top()!= LEFT_PARENTHESIS)){
                        ans+=operators.top();
                        operators.pop();
                    }
                    operators.push(c); break;
                }

                case MULT: case DIV:{
                    while(!operators.empty() && (operators.top()!= LEFT_PARENTHESIS || operators.top()!=ADD || operators.top()!= SUBS)){
                        ans+=operators.top();
                        operators.pop();
                    }

                    operators.push(c); break;
                }

            }
        }
    }

    while(!operators.empty()){
        ans+=operators.top();
        operators.pop();
    }

    return ans;
}


int main(){
    string s;
    cin >> s;

    istringstream iss(s);

    cout << InfixToPostfix(iss) << "\n";
    fflush(stdout);

    return 0;

}