/*
数字、空格、小写字母
1、分词：连续数字/字母
2、分割：一个空格
3、一行：length <= 80
4、跨行：下一行显示
5、某个词超过80、仅保存前80
*/
#include <iostream>
#include <string>
using namespace std;
bool is_digital(char c) {
    return c >= '0' && c <= '9';
}

void print_str(string str) {
    string item = "";
    string line = "";
    bool flag = true;
    for (int i = 0; i < (int) str.length(); ++i) {
        if (flag) {
            if (str[i] != ' ') {
                if (!item.empty()) {
                    if (item.length() > 80) {
                        if (!line.empty()) {
                            cout << line << endl;
                            line = "";
                        }
                        item.substr(0, 80);
                        cout << item << endl;
                    } else {
                        if (line.length() + item.length() > 80) {
                            cout << line << endl;
                            line = item + " ";
                        } else {
                            line += item + " ";
                        }
                        
                    }
                }
                item = str[i];
                flag = false;
            }
            continue;
        }
        if (is_digital(item[0]) == is_digital(str[i])) {
            item += str[i];
        } else {
            flag = true;
            --i;
        }
    }

    if (item.length() > 80) {
        cout << line << endl;
        line = "";
        item.substr(0, 80);
        cout << item << endl;
    } else {
        if (line.length() + item.length() > 80) {
            cout << line << endl;
            cout << item << endl;
        } else {
            cout << line + " " + item << endl;
        }
    }
    
}
int main () {
    print_str("aaa11a a1");
    return 0;
}