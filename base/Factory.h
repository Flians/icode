#include "icode.h"
#include "../leetcode/1_Two_Sum.h"
#include "../leetcode/2_Add_Two_Numbers.h"
#include "../leetcode/3_Longest_Substring_Without_Repeating_Characters.h"
#include "../leetcode/4_Median_Of_Two_Sorted_Arrays.h"
#include "../leetcode/5_Longest_Palindromic_Substring.h"
#include "../leetcode/8_String_To_Integer.h"
#include "../leetcode/10_Regular_Expression_Matching.h"
#include "../leetcode/11_Container_With_Most_Water.h"
#include "../leetcode/12_Integer_To_Roman.h"
#include "../leetcode/13_Roman_To_Integer.h"
#include "../leetcode/14_Longest_Common_Prefix.h"
#include "../leetcode/15_3Sum.h"
#include "../leetcode/17_Letter_Combinations_of_a_Phone_Number.h"
#include "../leetcode/22_Generate_Parentheses.h"
#include "../leetcode/33_Search_in_Rotated_Sorted_Array.h"
#include "../leetcode/46_Permutations.h"
#include "../leetcode/55_Jump_Game.h"
#include "../leetcode/64_Minimum_Path_Sum.h"
#include "../leetcode/78_Subsets.h"
#include "../leetcode/79_Word_Search.h"
#include "../leetcode/94_Binary_Tree_Inorder_Traversal.h"
#include "../leetcode/103_Binary_Tree_Zigzag_Level_Order_Traversal.h"
#include "../leetcode/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.h"
#include "../leetcode/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.h"
#include "../leetcode/116_Populating_Next_Right_Pointers_in_Each_Node.h"
#include "../leetcode/124_Binary_Tree_Maximum_Path_Sum.h"
#include "../leetcode/146_LRU_Cache.h"
#include "../leetcode/155_Min_Stack.h"
#include "../leetcode/160_Intersection_of_Two_Linked_Lists.h"
#include "../leetcode/163_Missing_Ranges.h"
#include "../leetcode/200_Number_of_Islands.h"
#include "../leetcode/201_Bitwise_AND_of_Numbers_Range.h"
#include "../leetcode/215_Kth_Largest_Element_in_an_Array.h"
#include "../leetcode/221_Maximal_Square.h"
#include "../leetcode/230_Kth_Smallest_Element_in_a_BST.h"
#include "../leetcode/238_Product_of_Array_Except_Self.h"
#include "../leetcode/300_Longest_Increasing_Subsequence.h"
#include "../leetcode/328_Odd_Even_Linked_List.h"
#include "../leetcode/334_Increasing_Triplet_Subsequence.h"
#include "../leetcode/560_Subarray_Sum_Equals_K.h"
#include "../leetcode/678_Valid_Parenthesis_String.h"
#include "../leetcode/679_24_Game.h"
#include "../leetcode/704_Binary_Search.h"
#include "../leetcode/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal.h"
#include "../leetcode/1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.h"
#include "../leetcode/1028_Recover_a_Tree_From_Preorder_Traversal.h"
#include "../leetcode/1046_Last_Stone_Weight.h"
#include "../leetcode/1143_Longest_Common_Subsequence.h"
class Factory
{
public:
	icode *problem(int i)
	{
		switch (i)
		{
		case 1:
			return new L1;
		case 2:
			return new L2;
		case 3:
			return new L3;
		case 4:
			return new L4;
		case 5:
			return new L5;
		case 8:
			return new L8;
		case 10:
			return new L10;
		case 11:
			return new L11;
		case 12:
			return new L12;
		case 13:
			return new L13;
		case 14:
			return new L14;
		case 15:
			return new L15;
		case 17:
			return new L17;
		case 22:
			return new L22;
		case 33:
			return new L33;
		case 46:
			return new L46;
		case 55:
			return new L55;
		case 64:
			return new L64;
		case 78:
			return new L78;
		case 79:
			return new L79;
		case 94:
			return new L94;
		case 103:
			return new L103;
		case 105:
			return new L105;
		case 106:
			return new L106;
		case 116:
			return new L116;
		case 124:
			return new L124;
		case 146:
			return new LRUCache;
		case 155:
			return new MinStack;
		case 160:
			return new L160;
		case 163:
			return new L163;
		case 200:
			return new L200;
		case 201:
			return new L201;
		case 215:
			return new L215;
		case 221:
			return new L221;
		case 230:
			return new L230;
		case 238:
			return new L238;
		case 300:
			return new L300;
		case 328:
			return new L328;
		case 334:
			return new L334;
		case 560:
			return new L560;
		case 678:
			return new L678;
		case 679:
			return new L679;
		case 704:
			return new L704;
		case 889:
			return new L889;
		case 1008:
			return new L1008;
		case 1028:
			return new L1028;
		case 1046:
			return new L1046;
		case 1143:
			return new L1143;
		default:
			cout << "This question is not existed!" << endl;
			exit(-1);
			break;
		}
	}
};