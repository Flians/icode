#include "../base/icode.hpp"
class L827 : public icode
{
public:
	void run() {
        cout << largestIsland({{0,1},{1,0}}) << " 3" << endl; 
        cout << largestIsland({{0,0},{0,0}}) << " 1" << endl; 
        cout << largestIsland({{1,1},{1,1}}) << " 4" << endl; 
        cout << largestIsland({{1}}) << " 1" << endl; 
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[i].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
    int area(vector<vector<int>> grid) {
        int res = 0;
        for (size_t i = 0, row = grid.size(); i < row; ++i) {
            for (size_t j = 0, cow = grid[i].size(); j < cow; ++j) {
                res = max(res, dfs(grid, i,j));
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>&& grid) {
        int res = area(grid);
        bool flag = false, has0 = false;
        for (size_t i = 0, row = grid.size(); i < row; ++i) {
            for (size_t j = 0, cow = grid[i].size(); j < cow; ++j) {
                if (grid[i][j] == 0) {
                    has0 = true;
                    if ((i>0?grid[i-1][j]:0) + (i<row-1?grid[i+1][j]:0) + (j>0?grid[i][j-1]:0) + (j<cow-1?grid[i][j+1]:0) >= 2) {
                        grid[i][j] = 1;
                        int tmp = area(grid);
                        if (tmp > res) {
                            flag = true;
                            res = tmp;
                        }
                        grid[i][j] = 0;
                    }
                }
            }
        }
        return flag || !has0  ? res : res + 1;
    }
    
    
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int vis[501][501];
    bool check(int i,int j,vector<vector<int>>& grid){
        if(i>=0 && (size_t)i<grid.size() && j>=0 && (size_t)j<grid[0].size() && grid[i][j] == 1)
            return true;
        return false;
    }
    int dfs_(vector<vector<int>>& grid,int i,int j,int &val){
        int count = 1;
        vis[i][j] = val;
        for(auto x:dir){
            if(check(i+x.first,j+x.second,grid) && vis[i+x.first][j+x.second] != val)
                count += dfs_(grid,i+x.first,j+x.second,val);
        }
        return count;
    }
    int largestIsland_(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        int val = 1, n = grid.size(), m = grid[0].size();
        int dp[n * m + 2];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    dp[val] = dfs_(grid,i,j,val);
                    val++;
                }
            }  
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    int temp = 1;
                    map<int,int> mp;
                    if(i-1>=0 && vis[i-1][j]){
                        temp += dp[vis[i-1][j]];
                        mp[vis[i-1][j]]++;
                    }
                    if(j-1>=0 && vis[i][j-1] && !mp[vis[i][j-1]]){
                        temp += dp[vis[i][j-1]];
                        mp[vis[i][j-1]]++;
                    }
                    if(i+1<n && vis[i+1][j] && !mp[vis[i+1][j]]){
                        temp += dp[vis[i+1][j]];
                        mp[vis[i+1][j]]++;
                    }
                    if(j+1<m && vis[i][j+1] && !mp[vis[i][j+1]]){
                        temp += dp[vis[i][j+1]];
                        mp[vis[i][j+1]]++;
                    }
                    ans = max(ans,temp);
                }
            }  
        }
        return ans == 0 ? n*m : ans;
    }
};