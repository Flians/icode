#include "../base/icode.hpp"
class L274 : public icode
{
public:
	void run() {
        vector<int> cit;
        cout << hIndex(cit) << " 0" << endl;
        cit = {100};
        cout << hIndex(cit) << " 1" << endl;
        cit = {3,0,6,1,5};
        cout << hIndex(cit) << " 3" << endl;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = citations.size() - 1; i >= 0 ; --i) {
            if (citations[i] >= i + 1)
                return i+1;
        }
        return 0;
    }
};