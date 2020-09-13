#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    getchar();
    string input;
    getline(cin, input);
    string res = "";
    int len = input.length();
    for (int i = 0; i < len; i += n) {
        int beg = min(len-i, n);
        for (int j = beg-1; j >= 0; --j) {
            res += input[i+j];
        }
    }
    cout << res << endl;
    return 0;
}