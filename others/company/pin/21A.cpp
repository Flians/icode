#include <iostream>
using namespace std;
int main() {
    int K, N;
    cin >> K >> N;
    if (K == 0) {
        cout << "paradox" << endl;
        return 0;
    }
    int in = 0;
    int time = 0;
    for (int i = 0; i < N; ++i) {
        cin >> in;
        K = in - K;
        if (K < 0) {
            K = 0 - K;
        } else if (K > 0) {
            ++time;
        } else if (i != N-1){
            cout << "paradox" << endl;
            return 0;
        }
    }
    cout << K << " " << time << endl;
    return 0;
}