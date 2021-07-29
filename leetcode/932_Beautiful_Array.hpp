#include "../base/icode.hpp"
class L932 : public icode
{
public:
	void run() {
        print_res(beautifulArray(5)); // [1, 5, 3, 2, 4]
    }

    vector<int> beautifulArray(int n) {
        vector<int> res;
        res.push_back(1);
        while (res.size() < (size_t) n) {
            vector<int> tmp;
            for (int i : res) if (i * 2 - 1 <= n) tmp.push_back(i * 2 - 1);
            for (int i : res) if (i * 2 <= n) tmp.push_back(i * 2);
            res = tmp;
        }
        return res;
    }
};