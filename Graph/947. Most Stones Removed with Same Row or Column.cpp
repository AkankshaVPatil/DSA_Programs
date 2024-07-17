//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
//947. Most Stones Removed with Same Row or Column
// TC = O(n * n), SC - O(n)
class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<bool>&visited, int idx)
    {
        visited[idx] = true;

        for(int i = 0; i < stones.size(); i++)
        {
            int r = stones[idx][0];
            int c = stones[idx][1];

            if(visited[i] == false && (stones[i][0] == r || stones[i][1] == c))
                dfs(stones, visited, i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool>visited(n, false);
        int group = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
            {
                dfs(stones, visited, i);
                group++;
            }
        }
        return n - group;
    }
};
