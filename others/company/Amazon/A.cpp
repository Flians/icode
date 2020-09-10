/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
**/

#include <vector>

using namespace std;

// triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
int minimumTotal(vector<vector<int>> triangle) {
    if (triangle.empty())
        return 0;
    size_t n = triangle.size();
    vector<int> record(triangle.back().size(), 0);
    for (int r = n-1; r >= 0; --r) {
        for (int i = 0; i <= r; ++i)
            record[i] = min(record[i], record[i+1]) + triangle[r][i];
    }
    return record[0];
}
