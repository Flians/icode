#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fun(string &input) {
    string res = "";
    unordered_map<char, bool> record;
    int i = 0;
    while (i < input.length()) {
        if (record.count(input[i]) == 0) {
            record[input[i]] = 1;
            res += input[i];
        }
        ++i;
    }
    return res;
}
int main() {
    string input;
    getline(cin, input);
    cout << fun(input) << endl;
}