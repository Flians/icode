#include "../base/icode.hpp"
class L1539 : public icode
{
public:
	void run() {
        cout << findKthPositive({2,3,4,7,11}, 5) << " 9" << endl;
        cout << findKthPositive({1,2,3,4}, 2) << " 6" << endl;
    }

    int findKthPositive(vector<int>&& arr, int k) {
        int low = 0, high = arr.size()-1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] - (1 + mid) < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};