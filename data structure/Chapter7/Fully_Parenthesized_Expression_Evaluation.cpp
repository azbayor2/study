#include <iostream>
#include <stack>

using namespace std;

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define LEFT_PAREN '('
#define RIGHT_PAREN ')'

double evaluate(){
    cout <<"enter fully parenthesized expression\n";
    stack<char> operators;
    stack<double> nums;

    while(cin.peek()!='\n'){
        char c;
        c = cin.peek();

        switch(c){
            case PLUS: case MINUS: case MULT: case DIV:{
                cin >> c;
                operators.push(c);
                break;
            }

            case LEFT_PAREN:{
                cin >> c;
                break;
            }
            case RIGHT_PAREN: {
                cin >> c;
                char o = operators.top(); operators.pop();
                double rightn = nums.top(); nums.pop();
                double leftn = nums.top(); nums.pop();

                switch(o){
                    case PLUS:{
                        nums.push(leftn+rightn);
                        break;
                    }
                    case MINUS:{
                        nums.push(leftn-rightn);
                        break;
                    }
                    case MULT:{
                        nums.push(leftn*rightn);
                        break;
                    }
                    case DIV:{
                        nums.push(leftn/rightn);
                        break;
                    }
                }
                break;
            }
            default:{
                double input;
                cin >> input;
                nums.push(input);
                break;
            }
        }
    }

    return nums.top();
}

int main(){
    cout << evaluate() << "\n";
    return 0;
}