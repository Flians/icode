// http://poj.org/problem?id=2520
#include <iostream>
#include <string>
#include <malloc.h>
#include <map>

std::map<char, int> DNA = {
    {'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}, {'-', 4}};

using namespace std;

void input(string &res, string &ref)
{
    getline(cin, res);
    getline(cin, ref);
}

/**
 * op[0] replace -> 2
 * op[1] delete -> 3
 * op[2] insert -> 3
 */
int edit_distance(string res, string ref, int **dp)
{
    int len_res = res.size(), len_ref = ref.size();
    int i = 0, j = 0, temp = 0;
    for (; i <= len_res; i++)
    {
        for (j = 0; j <= len_ref; j++)
        {
            if (i == 0)
                dp[0][j] = j;
            if (j == 0)
                dp[i][0] = i;
            if (res[i - 1] == ref[j - 1])
            {
                temp = dp[i - 1][j - 1];
            }
            else
            {
                temp = dp[i - 1][j - 1] + 2;
            }
            if (temp < dp[i - 1][j] + 3)
            {
                if (temp < dp[i][j - 1] + 3)
                {
                    dp[i][j] = temp;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 3;
                }
            }
            else
            {
                if (dp[i - 1][j] + 3 < dp[i][j - 1] + 3)
                {
                    dp[i][j] = dp[i - 1][j] + 3;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 3;
                }
            }
        }
    }
    return dp[len_res][len_ref];
}

void get_path(int **dp, int m, int n)
{
    int i=m-1, j=n-1, temp;
    temp = dp[i--][j];
    cout << temp << " ";
    for(; i>=0; i--)
    {
            if(temp == dp[i-1][j-1])
            if (dp[i-1][j-1] + 2 < dp[i - 1][j])
            {
                if (temp < dp[i][j - 1] + 3)
                {
                    dp[i][j] = temp;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 3;
                }
            }
            else
            {
                if (dp[i - 1][j] + 3 < dp[i][j - 1] + 3)
                {
                    dp[i][j] = dp[i - 1][j] + 3;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 3;
                }
            }
    }
}

int main()
{
    string res, ref;
    input(res, ref);
    int **dp, i = 0;
    dp = (int **)malloc((res.size() + 1) * sizeof(int *));
    for (; i < (int)(res.size() + 1); i++)
    {
        dp[i] = (int *)malloc((ref.size() + 1) * sizeof(int));
    }
    cout << "cost: " << edit_distance(res, ref, dp) << endl;
    get_path(dp, res.size() + 1, ref.size() + 1);
    return 0;
}