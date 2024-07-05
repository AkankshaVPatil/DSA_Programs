//https://leetcode.com/problems/sort-the-matrix-diagonally/
//1329. Sort the Matrix Diagonally
//TC - O(m*nlogn), SC - O(m*n)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>>umap;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                umap[i-j].push_back(mat[i][j]);
            }
        }

        for(auto &it:umap)
        {
            sort(it.second.begin(), it.second.end());
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                ans[i][j] = umap[i-j].back();
                umap[i-j].pop_back();
            }
        }
        return ans;
    }
};
