#include "icode.h"
#include "../leetcode/1_Two_Sum.h"
#include "../leetcode/2_Add_Two_Numbers.h"
#include "../leetcode/3_Longest_Substring_Without_Repeating_Characters.h"
#include "../leetcode/4_Median_Of_Two_Sorted_Arrays.h"

class Factory
{
public:
    icode *problem(int i)
    {
        switch (i)
        {
        case 1:
            return new L1;
            break;
        case 2:
            return new L2;
            break;
        case 3:
            return new L3;
            break;
        case 4:
            return new L4;
            break;
        default:
            break;
        }
    }
};
