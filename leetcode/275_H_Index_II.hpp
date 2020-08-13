#include "../base/icode.hpp"
class L275 : public icode
{
public:
	void run() {
        vector<int> citations = {0};
        cout << hIndex(citations) << " 0" << endl;
    }

    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while(l < r) {
            int mid = l + (r - l)/2;
            if ((int)citations.size() - mid <= citations[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return citations.size() - l;
    }
};