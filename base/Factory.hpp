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
#include "../leetcode/24_Swap_Nodes_in_Pairs.hpp"
#include "../leetcode/33_Search_in_Rotated_Sorted_Array.hpp"
#include "../leetcode/35_Search_Insert_Position.hpp"
#include "../leetcode/41_First_Missing_Positive.hpp"
#include "../leetcode/46_Permutations.hpp"
#include "../leetcode/54_spiral_matrix.hpp"
#include "../leetcode/55_Jump_Game.hpp"
#include "../leetcode/56_merge_intervals.hpp"
#include "../leetcode/57_insert_interval.hpp"
#include "../leetcode/58_length_of_last_word.hpp"
#include "../leetcode/59_Spiral_Matrix_II.hpp"
#include "../leetcode/60_Permutation_Sequence.hpp"
#include "../leetcode/61_Rotate_List.hpp"
#include "../leetcode/62_Unique_Paths.hpp"
#include "../leetcode/63_Unique_Paths_II.hpp"
#include "../leetcode/64_Minimum_Path_Sum.hpp"
#include "../leetcode/65_Valid_Number.hpp"
#include "../leetcode/66_Plus_One.hpp"
#include "../leetcode/67_Add_Binary.hpp"
#include "../leetcode/69_Sqrt(x).hpp"
#include "../leetcode/71_Simplify_Path.hpp"
#include "../leetcode/72_Edit_Distance.hpp"
#include "../leetcode/75_Sort_Colors.hpp"
#include "../leetcode/78_Subsets.hpp"
#include "../leetcode/79_Word_Search.hpp"
#include "../leetcode/82_Remove_Duplicates_from_Sorted_List_II.hpp"
#include "../leetcode/84_Largest_Rectangle_in_Histogram.hpp"
#include "../leetcode/88_Merge_Sorted_Array.hpp"
#include "../leetcode/91_Decode_Ways.hpp"
#include "../leetcode/94_Binary_Tree_Inorder_Traversal.hpp"
#include "../leetcode/96_Unique_Binary_Search_Trees.hpp"
#include "../leetcode/98_Validate_Binary_Search_Tree.hpp"
#include "../leetcode/103_Binary_Tree_Zigzag_Level_Order_Traversal.hpp"
#include "../leetcode/104_Maximum_Depth_of_Binary_Tree.hpp"
#include "../leetcode/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.hpp"
#include "../leetcode/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.hpp"
#include "../leetcode/107_Binary_Tree_Level_Order_Traversal_II.hpp"
#include "../leetcode/110_Balanced_Binary_Tree.hpp"
#include "../leetcode/111_Minimum_Depth_of_Binary_Tree.hpp"
#include "../leetcode/116_Populating_Next_Right_Pointers_in_Each_Node.hpp"
#include "../leetcode/117_Populating_Next_Right_Pointers_in_Each_Node_II.hpp"
#include "../leetcode/119_Pascal's_Triangle_II.hpp"
#include "../leetcode/121_Best_Time_to_Buy_and_Sell_Stock.hpp"
#include "../leetcode/123_Best_Time_to_Buy_and_Sell_Stock_III.hpp"
#include "../leetcode/124_Binary_Tree_Maximum_Path_Sum.hpp"
#include "../leetcode/125_Valid_Palindrome.hpp"
#include "../leetcode/127_Word_Ladder.hpp"
#include "../leetcode/129_Sum_Root_to_Leaf_Numbers.hpp"
#include "../leetcode/130_Surrounded_Regions.hpp"
#include "../leetcode/131_Palindrome_Partitioning.hpp"
#include "../leetcode/134_Gas_Station.hpp"
#include "../leetcode/137_Single_Number_II.hpp"
#include "../leetcode/139_Word_Break.hpp"
#include "../leetcode/141_Linked_List_Cycle.hpp"
#include "../leetcode/143_Reorder_List.hpp"
#include "../leetcode/146_LRU_Cache.hpp"
#include "../leetcode/152_Maximum_Product_Subarray.hpp"
#include "../leetcode/155_Min_Stack.hpp"
#include "../leetcode/160_Intersection_of_Two_Linked_Lists.hpp"
#include "../leetcode/163_Missing_Ranges.hpp"
#include "../leetcode/165_Compare_Version_Numbers.hpp"
#include "../leetcode/169_Majority_Element.hpp"
#include "../leetcode/171_Excel_Sheet_Column_Number.hpp"
#include "../leetcode/173_Binary_Search_Tree_Iterator.hpp"
#include "../leetcode/174_Dungeon_Game.hpp"
#include "../leetcode/179_Largest_Number.hpp"
#include "../leetcode/198_House_Robber.hpp"
#include "../leetcode/199_Binary_Tree_Right_Side_View.hpp"
#include "../leetcode/200_Number_of_Islands.hpp"
#include "../leetcode/201_Bitwise_AND_of_Numbers_Range.hpp"
#include "../leetcode/207_Course_Schedule.hpp"
#include "../leetcode/208_Implement_Trie_(Prefix_Tree).hpp"
#include "../leetcode/210_Course_Schedule_II.hpp"
#include "../leetcode/211_Add_and_Search_Word_Data_structure_design.hpp"
#include "../leetcode/213_House_Robber_II.hpp"
#include "../leetcode/215_Kth_Largest_Element_in_an_Array.hpp"
#include "../leetcode/216_Combination_Sum_III.hpp"
#include "../leetcode/220_Contains_Duplicate_III.hpp"
#include "../leetcode/221_Maximal_Square.hpp"
#include "../leetcode/222_Count_Complete_Tree_Nodes.hpp"
#include "../leetcode/223_Rectangle_Area.hpp"
#include "../leetcode/226_Invert_Binary_Tree.hpp"
#include "../leetcode/229_Majority_Element_II.hpp"
#include "../leetcode/230_Kth_Smallest_Element_in_a_BST.hpp"
#include "../leetcode/231_Power_of_Two.hpp"
#include "../leetcode/235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.hpp"
#include "../leetcode/236_Lowest_Common_Ancestor_of_a_Binary_Tree.hpp"
#include "../leetcode/238_Product_of_Array_Except_Self.hpp"
#include "../leetcode/240_Search_a_2D_Matrix_II.hpp"
#include "../leetcode/264_Ugly_Number_II.hpp"
#include "../leetcode/270_Closest_Binary_Search_Tree_Value.hpp"
#include "../leetcode/274_H_Index.hpp"
#include "../leetcode/275_H_Index_II.hpp"
#include "../leetcode/278_First_Bad_Version.hpp"
#include "../leetcode/279_Perfect_Squares.hpp"
#include "../leetcode/287_Find_the_Duplicate_Number.hpp"
#include "../leetcode/289_Game_of_Life.hpp"
#include "../leetcode/290_Word_Pattern.hpp"
#include "../leetcode/299_Bulls_and_Cows.hpp"
#include "../leetcode/300_Longest_Increasing_Subsequence.hpp"
#include "../leetcode/312_Burst_Balloons.hpp"
#include "../leetcode/322_Coin_Change.hpp"
#include "../leetcode/328_Odd_Even_Linked_List.hpp"
#include "../leetcode/332_Reconstruct_Itinerary.hpp"
#include "../leetcode/334_Increasing_Triplet_Subsequence.hpp"
#include "../leetcode/337_House_Robber_III.hpp"
#include "../leetcode/338_Counting_Bits.hpp"
#include "../leetcode/342_Power_of_Four.hpp"
#include "../leetcode/354_Russian_Doll_Envelopes.hpp"
#include "../leetcode/367_Valid_Perfect_Square.hpp"
#include "../leetcode/368_Largest_Divisible_Subset.hpp"
#include "../leetcode/376_Wiggle_Subsequence.hpp"
#include "../leetcode/380_Insert_Delete_GetRandom_O.hpp"
#include "../leetcode/382_Linked_List_Random_Node.hpp"
#include "../leetcode/383_Ransom_Note.hpp"
#include "../leetcode/387_First_Unique_Character_in_a_String.hpp"
#include "../leetcode/389_Find_the_Difference.hpp"
#include "../leetcode/392_Is_Subsequence.hpp"
#include "../leetcode/399_Evaluate_Division.hpp"
#include "../leetcode/402_Remove_K_Digits.hpp"
#include "../leetcode/404_Sum_of_Left_Leaves.hpp"
#include "../leetcode/406_Queue_Reconstruction_by_Height.hpp"
#include "../leetcode/409_Longest_Palindrome.hpp"
#include "../leetcode/412_Fizz_Buzz.hpp"
#include "../leetcode/417_Pacific_Atlantic_Water_Flow.hpp"
#include "../leetcode/421_Maximum_XOR_of_Two_Numbers_in_an_Array.hpp"
#include "../leetcode/423_Reconstruct_Original_Digits_from_English.hpp"
#include "../leetcode/435_Non_overlapping_Intervals.hpp"
#include "../leetcode/436_Find_Right_Interval.hpp"
#include "../leetcode/437_Path_Sum_III.hpp"
#include "../leetcode/438_Find_All_Anagrams_in_a_String.hpp"
#include "../leetcode/441_Arranging_Coins.hpp"
#include "../leetcode/442_Find_All_Duplicates_in_an_Array.hpp"
#include "../leetcode/450_Delete_Node_in_a_BST.hpp"
#include "../leetcode/451_Sort_Characters_By_Frequency.hpp"
#include "../leetcode/454_4Sum_II.hpp"
#include "../leetcode/456_132_Pattern.hpp"
#include "../leetcode/459_Repeated_Substring_Pattern.hpp"
#include "../leetcode/461_Hamming_Distance.hpp"
#include "../leetcode/463_Island_Perimeter.hpp"
#include "../leetcode/468_Validate_IP_Address.hpp"
#include "../leetcode/470_Implement_Rand10()_Using_Rand7().hpp"
#include "../leetcode/476_Number_Complement.hpp"
#include "../leetcode/478_Generate_Random_Point_in_a_Circle.hpp"
#include "../leetcode/495_Teemo_Attacking.hpp"
#include "../leetcode/497_Random_Point_in_Non_overlapping_Rectangles.hpp"
#include "../leetcode/498_Diagonal_Traverse.hpp"
#include "../leetcode/518_Coin_Change_2.hpp"
#include "../leetcode/520_Detect_Capital.hpp"
#include "../leetcode/526_Beautiful_Arrangement.hpp"
#include "../leetcode/528_Random_Pick_with_Weight.hpp"
#include "../leetcode/535_Encode_and_Decode_TinyURL.hpp"
#include "../leetcode/540_Single_Element_in_a_Sorted_Array.hpp"
#include "../leetcode/556_Next_Greater_Element_III.hpp"
#include "../leetcode/560_Subarray_Sum_Equals_K.hpp"
#include "../leetcode/567_Permutation_in_String.hpp"
#include "../leetcode/572_Subtree_of_Another_Tree.hpp"
#include "../leetcode/575_Distribute_Candies.hpp"
#include "../leetcode/594_Longest_Harmonious_Subsequence.hpp"
#include "../leetcode/605_Can_Place_Flowers.hpp"
#include "../leetcode/623_Add_One_Row_to_Tree.hpp"
#include "../leetcode/637_Average_of_Levels_in_Binary_Tree.hpp"
#include "../leetcode/639_Decode_Ways_II.hpp"
#include "../leetcode/645_Set_Mismatch.hpp"
#include "../leetcode/647_Palindromic_Substrings.hpp"
#include "../leetcode/678_Valid_Parenthesis_String.hpp"
#include "../leetcode/679_24_Game.hpp"
#include "../leetcode/695_Max_Area_of_Island.hpp"
#include "../leetcode/700_Search_in_a_Binary_Search_Tree.hpp"
#include "../leetcode/704_Binary_Search.hpp"
#include "../leetcode/705_Design_HashSet.hpp"
#include "../leetcode/706_Design_HashMap.hpp"
#include "../leetcode/713_Subarray_Product_Less_Than_K.hpp"
#include "../leetcode/714_Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee.hpp"
#include "../leetcode/733_Flood_Fill.hpp"
#include "../leetcode/754_Reach_a_Number.hpp"
#include "../leetcode/763_Partition_Labels.hpp"
#include "../leetcode/771_Jewels_and_Stones.hpp"
#include "../leetcode/785_Is_Graph_Bipartite.hpp"
#include "../leetcode/787_Cheapest_Flights_Within_K_Stops.hpp"
#include "../leetcode/797_All_Paths_From_Source_to_Target.hpp"
#include "../leetcode/812_Largest_Triangle_Area.hpp"
#include "../leetcode/821_Shortest_Distance_to_a_Character.hpp"
#include "../leetcode/823_Binary_Trees_With_Factors.hpp"
#include "../leetcode/824_Goat_Latin.hpp"
#include "../leetcode/827_Making_A_Large_Island.hpp"
#include "../leetcode/835_Image_Overlap.hpp"
#include "../leetcode/836_Rectangle_Overlap.hpp"
#include "../leetcode/841_Keys_and_Rooms.hpp"
#include "../leetcode/856_Score_of_Parentheses.hpp"
#include "../leetcode/869_Reordered_Power_of_2.hpp"
#include "../leetcode/870_Advantage_Shuffle.hpp"
#include "../leetcode/877_Stone_Game.hpp"
#include "../leetcode/880_Decoded_String_at_Index.hpp"
#include "../leetcode/881_Boats_to_Save_People.hpp"
#include "../leetcode/886_Possible_Bipartition.hpp"
#include "../leetcode/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal.hpp"
#include "../leetcode/895_Maximum_Frequency_Stack.hpp"
#include "../leetcode/897_Increasing_Order_Search_Tree.hpp"
#include "../leetcode/901_Online_Stock_Span.hpp"
#include "../leetcode/905_Sort_Array_By_Parity.hpp"
#include "../leetcode/910_Smallest_Range_II.hpp"
#include "../leetcode/916_Word_Subsets.hpp"
#include "../leetcode/918_Maximum_Sum_Circular_Subarray.hpp"
#include "../leetcode/923_3Sum_With_Multiplicity.hpp"
#include "../leetcode/948_Bag_of_Tokens.hpp"
#include "../leetcode/949_Largest_Time_for_Given_Digits.hpp"
#include "../leetcode/952_Largest_Component_Size_by_Common_Factor.hpp"
#include "../leetcode/957_Prison_Cells_After_N_Days.hpp"
#include "../leetcode/966_Vowel_Spellchecker.hpp"
#include "../leetcode/967_Numbers_With_Same_Consecutive_Differences.hpp"
#include "../leetcode/969_Pancake_Sorting.hpp"
#include "../leetcode/971_Flip_Binary_Tree_To_Match_Preorder_Traversal.hpp"
#include "../leetcode/973_K_Closest_Points_to_Origin.hpp"
#include "../leetcode/977_Squares_of_a_Sorted_Array.hpp"
#include "../leetcode/980_Unique_Paths_III.hpp"
#include "../leetcode/983_Minimum_Cost_For_Tickets.hpp"
#include "../leetcode/986_Interval_List_Intersections.hpp"
#include "../leetcode/987_Vertical_Order_Traversal_of_a_Binary_Tree.hpp"
#include "../leetcode/991_Broken_Calculator.hpp"
#include "../leetcode/993_Cousins_in_Binary_Tree.hpp"
#include "../leetcode/994_Rotting_Oranges.hpp"
#include "../leetcode/997_Find_the_Town_Judge.hpp"
#include "../leetcode/1008_Construct_Binary_Search_Tree_from_Preorder_Traversal.hpp"
#include "../leetcode/1010_Pairs_of_Songs_With_Total_Durations_Divisible_by_60.hpp"
#include "../leetcode/1022_Sum_of_Root_To_Leaf_Binary_Numbers.hpp"
#include "../leetcode/1028_Recover_a_Tree_From_Preorder_Traversal.hpp"
#include "../leetcode/1029_Two_City_Scheduling.hpp"
#include "../leetcode/1032_Stream_of_Characters.hpp"
#include "../leetcode/1035_Uncrossed_Lines.hpp"
#include "../leetcode/1041_Robot_Bounded_In_Circle.hpp"
#include "../leetcode/1044_Longest_Duplicate_Substring.hpp"
#include "../leetcode/1046_Last_Stone_Weight.hpp"
#include "../leetcode/1091_Shortest_Path_in_Binary_Matrix.hpp"
#include "../leetcode/1094_Car_Pooling.hpp"
#include "../leetcode/1103_Distribute_Candies_to_People.hpp"
#include "../leetcode/1143_Longest_Common_Subsequence.hpp"
#include "../leetcode/1191_K_Concatenation_Maximum_Sum.hpp"
#include "../leetcode/1232_Check_If_It_Is_a_Straight_Line.hpp"
#include "../leetcode/1249_Minimum_Remove_to_Make_Valid_Parentheses.hpp"
#include "../leetcode/1254_Number_of_Closed_Islands.hpp"
#include "../leetcode/1277_Count_Square_Submatrices_with_All_Ones.hpp"
#include "../leetcode/1286_Iterator_for_Combination.hpp"
#include "../leetcode/1291_Sequential_Digits.hpp"
#include "../leetcode/1305_All_Elements_in_Two_Binary_Search_Trees.hpp"
#include "../leetcode/1306_Jump_Game_III.hpp"
#include "../leetcode/1332_Remove_Palindromic_Subsequences.hpp"
#include "../leetcode/1337_The_K_Weakest_Rows_in_a_Matrix.hpp"
#include "../leetcode/1345_Jump_Game_IV.hpp"
#include "../leetcode/1379_Find_a_Corresponding_Node_of_a_Binary_Tree_in_a_Clone_of_That_Tree.hpp"
#include "../leetcode/1382_Balance_a_Binary_Search_Tree.hpp"
#include "../leetcode/1396_Design_Underground_System.hpp"
#include "../leetcode/1401_Circle_and_Rectangle_Overlapping.hpp"
#include "../leetcode/1437_Check_If_All_1's_Are_at_Least_Length_K_Places_Away.hpp"
#include "../leetcode/1457_Pseudo_Palindromic_Paths_in_a_Binary_Tree.hpp"
#include "../leetcode/1461_Check_If_a_String_Contains_All_Binary_Codes_of_Size_K.hpp"
#include "../leetcode/1463_Cherry_Pickup_II.hpp"
#include "../leetcode/1492_The_kth_Factor_of_n.hpp"
#include "../leetcode/1510_Stone_Game_IV.hpp"
#include "../leetcode/1539_Kth_Missing_Positive_Number.hpp"
#include "../leetcode/1631_Path_With_Minimum_Effort.hpp"
#include "../leetcode/1640_Check_Array_Formation_Through_Concatenation.hpp"
#include "../leetcode/1641_Count_Sorted_Vowel_Strings.hpp"
#include "../leetcode/1646_Get_Maximum_in_Generated_Array.hpp"
#include "../leetcode/1658_Minimum_Operations_to_Reduce_X_to_Zero.hpp"
#include "../leetcode/1662_Check_If_Two_String_Arrays_are_Equivalent.hpp"
#include "../leetcode/1663_Smallest_String_With_A_Given_Numeric_Value.hpp"
#include "../leetcode/1673_Find_the_Most_Competitive_Subsequence.hpp"
#include "../leetcode/1679_Max_Number_of_K_Sum_Pairs.hpp"
#include "../leetcode/1680_Concatenation_of_Consecutive_Binary_Numbers.hpp"
#include "../leetcode/1696_Jump_Game_VI.hpp"
#include "../leetcode/1721_Swapping_Nodes_in_a_Linked_List.hpp"
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
		case 24:
			return new L24;
		case 33:
			return new L33;
		case 35:
			return new L35;
		case 41:
			return new L41;
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
		case 59:
			return new L59;
		case 60:
			return new L60;
		case 61:
			return new L61;
		case 62:
			return new L62;
		case 63:
			return new L63;
		case 64:
			return new L64;
		case 65:
			return new L65;
		case 66:
			return new L66;
		case 67:
			return new L67;
		case 69:
			return new L69;
		case 71:
			return new L71;
		case 72:
			return new L72;
		case 75:
			return new L75;
		case 78:
			return new L78;
		case 79:
			return new L79;
		case 82:
			return new L82;
		case 84:
			return new L84;
		case 88:
			return new L88;
		case 91:
			return new L91;
		case 94:
			return new L94;
		case 96:
			return new L96;
		case 98:
			return new L98;
		case 103:
			return new L103;
		case 104:
			return new L104;
		case 105:
			return new L105;
		case 106:
			return new L106;
		case 107:
			return new L107;
		case 110:
			return new L110;
		case 111:
			return new L111;
		case 116:
			return new L116;
		case 117:
			return new L117;
		case 119:
			return new L119;
		case 121:
			return new L121;
		case 123:
			return new L123;
		case 124:
			return new L124;
		case 125:
			return new L125;
		case 127:
			return new L127;
		case 129:
			return new L129;
		case 130:
			return new L130;
		case 131:
			return new L131;
		case 134:
			return new L134;
		case 137:
			return new L137;
		case 139:
			return new L139;
		case 141:
			return new L141;
		case 143:
			return new L143;
		case 146:
			return new LRUCache;
		case 152:
			return new L152;
		case 155:
			return new MinStack;
		case 160:
			return new L160;
		case 163:
			return new L163;
		case 165:
			return new L165;
		case 169:
			return new L169;
		case 171:
			return new L171;
		case 173:
			return new BSTIterator;
		case 174:
			return new L174;
		case 179:
			return new L179;
		case 198:
			return new L198;
		case 199:
			return new L199;
		case 200:
			return new L200;
		case 201:
			return new L201;
		case 207:
			return new L207;
		case 208:
			return new Trie;
		case 210:
			return new L210;
		case 211:
			return new WordDictionary;
		case 213:
			return new L213;
		case 215:
			return new L215;
		case 216:
			return new L216;
		case 220:
			return new L220;
		case 221:
			return new L221;
		case 222:
			return new L222;
		case 223:
			return new L223;
		case 226:
			return new L226;
		case 229:
			return new L229;
		case 230:
			return new L230;
		case 231:
			return new L231;
		case 235:
			return new L235;
		case 236:
			return new L236;
		case 238:
			return new L238;
		case 240:
			return new L240;
		case 264:
			return new L264;
		case 270:
			return new L270;
		case 274:
			return new L274;
		case 275:
			return new L275;
		case 278:
			return new L278;
		case 279:
			return new L279;
		case 287:
			return new L287;
		case 289:
			return new L289;
		case 290:
			return new L290;
		case 299:
			return new L299;
		case 300:
			return new L300;
		case 312:
			return new L312;
		case 322:
			return new L322;
		case 328:
			return new L328;
		case 332:
			return new L332;
		case 334:
			return new L334;
		case 337:
			return new L337;
		case 338:
			return new L338;
		case 342:
			return new L342;
		case 354:
			return new L354;
		case 367:
			return new L367;
		case 368:
			return new L368;
		case 376:
			return new L376;
		case 380:
			return new RandomizedSet;
		case 382:
			return new L382;
		case 383:
			return new L383;
		case 387:
			return new L387;
		case 389:
			return new L389;
		case 392:
			return new L392;
		case 399:
			return new L399;
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
		case 417:
			return new L417;
		case 421:
			return new L421;
		case 423:
			return new L423;
		case 435:
			return new L435;
		case 436:
			return new L436;
		case 437:
			return new L437;
		case 438:
			return new L438;
		case 441:
			return new L441;
		case 442:
			return new L442;
		case 450:
			return new L450;
		case 451:
			return new L451;
		case 454:
			return new L454;
		case 456:
			return new L456;
		case 459:
			return new L459;
		case 461:
			return new L461;
		case 463:
			return new L463;
		case 468:
			return new L468;
		case 470:
			return new L470;
		case 476:
			return new L476;
		case 478:
			return new L478;
		case 495:
			return new L495;
		case 497:
			return new RandPoint;
		case 498:
			return new L498;
		case 518:
			return new L518;
		case 520:
			return new L520;
		case 526:
			return new L526;
		case 528:
			return new Random_pick;
		case 535:
			return new L535;
		case 540:
			return new L540;
		case 556:
			return new L556;
		case 560:
			return new L560;
		case 567:
			return new L567;
		case 572:
			return new L572;
		case 575:
			return new L575;
		case 594:
			return new L594;
		case 605:
			return new L605;
		case 623:
			return new L623;
		case 637:
			return new L637;
		case 639:
			return new L639;
		case 645:
			return new L645;
		case 647:
			return new L647;
		case 678:
			return new L678;
		case 679:
			return new L679;
		case 695:
			return new L695;
		case 700:
			return new L700;
		case 704:
			return new L704;
		case 705:
			return new MyHashSet;
		case 706:
			return new MyHashMap;
		case 713:
			return new L713;
		case 714:
			return new L714;
		case 733:
			return new L733;
		case 754:
			return new L754;
		case 763:
			return new L763;
		case 771:
			return new L771;
		case 785:
			return new L785;
		case 787:
			return new L787;
		case 797:
			return new L797;
		case 812:
			return new L812;
		case 821:
			return new L821;
		case 823:
			return new L823;
		case 824:
			return new L824;
		case 827:
			return new L827;
		case 835:
			return new L835;
		case 836:
			return new L836;
		case 841:
			return new L841;
		case 856:
			return new L856;
		case 869:
			return new L869;
		case 870:
			return new L870;
		case 877:
			return new L877;
		case 880:
			return new L880;
		case 881:
			return new L881;
		case 886:
			return new L886;
		case 889:
			return new L889;
		case 895:
			return new FreqStack;
		case 897:
			return new L897;
		case 901:
			return new StockSpanner;
		case 905:
			return new L905;
		case 910:
			return new L910;
		case 916:
			return new L916;
		case 918:
			return new L918;
		case 923:
			return new L923;
		case 948:
			return new L948;
		case 949:
			return new L949;
		case 952:
			return new L952;
		case 957:
			return new L957;
		case 966:
			return new L966;
		case 967:
			return new L967;
		case 969:
			return new L969;
		case 971:
			return new L971;
		case 973:
			return new L973;
		case 977:
			return new L977;
		case 980:
			return new L980;
		case 983:
			return new L983;
		case 986:
			return new L986;
		case 987:
			return new L987;
		case 991:
			return new L991;
		case 993:
			return new L993;
		case 994:
			return new L994;
		case 997:
			return new L997;
		case 1008:
			return new L1008;
		case 1010:
			return new L1010;
		case 1022:
			return new L1022;
		case 1028:
			return new L1028;
		case 1029:
			return new L1029;
		case 1032:
			return new StreamChecker;
		case 1035:
			return new L1035;
		case 1041:
			return new L1041;
		case 1044:
			return new L1044;
		case 1046:
			return new L1046;
		case 1091:
			return new L1091;
		case 1094:
			return new L1094;
		case 1103:
			return new L1103;
		case 1143:
			return new L1143;
		case 1191:
			return new L1191;
		case 1232:
			return new L1232;
		case 1249:
			return new L1249;
		case 1254:
			return new L1254;
		case 1277:
			return new L1277;
		case 1286:
			return new CombinationIterator;
		case 1291:
			return new L1291;
		case 1305:
			return new L1305;
		case 1306:
			return new L1306;
		case 1332:
			return new L1332;
		case 1337:
			return new L1337;
		case 1345:
			return new L1345;
		case 1379:
			return new L1379;
		case 1382:
			return new L1382;
		case 1396:
			return new UndergroundSystem;
		case 1401:
			return new L1401;
		case 1437:
			return new L1437;
		case 1457:
			return new L1457;
		case 1461:
			return new L1461;
		case 1463:
			return new L1463;
		case 1492:
			return new L1492;
		case 1510:
			return new L1510;
		case 1539:
			return new L1539;
		case 1631:
			return new L1631;
		case 1640:
			return new L1640;
		case 1641:
			return new L1641;
		case 1646:
			return new L1646;
		case 1658:
			return new L1658;
		case 1662:
			return new L1662;
		case 1663:
			return new L1663;
		case 1673:
			return new L1673;
		case 1679:
			return new L1679;
		case 1680:
			return new L1680;
		case 1696:
			return new L1696;
		case 1721:
			return new L1721;
		default:
			cout << "This question is not existed!" << endl;
			exit(-1);
			break;
		}
	}
};