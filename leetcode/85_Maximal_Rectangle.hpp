#include "../base/icode.hpp"
class L85 : public icode
{
public:
    void run()
    {
        std::cout << maximalRectangle({{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}}) << " 6" << std::endl;
    }

    int maximalRectangle(vector<vector<char>> &&matrix)
    {
        if (matrix.empty())
            return 0;
        const int M = matrix.size(), N = matrix[0].size();
        int maxArea = 0;
        int height[N];
        int left[N];
        int right[N];
        fill_n(height, N, 0);
        fill_n(left, N, 0);
        fill_n(right, N, N);
        for (int i = 0; i < M; i++)
        {
            // Get height at row i
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }
            // Get left at row i
            int curLeft = 0;
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = max(left[j], curLeft);
                }
                else
                {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            // Get right at row i
            int curRight = N;
            for (int j = N - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], curRight);
                }
                else
                {
                    right[j] = N;
                    curRight = j;
                }
            }
            // Get max area
            for (int j = 0; j < N; j++)
            {
                int area = (right[j] - left[j]) * height[j];
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};