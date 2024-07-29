//https://leetcode.com/problems/minimum-path-sum/description/
//64. Minimum Path Sum
// TC - O(M*N), SC - O(m * n)
class Solution {
public:
    int dp[201][201];
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int sum = INT_MAX;
        if(i+1 < m) sum = min(sum, grid[i][j] + solve(grid, i+1, j));  
        if(j+1 < n) sum = min(sum, grid[i][j] + solve(grid, i, j+1));

        return dp[i][j] = sum;  
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0);
    }
};
