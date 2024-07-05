//https://leetcode.com/problems/diagonal-traverse/description/
//498. Diagonal Traverse
// TC - O(m * n), SC - O(m * n)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>>map;

        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++)// 
        {
            for(int j = 0; j < n; j++)
            {
                map[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        int flag = true;
        for(auto &itr:map)
        {
            if(flag)
                reverse(itr.second.begin(), itr.second.end());
            
            for(auto &i:itr.second)
                ans.push_back(i);

            flag = !flag;
        }

        return ans;
    }
};
