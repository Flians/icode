#include "../base/icode.hpp"

class L11 : public icode
{
public:
    // max{(j-i)*min(ai,aj)}
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int max_temp = 0;
        /*
        for(;i<height.size()-1;i++)
        {
            for(j=i+1;j<height.size();j++)
            {
                max_temp = max(max_temp, (j-i)*min(height[i], height[j]));
            }
        }
        */
        while (i != j)
        {
            if (height[i] < height[j])
            {
                max_temp = max(max_temp, (j - i) * height[i]);
                i++;
            }
            else
            {
                max_temp = max(max_temp, (j - i) * height[j]);
                j--;
            }
        }
        return max_temp;
    }

    void run()
    {
    }
};