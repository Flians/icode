#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    bool vis[len];
    int i=1, j=0, num=0;
    while (i<=9) {
        cin >> num;
        char tmp = i+'0';
        j = 0;
        for (; j<len; j++) {
            if (tmp == str[j] && !vis[j]) {
                str[j] = num + '0';
                vis[j] = true;
            }
        }
        ++i;
    }
    cout << str << endl;
    return 0;
}