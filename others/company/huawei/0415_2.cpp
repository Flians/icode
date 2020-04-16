#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

int main (){
    string name;
    cin >> name;
    string str;
    cin >> str;
    bool flag = false;
    vector<vector<string> > res;
    unsigned beg=0;
    unsigned temp=0;
    smatch match;
    regex pattern(name + "\\[addr=(0[xX][0-9a-zA-Z]+),mask=(0[xX][0-9a-zA-Z]+),val=(0[xX][0-9a-zA-Z]+)");
    while ((temp = str.find_first_of("]", beg)) != -1) {
        string item = str.substr(beg, temp);
        if (regex_search(item, match, pattern)) { 
            vector<string> tres;
            tres.push_back(match[1]);
            tres.push_back(match[2]);
            tres.push_back(match[3]);
            res.push_back(tres);
            // cout << match[1] << " " << match[2] << " " << match[3] << endl;
            flag = true;
        }
        beg = temp + 2;
    }
    
    if (flag) {
        for (auto item : res) {
            cout << item[0] << " " << item[1] << " " << item[2] << endl;
        }
    } else {
        cout << "FALL" << endl;
    }
    
    return 0;
}