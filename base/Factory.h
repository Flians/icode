#include "icode.h"
#include "../leetcode/1_Two_Sum.h"
#include "../leetcode/2_Add_Two_Numbers.h"
#include "../leetcode/3_Longest_Substring_Without_Repeating_Characters.h"
#include "../leetcode/4_Median_Of_Two_Sorted_Arrays.h"
#include "../leetcode/5_Longest_Palindromic_Substring.h"
#include "../leetcode/94_Binary_Tree_Inorder_Traversal.h"
#include "../leetcode/103_Binary_Tree_Zigzag_Level_Order_Traversal.h"
#include "../leetcode/160_Intersection_of_Two_Linked_Lists.h"
#include "../leetcode/163_Missing_Ranges.h"

#include "../leetcode/200_Number_of_Islands.h"

#include "../leetcode/328_Odd_Even_Linked_List.h"
#include "../leetcode/334_Increasing_Triplet_Subsequence.h"

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
        case 5:
            return new L5;
            break;
        case 94:
            return new L94;
            break;
        case 103:
            return new L103;
            break;
        case 160:
            return new L160;
            break;
        case 163:
            return new L163;
            break;
        case 200:
            return new L200;
            break;
        case 328:
            return new L328;
            break;
        case 334:
            return new L334;
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
