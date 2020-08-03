#include "icode.hpp"
#include "../leetcode/1_Two_Sum.hpp"
#include "../leetcode/2_Add_Two_Numbers.hpp"
#include "../leetcode/3_Longest_Substring_Without_Repeating_Characters.hpp"
#include "../leetcode/4_Median_Of_Two_Sorted_Arrays.hpp"
#include "../leetcode/5_Longest_Palindromic_Substring.hpp"
#include "../leetcode/6_ZigZag_Conversion.hpp"
#include "../leetcode/7_Reverse_Integer.hpp"
#include "../leetcode/8_String_To_Integer.hpp"
#include "../leetcode/9_Palindrome_Number.hpp"
#include "../leetcode/10_Regular_Expression_Matching.hpp"
#include "../leetcode/11_Container_With_Most_Water.hpp"
#include "../leetcode/12_Integer_To_Roman.hpp"
#include "../leetcode/13_Roman_To_Integer.hpp"
#include "../leetcode/14_Longest_Common_Prefix.hpp"
#include "../leetcode/15_3Sum.hpp"
#include "../leetcode/16_3Sum_Closest.hpp"
#include "../leetcode/17_Letter_Combinations_of_a_Phone_Number.hpp"
#include "../leetcode/18_4Sum.hpp"
#include "../leetcode/19_Remove_Nth_Node_From_End_of_List.hpp"
#include "../leetcode/20_Valid_Parentheses.hpp"
#include "../leetcode/21_Merge_Two_Sorted_Lists.hpp"
#include "../leetcode/22_Generate_Parentheses.hpp"
#include "../leetcode/23_Merge_k_Sorted_Lists.hpp"
#include "../leetcode/33_Search_in_Rotated_Sorted_Array.hpp"
#include "../leetcode/46_Permutations.hpp"
#include "../leetcode/54_spiral_matrix.hpp"
#include "../leetcode/55_Jump_Game.hpp"
#include "../leetcode/56_merge_intervals.hpp"
#include "../leetcode/57_insert_interval.hpp"
#include "../leetcode/58_length_of_last_word.hpp"
#include "../leetcode/64_Minimum_Path_Sum.hpp"
#include "../leetcode/78_Subsets.hpp"
#include "../leetcode/79_Word_Search.hpp"
#include "../leetcode/94_Binary_Tree_Inorder_Traversal.hpp"
#include "../leetcode/103_Binary_Tree_Zigzag_Level_Order_Traversal.hpp"
#include "../leetcode/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.hpp"
#include "../leetcode/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.hpp"
#include "../leetcode/116_Populating_Next_Right_Pointers_in_Each_Node.hpp"
#include "../leetcode/124_Binary_Tree_Maximum_Path_Sum.hpp"
#include "../leetcode/146_LRU_Cache.hpp"
#include "../leetcode/155_Min_Stack.hpp"
#include "../leetcode/160_Intersection_of_Two_Linked_Lists.hpp"
#include "../leetcode/163_Missing_Ranges.hpp"
#include "../leetcode/169_Majority_Element.hpp"
#include "../leetcode/200_Number_of_Islands.hpp"
#include "../leetcode/201_Bitwise_AND_of_Numbers_Range.hpp"
#include "../leetcode/208_Implement_Trie_(Prefix_Tree).hpp"
#include "../leetcode/215_Kth_Largest_Element_in_an_Array.hpp"
#include "../leetcode/221_Maximal_Square.hpp"
#include "../leetcode/223_Rectangle_Area.hpp"
#include "../leetcode/230_Kth_Smallest_Element_in_a_BST.hpp"
#include "../leetcode/238_Product_of_Array_Except_Self.hpp"
#include "../leetcode/278_First_Bad_Version.hpp"
#include "../leetcode/300_Longest_Increasing_Subsequence.hpp"
#include "../leetcode/328_Odd_Even_Linked_List.hpp"
#include "../leetcode/334_Increasing_Triplet_Subsequence.hpp"
#include "../leetcode/367_Valid_Perfect_Square.hpp"
#include "../leetcode/383_Ransom_Note.hpp"
#include "../leetcode/387_First_Unique_Character_in_a_String.hpp"
#include "../leetcode/402_Remove_K_Digits.hpp"
#include "../leetcode/438_Find_All_Anagrams_in_a_String.hpp"
#include "../leetcode/476_Number_Complement.hpp"
#include "../leetcode/520_Detect_Capital.hpp"
#include "../leetcode/540_Single_Element_in_a_Sorted_Array.hpp"
#include "../leetcode/560_Subarray_Sum_Equals_K.hpp"
#include "../leetcode/567_Permutation_in_String.hpp"
#include "../leetcode/678_Valid_Parenthesis_String.hpp"
#include "../leetcode/679_24_Game.hpp"
#include "../leetcode/704_Binary_Search.hpp"
#include "../leetcode/705_Design_HashSet.hpp"
#include "../leetcode/733_Flood_Fill.hpp"
#include "../leetcode/771_Jewels_and_Stones.hpp"
#include "../leetcode/812_Largest_Triangle_Area.hpp"
#include "../leetcode/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal.hpp"
#include "../leetcode/901_Online_Stock_Span.hpp"
#include "../leetcode/918_Maximum_Sum_Circular_Subarray.hpp"
#include "../leetcode/993_Cousins_in_Binary_Tree.hpp"
#include "../leetcode/997_Find_the_Town_Judge.hpp"
#include "../leetcode/1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.hpp"
#include "../leetcode/1028_Recover_a_Tree_From_Preorder_Traversal.hpp"
#include "../leetcode/1046_Last_Stone_Weight.hpp"
#include "../leetcode/1143_Longest_Common_Subsequence.hpp"
#include "../leetcode/1232_Check_If_It_Is_a_Straight_Line.hpp"
#include "../leetcode/1277_Count_Square_Submatrices_with_All_Ones.hpp"
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
		case 6:
			return new L6;
		case 7:
			return new L7;
		case 8:
			return new L8;
		case 9:
			return new L9;
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
		case 16:
			return new L16;
		case 17:
			return new L17;
		case 18:
			return new L18;
		case 19:
			return new L19;
		case 20:
			return new L20;
		case 21:
			return new L21;
		case 22:
			return new L22;
		case 23:
			return new L23;
		case 33:
			return new L33;
		case 46:
			return new L46;
		case 54:
			return new L54;
		case 55:
			return new L55;
		case 56:
			return new L56;
		case 57:
			return new L57;
		case 58:
			return new L58;
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
		case 169:
			return new L169;
		case 200:
			return new L200;
		case 201:
			return new L201;
		case 208:
			return new Trie;
		case 215:
			return new L215;
		case 221:
			return new L221;
		case 223:
			return new L223;
		case 230:
			return new L230;
		case 238:
			return new L238;
		case 278:
			return new L278;
		case 300:
			return new L300;
		case 328:
			return new L328;
		case 334:
			return new L334;
		case 367:
			return new L367;
		case 383:
			return new L383;
		case 387:
			return new L387;
		case 402:
			return new L402;
		case 438:
			return new L438;
		case 476:
			return new L476;
		case 520:
			return new L520;
		case 540:
			return new L540;
		case 560:
			return new L560;
		case 567:
			return new L567;
		case 678:
			return new L678;
		case 679:
			return new L679;
		case 704:
			return new L704;
		case 705:
			return new MyHashSet;
		case 733:
			return new L733;
		case 771:
			return new L771;
		case 812:
			return new L812;
		case 889:
			return new L889;
		case 901:
			return new StockSpanner;
		case 918:
			return new L918;
		case 993:
			return new L993;
		case 997:
			return new L997;
		case 1008:
			return new L1008;
		case 1028:
			return new L1028;
		case 1046:
			return new L1046;
		case 1143:
			return new L1143;
		case 1232:
			return new L1232;
		case 1277:
			return new L1277;
		default:
			cout << "This question is not existed!" << endl;
			exit(-1);
			break;
		}
	}
};