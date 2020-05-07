#include "../base/icode.h"
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class L278
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
        cout << firstBadVersion(5) << endl;
    }
};