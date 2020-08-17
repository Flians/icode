#include "../base/icode.hpp"
class L1103 : public icode
{
public:
	void run() {
        // [15,18,15,12]
        print_res(distributeCandies(60, 4));
    }

    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> dc(num_people, 0);
        int index = 0;
        while (candies > 0) {
            index++;
            if (candies >= index) {
                dc[(index-1)%num_people] += index;
                candies -= index;
            }else {
                dc[(index-1)%num_people] += candies;
                candies = 0;
                break;
            }
        }
        return dc;
    }
};