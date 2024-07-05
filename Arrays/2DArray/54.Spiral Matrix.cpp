//https://leetcode.com/problems/spiral-matrix/description/
//54. Spiral Matrix
// TC - O(m*n), SC- O(m*n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        //dir 0 ==> left to right  // dir 3 ==> right to left
        // dir 1==> top to bottom  // dir 4 ==> bottom to top
        
        int dir = 0;
        vector<int> ans;
        while(top <= bottom && left <= right)//0<3, 0<4
        {
            if(dir == 0)
            {
                for(int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            
            if(dir == 1)
            {
                for(int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

            if(dir == 2)
            {
                for(int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(dir == 3)
            {
                for(int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;
            if(dir == 4)
                dir = 0;
        }

        return ans;
    }
};
