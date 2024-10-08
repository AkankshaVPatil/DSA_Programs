//https://leetcode.com/problems/search-a-2d-matrix/description/
//74. Search a 2D Matrix
// TC - O(log(m*n)), SC - O(N)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m * n - 1;

        while(l <= r)// 1 < 1
        {
            int mid = (l + r)/2;//1

            if(matrix[mid/n][mid%n] > target)
                r = mid - 1;
            else if(matrix[mid/n][mid%n] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};
