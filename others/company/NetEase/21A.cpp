#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<char>> all = {
    {'W','B','T','W','B','T','W','B','T'},
    {'W','T','B','W','T','B','W','T','B'},
    {'T','B','W','T','B','W','T','B','W'},
    {'T','W','B','T','W','B','T','W','B'},
    {'B','T','W','B','T','W','B','T','W'},
    {'B','W','T','B','W','T','B','W','T'},
};

int main () {
    int T;
    cin >> T;
    while (T--) {
        string line;
        bool flag = 0;
        vector<char> inputs(10, 'A');
        for (int i = 0; i < 7; ++i) {      
            cin >> line;  
            if (inputs[line[0] - '0'] != 'A') {
                flag = 1;
            } else {
                inputs[line[0] - '0'] = line[1];
            }
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }
        int i = 0;
        for (auto item : all) {
            for (i = 1; i <= 9; ++i) {
                if (item[i-1]!=inputs[i] && inputs[i] != 'A') {
                    break;
                }
            }
            if (i == 10) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}