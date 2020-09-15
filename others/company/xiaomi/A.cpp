#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool check(string &input) {
    stack<char> record;
    size_t i = 0;
    while (i < input.length()) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            record.push(input[i]);
        } else if (!record.empty()) {
            if ((input[i] == ')' &&record.top() != '(') || 
                (input[i] == ']' && record.top() != '[') || 
                (input[i] == '}' && record.top() != '{')) {
                    return false;
            }
            record.pop();
        } else {
        	return false;
        }
        ++i;
    }
	return record.empty();
}

int main() {
    string input;
    getline(cin, input);
    cout << (check(input) ? "true" : "false") << endl;
}