#include "../base/icode.hpp"

int N=5, T=0;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return version > T;
}

class L278 : public icode
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    void run()
    {
        srand((unsigned)time(NULL));
        T = rand()%N;
        cout << firstBadVersion(N) << endl;
    }
};