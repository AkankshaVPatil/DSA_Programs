//https://leetcode.com/problems/climbing-stairs/description/
//70. Climbing Stairs
//-----Approach-I-------
//TC - O(n), SC - O(n)
//Bottom-UP
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return n;

        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//-----Approach-II-------
//TC - O(n), SC - O(n)
//Bottom up Approach
class Solution {
public:
    int dp[46];
    int solve(int n)
    {
        if(n <= 2) return dp[n] = n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1) + solve(n-2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
