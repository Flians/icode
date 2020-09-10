/**
 * Basic Calculator 
 * Functions: support +,-,*,/, (,)
 * input exmaple: 
 * 2+(3*4-5)/6; 
 * -1+3; 
 * 3+(-1)
 * ((1+2)*5)
 * output: result
 * others: 1) overflow: throw exception 2) divided by 0: throw exception. 
 **/

#include <string>
#include <stack>

using namespace std;

int calculate(string input, int index = 0) {
    stack<int> data;
    int item = 0, res = 0;
    char ops = '+';
    for (int i = index; i < input.length(); ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            item = item * 10 + (input[i]-'0');
        } else {
            if (input[i] == '(') {
                item = calculate(input, i+1);
            }
            if (input[i] != ')') {
                switch(ops) {
                    case '+':
                        data.push(item);
                        break;
                    case '-':
                        data.push(0-item);
                        break;
                    case '*':
                        int tmp = data.top() * item;
                        data.pop();
                        data.push(tmp);
                        break;
                    case '/':
                        if (item == 0)
                            throw "/0";
                        int tmp = data.top() / item;
                        data.pop();
                        data.push(tmp);
                        break;
                    default :
                }
                ops = input[i];
                item = 0;
            }
            if (input[i] == ')') {
                break;
            }
        }
    }
    while (!data.empty()) {
        res += data.top();
        data.pop();
    }
    return res;
}