#include "../base/icode.hpp"
class L4 : public icode
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l1 = nums1.size(), l2 = nums2.size();
        int len = l1 + l2;
        int i = 0, j = 0, num1 = 0, num2 = 0;
        while (i + j <= len / 2)
        {
            num2 = num1;
            if (i >= l1)
                num1 = nums2[j++];
            else if (j >= l2)
                num1 = nums1[i++];
            else
            {
                if (nums1[i] < nums2[j])
                {
                    num1 = nums1[i++];
                }
                else
                {
                    num1 = nums2[j++];
                }
            }
        }
        if (len % 2 == 1)
        {
            return num1;
        }
        else
        {
            return (num1 + num2) / 2.0;
        }
    }

    void run()
    {
        int a[] = {1, 2};
        vector<int> nums1(a, a + 2);
        int b[] = {3, 4};
        vector<int> nums2(b, b + 2);
        cout << findMedianSortedArrays(nums1, nums2) << endl;
    }
};