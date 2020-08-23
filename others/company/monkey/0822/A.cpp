#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, i = 0;
    cin >> N;
    vector<int> nodes(N, 0);
    for (; i < N; ++i) {
        cin >> nodes[i];
    }
    if (N == 1) {
        cout << nodes[0] << endl;
    } else if (N == 2) {
        cout << nodes[0] << " " << nodes[1] << endl;
    } else if (N == 3) {
        cout << nodes[0] << " " << nodes[1] << " " << nodes[2] << endl;
    } else {
        i = 1;
        vector<int> right;
        while (i <= N) {
            cout << nodes[i-1] << " ";
            if (i > 2)
                right.push_back(nodes[i-2]);
            i *= 2;
        }
        for (i /= 2; i < N; ++i) {
            cout << nodes[i] << " ";
        }
        for (i = right.size()-1; i > 0; --i) {
            cout << right[i] << " ";
        }
        cout << right[0] << endl;
    }
    return 0;
}