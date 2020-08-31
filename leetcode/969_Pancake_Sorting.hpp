#include "../base/icode.hpp"
class L969 : public icode
{
public:
	void run() {
        vector<int> A = {3,2,4,1};
        print_res(pancakeSort(A));
    }

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for (int i = A.size(); i > 0; --i) {
            vector<int>::iterator index = find(A.begin(), A.end(), i);
            if (i == index - A.begin() + 1) {
                continue;
            }
            if (index != A.begin()) {
                res.push_back(index - A.begin() + 1);
                reverse(A.begin(), index + 1);
            }
            res.push_back(i);
            reverse(A.begin(), A.begin()+i);
        }
        return res;
    }
};