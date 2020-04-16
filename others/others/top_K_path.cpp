/*
http://theory.ict.ac.cn/grad_oj/problem/29
Description
A robot is located at the top-left corner of a m×nm×n grid. The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. There is a non-negative integer in each small grid which means the score that the robot get when it passes this grid. Now you need to calculate the top kk total scores when the robot reach the destination.
Note: The top k total scores may contain same total score got from different paths.

Input
The first line of input are m and n,which denote the size of the grid. The second line of input is the kk. The next m lines are the score matrix. (1≤m,n,k≤1001≤m,n,k≤100,and 0≤score≤1000≤score≤100)

Output
There is only one line in the Output,which is a descending sequence consist of the top k total scores.

Sample1
Input
3 3
2
3 2 5
3 2 2
4 2 1
Output
13 13
Sample2
Input
4 3
3
7 1 5
4 6 2
4 2 1
5 7 3
Output
30 29 27
*/
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <list>
#include <cmath>

// get the top k socre for each point, default 0.
void path_topk(int **grid, int m, int n, int k, int ***dp)
{
    int l = 0, t = 0, cx = 0, cy = 0;
    for (; cx < m; cx++)
    {
        for (cy = 0; cy < n; cy++)
        {
            if (cx == 0 && cy == 0)
            {
                dp[cx][cy][0] = grid[cx][cy];
            }
            else if (cx == 0 && cy != 0)
            {
                dp[cx][cy][0] = dp[cx][cy - 1][0] + grid[cx][cy];
            }
            else if (cx != 0 && cy == 0)
            {
                dp[cx][cy][0] = dp[cx - 1][cy][0] + grid[cx][cy];
            }
            else
            {
                l = 0, t = 0;
                while (l + t < k)
                {
                    if (dp[cx][cy - 1][t] > dp[cx - 1][cy][l])
                    {
                        dp[cx][cy][l + t] = dp[cx][cy - 1][t++] + grid[cx][cy];
                    }
                    else if(dp[cx - 1][cy][l] != -1)
                    {
                        dp[cx][cy][l + t] = dp[cx - 1][cy][l++] + grid[cx][cy];
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
}

// get the maximum of the score.
int path_score(int **grid, int cx, int cy, int m, int n, int **maxS)
{
    int temp = 0;
    if (m == cx && n == cy)
    {
        temp = grid[cx][cy];
    }
    else if (m == cx && n != cy)
    {
        temp = path_score(grid, cx, cy + 1, m, n, maxS) + grid[cx][cy];
    }
    else if (m != cx && n == cy)
    {
        temp = path_score(grid, cx + 1, cy, m, n, maxS) + grid[cx][cy];
    }
    else
    {
        temp = std::max(path_score(grid, cx + 1, cy, m, n, maxS) + grid[cx][cy],
                        path_score(grid, cx, cy + 1, m, n, maxS) + grid[cx][cy]);
    }
    maxS[cx][cy] = std::max(temp, maxS[cx][cy]);
    return maxS[cx][cy];
}

// get the top K maximum score, time overlimit.
void path(int **grid, int m, int n, int score, std::list<int> *topk, int k)
{
    if (m == 0 && n == 0)
    {
        int temp = score + grid[m][n];
        if (topk->size() == (unsigned)k && topk->front() > temp)
            return;
        else
        {
            std::list<int>::iterator node = std::lower_bound(topk->begin(), topk->end(), temp);
            topk->insert(node, temp);
            while (topk->size() > (unsigned)k)
                topk->pop_front();
        }
    }
    else if (m == 0 && n != 0)
        path(grid, m, n - 1, score + grid[m][n], topk, k);
    else if (m != 0 && n == 0)
        path(grid, m - 1, n, score + grid[m][n], topk, k);
    else
    {
        path(grid, m - 1, n, score + grid[m][n], topk, k);
        path(grid, m, n - 1, score + grid[m][n], topk, k);
    }
}

int main(int argc, char const *argv[])
{
    int m, n, k, i = 0, j = 0, l = 0;
    scanf("%d %d %d", &m, &n, &k);
    // record m*n matrix.
    int **grid;
    // record the max score of each point, default 0.
    int **maxS;
    // record the top k score 0f each point, default 0.
    int ***dp;
    grid = (int **)malloc(m * sizeof(int *));
    maxS = (int **)malloc(m * sizeof(int *));
    dp = (int ***)malloc(m * sizeof(int *));
    for (; i < m; i++)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
        maxS[i] = (int *)malloc(n * sizeof(int));
        dp[i] = (int **)malloc(n * sizeof(int *));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
            maxS[i][j] = 0;
            dp[i][j] = (int *)malloc(k * sizeof(int));
            for (l = 0; l < k; l++)
            {
                dp[i][j][l] = -1;
            }
        }
    }
    // record the score of top k path, default 0.
    std::list<int> *topk = new std::list<int>(k, 0);
    // find all pathed from the starting point to the ending point, and get the top k path.
    path(grid, m - 1, n - 1, 0, topk, k);

    printf("%d", topk->back());
    topk->pop_back();
    l=k;
    while (--l)
    {
        printf(" %d", topk->back());
        topk->pop_back();
    }
    printf("\n");

    // get the maximum of the score.
    printf("%d\n", path_score(grid, 0, 0, m - 1, n - 1, maxS));

    // find the top k score for each point.
    path_topk(grid, m, n, k, dp);
    printf("%d", dp[m-1][n-1][0]);
    for(l=1; l < k; l++)
        printf(" %d", dp[m-1][n-1][l]==-1?0:dp[m-1][n-1][l]);
    printf("\n");

    for (i = 0; i < m; i++)
    {
        free(*(grid + i));
        free(*(maxS + i));
        for (j = 0; j < n; j++)
        {
            free((dp[i][j]));
        }
        free(dp[i]);
    }
    free(grid);
    free(maxS);
    free(dp);
    delete topk;
    return 0;
}

/*
3 3
2
3 2 5
3 2 2
4 2 1

13 13

*******

4 3
3
7 1 5
4 6 2
4 2 1
5 7 3

30 29 27

*******

2 2
4
1 2
3 4

8 7 0 0
*/
