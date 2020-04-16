
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

string fun(string all) {
    map<string ,int> votes;
    int i=0;
    string temp;
    bool flag = true;
    for (; i<all.length(); i++) {
        if (flag) {
            if (all[i]>='A' && all[i]<='Z') {
                temp = all[i];
                flag = false;
            } else {
                return "error.0001";
            }
        } else {
            if (all[i] == ',') {
                flag = true;
                if (votes.count(temp) == 0) {
                    votes[temp] = 1;
                } else {
                    votes[temp] += 1;
                }
                // cout << temp << endl;
                temp = "";
            } else if (all[i] < 'a' || all[i] > 'z') {
                return "error.0001";
            } else {
                temp += all[i];
            } 
        }
    }
    if (votes.count(temp) == 0)
    {
        votes[temp] = 1;
    }
    else
    {
        votes[temp] += 1;
    }
    vector<pair<string, int>> res(votes.begin(), votes.end());
    sort(res.begin(), res.end(), cmp);
    /*
    for (auto item:res)
        cout << item.first << " " << item.second << endl;
    */
    return res[0].first;
}

int main() {
    string all;
    cin >> all;
    cout << fun(all) << endl;
    return 0;
}