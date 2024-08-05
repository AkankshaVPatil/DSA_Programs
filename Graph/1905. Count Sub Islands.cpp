//https://leetcode.com/problems/count-sub-islands/description/
//1905. Count Sub Islands.cpp
// TC - O(m*n), SC - O(1)
class Solution {
public:
    bool solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n)
    {
        if(i  < 0 || j < 0 || i >= m || j >= n) return true;
        if(grid1[i][j] == 1 && grid2[i][j] == 0)    return true;
        if(grid1[i][j] == 3 && grid2[i][j] == 3)    return true;
        if(grid1[i][j] == 0 && grid2[i][j] == 0)    return true;
        if(grid1[i][j] == 0 && grid2[i][j] == 1)    return false;

        grid1[i][j] = 3;
        grid2[i][j] = 3;

        bool up =  solve(grid1, grid2, i + 1, j, m, n);
        bool down =  solve(grid1, grid2, i - 1, j, m, n);
        bool right =  solve(grid1, grid2, i, j + 1, m, n);
        bool left =  solve(grid1, grid2, i, j - 1, m, n);

        return up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid1[i][j] == 1 && grid2[i][j] == 1)
                {
                    ans += solve(grid1, grid2, i, j, m, n);
                }
            }
        }
        return ans;
    }
};
