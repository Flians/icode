#include "../base/icode.hpp"
class L84 : public icode
{
public:
	void run() {
        cout << largestRectangleArea({2,1,5,6,2,3}) << " 10" << endl;
        cout << largestRectangleArea({2}) << " 2" << endl;
        cout << largestRectangleArea({2,4}) << " 4" << endl;
    }

    int largestRectangleArea(vector<int>&& heights) {
        int res = 0;
        stack<int> record;
        heights.push_back(0);
        for (int i = 0, len = heights.size(); i < len; ++i) {
            while (!record.empty() && heights[record.top()] >= heights[i]) {
                int last = record.top();
                record.pop();
                res = max(res, (record.empty() ? i : i - record.top() - 1) * heights[last]);
            }
            record.push(i);
        }
        return res;
    }
};