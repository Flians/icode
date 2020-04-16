#include <iostream>
#include <string>
using namespace std;

int main() {
    int a,b,i=0,temp=0;
    string res = "0";
    cin >> a >> b;
    while (a>0 || b>0) {
        temp = a%10;
        temp += b%10;
        res[i]+=temp%10;
        if (temp/10)
            res = (char)(temp/10 + '0') + res;
        a /= 10;
        b /= 10;
    }
    cout << res << endl;
    return 0;
}