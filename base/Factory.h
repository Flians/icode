#include "icode.h"
#include "../leetcode/1_Two_Sum.h"
#include "../leetcode/2_Add_Two_Numbers.h"
#include "../leetcode/3_Longest_Substring_Without_Repeating_Characters.h"
#include "../leetcode/4_Median_Of_Two_Sorted_Arrays.h"

#include "../leetcode/200_Number_of_Islands.h"

#include "../leetcode/678_Valid_Parenthesis_String.h"
#include "../leetcode/679_24_Game.h"

#include "../leetcode/1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.h"

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
        case 200:
            return new L200;
            break;
        case 678:
            return new L678;
            break;
        case 679:
            return new L679;
            break;
        case 1008:
            return new L1008;
            break;
        default:
            cout << "This question is not existed!" << endl;
            exit(-1);
            break;
        }
    }
};
