#include "../base/icode.hpp"
class L957 : public icode
{
public:
	void run() {
        vector<int> nums = {0,1,0,1,1,0,0,1};
        // [0,0,1,1,0,0,0,0]
        print_res(prisonAfterNDays(nums, 7));
        nums = {1,0,0,1,0,0,1,0};
        // [0,0,1,1,1,1,1,0]
        print_res(prisonAfterNDays(nums, 1000000000));
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = (N-1) % 14 + 1;
        while (N-- > 0) {
            for (int j = 1; j < 7; ++j) {
                if (cells[0] == cells[j+1]) {
                    cells[0] = cells[j];
                    cells[j] = 1;
                } else {
                    cells[0] = cells[j];
                    cells[j] = 0;
                }
            }
            cells[0] = cells[7] = 0;
        }
        return cells;
    }
};