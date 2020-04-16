#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, N, B, i, index=1;
    cin >> T;
    while (T--) {
        cin >> N >> B;
        vector<int> houses;
        int temp;
        for (i=0; i< N; i++) {
            cin >> temp;
            houses.push_back(temp);
        }
        sort(houses.begin(), houses.end());
        int num = 0;
        for (i=0; i < N && B >= houses[i]; B -= houses[i++]) {
            num++;
        }
        vector<int>().swap(houses);
        cout << "Case #" << (index++) << ": " << num << endl;
    }
    return 0;
}