//https://leetcode.com/problems/lucky-numbers-in-a-matrix/description
//1380. Lucky Numbers in a Matrix
// TC - O(m *n), SC - O(m + n)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rMax = INT_MIN;
        for(int row = 0; row < m; row++)
        {   
            int RowMin = INT_MAX;
            for(int col = 0; col < n; col++)
            {
                RowMin = min(RowMin, matrix[row][col]);
            }
            rMax = max(rMax, RowMin);
        }

        int cMin = INT_MAX;
        for(int col = 0; col < n; col++)
        {   
            int ColMax = INT_MIN;
            for(int row = 0; row < m; row++)
            {
                ColMax = max(ColMax, matrix[row][col]);
            }
            cMin = min(cMin, ColMax);
        }

        if(rMax == cMin)
            return {rMax};
        else
            return {};
    }
};
