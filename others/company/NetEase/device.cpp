#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct Device {
    int level;
    int time;
    string uuid;
    Device(){}
    Device(int l, int t, string uuid):level(l),time(t),uuid(uuid){}
};
unordered_map<string, Device> devices = {
    {"1", {1, 10, "1"}}, 
    {"2",{2, 14, "2"}}, 
    {"3", {2, 12, "3"}}, 
    {"4", {2, 13, "4"}}, 
    {"5", {5, 14, "5"}}
};

Device query(string uuid) {
    return devices[uuid];
}

void print_v(vector<string> uuids) {
    for (auto &it : uuids) {
        cout << it << " ";
    }
    cout << endl;
}

bool cmp(string &a, string &b, unordered_map<string, Device> &all) {
    return all[a].level == all[b].level ? all[a].time <= all[b].time : all[a].level < all[b].level;
}

int partition(vector<string> &uuids, int l, int h, unordered_map<string, Device> &all) {
    string mid = uuids[l];
    while (l < h) {
        while(l < h && cmp(mid, uuids[h], all))
            --h;
        uuids[l] = uuids[h];
        while(l < h && cmp(uuids[l], mid, all))
            ++l;
        uuids[h] = uuids[l];
    }
    uuids[l] = mid;
    return l;
}
void sort(vector<string> &uuids, int l, int h, unordered_map<string, Device> &all) {
    if (l < h) {
        int mid = partition(uuids, l, h, all);
        sort(uuids, l, mid - 1, all);
        sort(uuids, mid + 1, h, all);
    }
}
void func(vector<string> &uuids) {
    unordered_map<string, Device> all;
    for (auto uuid : uuids) {
        all[uuid] = query(uuid);
    }
    sort(uuids, 0, uuids.size()-1, all);
}
int main() {
    vector<string> uuids = {"5", "4", "3", "2", "1", };
    func(uuids);
    for (auto &it : uuids) {
        cout << it << " ";
    }
    cout << endl;
}