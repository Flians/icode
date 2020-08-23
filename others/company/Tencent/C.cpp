#include <iostream>
#include <vector>
using namespace std;

long long suma(long long a){
    long long sum = 0;
    while (a) {
        sum += (a%10);
        a /= 10;
    }
    return sum;
}

long long find_max_val(long long n) {
    long long max_val = 0;
    for (long long i = 1; i <= n/2; ++i) {
        max_val = max(max_val, suma(i) + suma(n - i));
    }
    return max_val;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << find_max_val(n) << endl;
    }
    return 0;
}