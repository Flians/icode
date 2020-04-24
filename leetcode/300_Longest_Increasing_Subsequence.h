#include "../base/icode.h"

class L300 : public icode
{
public:
    /**
     * 暴力破解 T(O)=O(n^2)
     * 使用一个辅助数组longE[i]记录以对于元素a[i]结尾的子串的最大长度
     * 遍历a[i]之前的元素a[j]，并判断a[i]与a[j]+1的大小来更新longE[i]
     */
    int longIS_DP_N2(vector<int> a)
    {
        int i = 0, j = 0, max = 0;
        int longE[a.size()];
        for (; i < (int)a.size(); i++)
        {
            longE[i] = 1;
            for (j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                    longE[i] = longE[i] > longE[j] + 1 ? longE[i] : longE[j] + 1;
            }
            max = longE[i] > max ? longE[i] : max;
        }
        return max;
    }

    int lower_bound(int *array, int *array_end, int key)
    {
        int first = 0, middle;
        int half, len;
        len = array_end - array;

        while (len > 0)
        {
            half = len >> 1;
            middle = first + half;
            //在右边子序列中查找
            if (array[middle] < key)
            {
                first = middle + 1;
                len = len - half - 1;
            }
            //在左边子序列（包含middle）中查找
            else
                len = half;
        }
        return first;
    }

    /**
     * T(O)=O(nlogn)
     * 使用一个辅助数组lenE[i]记录长度为i+1的字串的最后一个元素，则lenE是一个非递减的数列
     * 对于每个a[i], 在lenE中查找第一个大于等于a[i]的位置temp, 使lenE[temp]=a[i]
     * 最后更新LenE的实际长度max
     */
    int longIS_DP_NlogN(vector<int> a)
    {
        int i = 1, max = 1;
        int lenE[a.size() + 1];
        lenE[0] = a[0];
        for (; i < (int)a.size(); i++)
        {
            int temp = lower_bound(lenE, lenE + max, a[i]);
            // #include <iostream>
            // #include <algorithm>
            // int temp = std::lower_bound(lenE, lenE + max, a[i]) - lenE;
            lenE[temp] = a[i];
            max = max < temp + 1 ? temp + 1 : max;
        }
        return max;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        // return longIS_DP_N2(nums);
        return longIS_DP_NlogN(nums);
    }

    void run()
    {
        int a[8] = {10,9,2,5,3,7,101,18};
        vector<int> nums(a, a+8);
        cout << lengthOfLIS(nums) << endl;
    }
};