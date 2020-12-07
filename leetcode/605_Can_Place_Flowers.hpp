#include "../base/icode.hpp"
class L605 : public icode
{
public:
	void run() {
        vector<int> nums = {1,0,0,0,1};
        cout << canPlaceFlowers(nums, 1) << " true" << endl;
        cout << canPlaceFlowers(nums, 2) << " false" << endl;
        nums = {0,1,0};
        cout << canPlaceFlowers(nums, 1) << " false" << endl;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n, int i = 0) {
        int len = flowerbed.size();
        if (i >= len || n == 0) {
            return n == 0;
        }
        if (!flowerbed[i]) {
            if ((i == 0 && (len == 1 || !flowerbed[i+1])) || 
                (i > 0 && !flowerbed[i-1] && (i == len -1 || !flowerbed[i+1]))) {
                flowerbed[i] = 1;
                return canPlaceFlowers(flowerbed, n - 1, i+1);
            }
        }
        return canPlaceFlowers(flowerbed, n, i+1);
    }
};