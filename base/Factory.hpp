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
#include "../leetcode/35_Search_Insert_Position.hpp"
#include "../leetcode/46_Permutations.hpp"
#include "../leetcode/54_spiral_matrix.hpp"
#include "../leetcode/55_Jump_Game.hpp"
#include "../leetcode/56_merge_intervals.hpp"
#include "../leetcode/57_insert_interval.hpp"
#include "../leetcode/58_length_of_last_word.hpp"
#include "../leetcode/60_Permutation_Sequence.hpp"
#include "../leetcode/64_Minimum_Path_Sum.hpp"
#include "../leetcode/72_Edit_Distance.hpp"
#include "../leetcode/75_Sort_Colors.hpp"
#include "../leetcode/78_Subsets.hpp"
#include "../leetcode/79_Word_Search.hpp"
#include "../leetcode/94_Binary_Tree_Inorder_Traversal.hpp"
#include "../leetcode/103_Binary_Tree_Zigzag_Level_Order_Traversal.hpp"
#include "../leetcode/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.hpp"
#include "../leetcode/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.hpp"
#include "../leetcode/116_Populating_Next_Right_Pointers_in_Each_Node.hpp"
#include "../leetcode/119_Pascal's_Triangle_II.hpp"
#include "../leetcode/123_Best_Time_to_Buy_and_Sell_Stock_III.hpp"
#include "../leetcode/124_Binary_Tree_Maximum_Path_Sum.hpp"
#include "../leetcode/125_Valid_Palindrome.hpp"
#include "../leetcode/130_Surrounded_Regions.hpp"
#include "../leetcode/137_Single_Number_II.hpp"
#include "../leetcode/143_Reorder_List.hpp"
#include "../leetcode/146_LRU_Cache.hpp"
#include "../leetcode/155_Min_Stack.hpp"
#include "../leetcode/160_Intersection_of_Two_Linked_Lists.hpp"
#include "../leetcode/163_Missing_Ranges.hpp"
#include "../leetcode/169_Majority_Element.hpp"
#include "../leetcode/171_Excel_Sheet_Column_Number.hpp"
#include "../leetcode/174_Dungeon_Game.hpp"
#include "../leetcode/200_Number_of_Islands.hpp"
#include "../leetcode/201_Bitwise_AND_of_Numbers_Range.hpp"
#include "../leetcode/207_Course_Schedule.hpp"
#include "../leetcode/208_Implement_Trie_(Prefix_Tree).hpp"
#include "../leetcode/211_Add_and_Search_Word_Data_structure_design.hpp"
#include "../leetcode/215_Kth_Largest_Element_in_an_Array.hpp"
#include "../leetcode/221_Maximal_Square.hpp"
#include "../leetcode/222_Count_Complete_Tree_Nodes.hpp"
#include "../leetcode/223_Rectangle_Area.hpp"
#include "../leetcode/226_Invert_Binary_Tree.hpp"
#include "../leetcode/230_Kth_Smallest_Element_in_a_BST.hpp"
#include "../leetcode/231_Power_of_Two.hpp"
#include "../leetcode/238_Product_of_Array_Except_Self.hpp"
#include "../leetcode/270_Closest_Binary_Search_Tree_Value.hpp"
#include "../leetcode/274_H_Index.hpp"
#include "../leetcode/275_H_Index_II.hpp"
#include "../leetcode/278_First_Bad_Version.hpp"
#include "../leetcode/300_Longest_Increasing_Subsequence.hpp"
#include "../leetcode/328_Odd_Even_Linked_List.hpp"
#include "../leetcode/334_Increasing_Triplet_Subsequence.hpp"
#include "../leetcode/338_Counting_Bits.hpp"
#include "../leetcode/342_Power_of_Four.hpp"
#include "../leetcode/367_Valid_Perfect_Square.hpp"
#include "../leetcode/368_Largest_Divisible_Subset.hpp"
#include "../leetcode/380_Insert_Delete_GetRandom_O(1).hpp"
#include "../leetcode/383_Ransom_Note.hpp"
#include "../leetcode/387_First_Unique_Character_in_a_String.hpp"
#include "../leetcode/392_Is_Subsequence.hpp"
#include "../leetcode/402_Remove_K_Digits.hpp"
#include "../leetcode/404_Sum_of_Left_Leaves.hpp"
#include "../leetcode/406_Queue_Reconstruction_by_Height.hpp"
#include "../leetcode/409_Longest_Palindrome.hpp"
#include "../leetcode/412_Fizz_Buzz.hpp"
#include "../leetcode/435_Non_overlapping_Intervals.hpp"
#include "../leetcode/436_Find_Right_Interval.hpp"
#include "../leetcode/437_Path_Sum_III.hpp"
#include "../leetcode/438_Find_All_Anagrams_in_a_String.hpp"
#include "../leetcode/442_Find_All_Duplicates_in_an_Array.hpp"
#include "../leetcode/450_Delete_Node_in_a_BST.hpp"
#include "../leetcode/451_Sort_Characters_By_Frequency.hpp"
#include "../leetcode/468_Validate_IP_Address.hpp"
#include "../leetcode/470_Implement_Rand10()_Using_Rand7().hpp"
#include "../leetcode/476_Number_Complement.hpp"
#include "../leetcode/497_Random_Point_in_Non_overlapping_Rectangles.hpp"
#include "../leetcode/518_Coin_Change_2.hpp"
#include "../leetcode/520_Detect_Capital.hpp"
#include "../leetcode/528_Random_Pick_with_Weight.hpp"
#include "../leetcode/540_Single_Element_in_a_Sorted_Array.hpp"
#include "../leetcode/560_Subarray_Sum_Equals_K.hpp"
#include "../leetcode/567_Permutation_in_String.hpp"
#include "../leetcode/678_Valid_Parenthesis_String.hpp"
#include "../leetcode/679_24_Game.hpp"
#include "../leetcode/700_Search_in_a_Binary_Search_Tree.hpp"
#include "../leetcode/704_Binary_Search.hpp"
#include "../leetcode/705_Design_HashSet.hpp"
#include "../leetcode/733_Flood_Fill.hpp"
#include "../leetcode/771_Jewels_and_Stones.hpp"
#include "../leetcode/787_Cheapest_Flights_Within_K_Stops.hpp"
#include "../leetcode/812_Largest_Triangle_Area.hpp"
#include "../leetcode/824_Goat_Latin.hpp"
#include "../leetcode/886_Possible_Bipartition.hpp"
#include "../leetcode/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal.hpp"
#include "../leetcode/901_Online_Stock_Span.hpp"
#include "../leetcode/905_Sort_Array_By_Parity.hpp"
#include "../leetcode/918_Maximum_Sum_Circular_Subarray.hpp"
#include "../leetcode/952_Largest_Component_Size_by_Common_Factor.hpp"
#include "../leetcode/967_Numbers_With_Same_Consecutive_Differences.hpp"
#include "../leetcode/969_Pancake_Sorting.hpp"
#include "../leetcode/973_K_Closest_Points_to_Origin.hpp"
#include "../leetcode/983_Minimum_Cost_For_Tickets.hpp"
#include "../leetcode/986_Interval_List_Intersections.hpp"
#include "../leetcode/987_Vertical_Order_Traversal_of_a_Binary_Tree.hpp"
#include "../leetcode/993_Cousins_in_Binary_Tree.hpp"
#include "../leetcode/994_Rotting_Oranges.hpp"
#include "../leetcode/997_Find_the_Town_Judge.hpp"
#include "../leetcode/1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.hpp"
#include "../leetcode/1028_Recover_a_Tree_From_Preorder_Traversal.hpp"
#include "../leetcode/1029_Two_City_Scheduling.hpp"
#include "../leetcode/1032_Stream_of_Characters.hpp"
#include "../leetcode/1035_Uncrossed_Lines.hpp"
#include "../leetcode/1044_Longest_Duplicate_Substring.hpp"
#include "../leetcode/1046_Last_Stone_Weight.hpp"
#include "../leetcode/1103_Distribute_Candies_to_People.hpp"
#include "../leetcode/1143_Longest_Common_Subsequence.hpp"
#include "../leetcode/1232_Check_If_It_Is_a_Straight_Line.hpp"
#include "../leetcode/1277_Count_Square_Submatrices_with_All_Ones.hpp"
#include "../leetcode/1286_Iterator_for_Combination.hpp"
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
		case 35:
			return new L35;
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
		case 60:
			return new L60;
		case 64:
			return new L64;
		case 72:
			return new L72;
		case 75:
			return new L75;
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
		case 119:
			return new L119;
		case 123:
			return new L123;
		case 124:
			return new L124;
		case 125:
			return new L125;
		case 130:
			return new L130;
		case 137:
			return new L137;
		case 143:
			return new L143;
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
		case 171:
			return new L171;
		case 174:
			return new L174;
		case 200:
			return new L200;
		case 201:
			return new L201;
		case 207:
			return new L207;
		case 208:
			return new Trie;
		case 211:
			return new WordDictionary;
		case 215:
			return new L215;
		case 221:
			return new L221;
		case 222:
			return new L222;
		case 223:
			return new L223;
		case 226:
			return new L226;
		case 230:
			return new L230;
		case 231:
			return new L231;
		case 238:
			return new L238;
		case 270:
			return new L270;
		case 274:
			return new L274;
		case 275:
			return new L275;
		case 278:
			return new L278;
		case 300:
			return new L300;
		case 328:
			return new L328;
		case 334:
			return new L334;
		case 338:
			return new L338;
		case 342:
			return new L342;
		case 367:
			return new L367;
		case 368:
			return new L368;
		case 380:
			return new RandomizedSet;
		case 383:
			return new L383;
		case 387:
			return new L387;
		case 392:
			return new L392;
		case 402:
			return new L402;
		case 404:
			return new L404;
		case 406:
			return new L406;
		case 409:
			return new L409;
		case 412:
			return new L412;
		case 435:
			return new L435;
		case 436:
			return new L436;
		case 437:
			return new L437;
		case 438:
			return new L438;
		case 442:
			return new L442;
		case 450:
			return new L450;
		case 451:
			return new L451;
		case 468:
			return new L468;
		case 470:
			return new L470;
		case 476:
			return new L476;
		case 497:
			return new RandPoint;
		case 518:
			return new L518;
		case 520:
			return new L520;
		case 528:
			return new Random_pick;
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
		case 700:
			return new L700;
		case 704:
			return new L704;
		case 705:
			return new MyHashSet;
		case 733:
			return new L733;
		case 771:
			return new L771;
		case 787:
			return new L787;
		case 812:
			return new L812;
		case 824:
			return new L824;
		case 886:
			return new L886;
		case 889:
			return new L889;
		case 901:
			return new StockSpanner;
		case 905:
			return new L905;
		case 918:
			return new L918;
		case 952:
			return new L952;
		case 967:
			return new L967;
		case 969:
			return new L969;
		case 973:
			return new L973;
		case 983:
			return new L983;
		case 986:
			return new L986;
		case 987:
			return new L987;
		case 993:
			return new L993;
		case 994:
			return new L994;
		case 997:
			return new L997;
		case 1008:
			return new L1008;
		case 1028:
			return new L1028;
		case 1029:
			return new L1029;
		case 1032:
			return new StreamChecker;
		case 1035:
			return new L1035;
		case 1044:
			return new L1044;
		case 1046:
			return new L1046;
		case 1103:
			return new L1103;
		case 1143:
			return new L1143;
		case 1232:
			return new L1232;
		case 1277:
			return new L1277;
		case 1286:
			return new CombinationIterator;
		default:
			cout << "This question is not existed!" << endl;
			exit(-1);
			break;
		}
	}
};