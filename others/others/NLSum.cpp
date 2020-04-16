#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N,L;
    cin >> N >> L;
    int br=0, er=0, lr=100, i=1, j=0, k=N/L;
    for (;i<=k;++i) {
        int ts=0;
        j = i;
        while (ts < N && j<=k)
            ts += (j++);
        int tep = j-i;
        if (ts == N && tep >= L && tep <= lr) {
            // cout << i << " " << j << " " << ts << endl;
            lr = tep;
            br = i;
            er = j;
        }
    }
    if (br==0)
        cout << "No" << endl;
    else {
        cout << (br++);
        while (br<er)
            cout << " " << (br++);
        cout << endl;
    }
    return 0;
}