#include <iostream>
#include <string>
using namespace std;
bool check(string &str, int l, int r) {
    while (l < r) {
        if (str[l++] != str[r++])
            return false;
    }
    return true;
}

int main () {
    string in;
    cin >> in;
    int i = 0, j = in.length()-1;
    while (i < j) {
        if (in[i] == in[j] && check(in, i, j)) {
            break;
        } else {
            in.insert(in.begin() + j + 1, in[i]);
            ++i;
        }
    }
    cout << in << endl;
    return 0;
}