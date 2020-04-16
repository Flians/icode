#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double PI = 3.1415926;

int main() {
    int n;
    cin >> n;
    vector<int> r(n,0);
    int i=n;
    while (i--) {
        cin >> r[i];
    }
    sort(r.begin(), r.end(), greater<int>());
    vector<int>::iterator it = r.begin();
    double area = 0.0;
    bool flag = true;
    while (it != r.end())
    {
        if (flag) {
            flag = false;
            area += (*it)*(*it);
        }else
        {
            flag = true;
            area -= (*it)*(*it);
        }
        it++;
    }
    area *= PI;
    cout << fixed << setprecision(5) << area << endl;
    return 0;
}