//https://leetcode.com/problems/rotate-image/description/
//48. Rotate Image
// TC- O(n*n), SC- O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(auto &row:matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};



//------ Approach - 2--------------
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)// only chang in line
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(auto &row:matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};
