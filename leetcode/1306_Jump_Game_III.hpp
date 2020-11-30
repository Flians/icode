#include "../base/icode.hpp"
class L1306 : public icode
{
public:
	void run() {
        vector<int> arr = {4,2,3,0,3,1,2};
        cout << canReach(arr, 5) << " true" << endl;
        cout << canReach(arr, 0) << " true" << endl;
        arr = {3,0,2,1,2};
        cout << canReach(arr, 2) << " false" << endl;
    }

    bool canReach(vector<int>& arr, int start) {
        if (start >=0 && start < (int) arr.size() && arr[start] >=0) {
            if (arr[start] == 0) {
                return true;
            }
            arr[start] = -arr[start];
            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        return false;
    }
};