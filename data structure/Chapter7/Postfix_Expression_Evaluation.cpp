#include <iostream>
#include <stack>

using namespace std;

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'

double evaluate(){
    stack<double> nums;
    cout << "input postfix expression:\n";

    while(cin.peek()!='\n'){
        char c = cin.peek();
        switch(c){
            case ' ':{
                cin.ignore();
                break;
            }
            case PLUS:{
                cin.ignore();
                double rightn = nums.top(); nums.pop();
                double leftn = nums.top(); nums.pop();
                nums.push(leftn+rightn);
                break;
            }
            case MINUS:{
                cin.ignore();
                double rightn = nums.top(); nums.pop();
                double leftn = nums.top(); nums.pop();
                nums.push(leftn-rightn);
                break;
            }
            case MULT:{
                cin.ignore();
                double rightn = nums.top(); nums.pop();
                double leftn = nums.top(); nums.pop();
                nums.push(leftn*rightn);
                break;
            }
            case DIV:{
                cin.ignore();
                double rightn = nums.top(); nums.pop();
                double leftn = nums.top(); nums.pop();
                nums.push(leftn/rightn);
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
    cout << evaluate() << endl;
    return 0;
}