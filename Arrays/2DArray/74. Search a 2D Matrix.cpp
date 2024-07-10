//https://leetcode.com/problems/search-a-2d-matrix/description/
//74. Search a 2D Matrix

//----------Approach-I
// TC - O(log(m*n)), SC - O(1)

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

//----------Approach-I
// TC - O(m*n)), SC - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n-1;

        while(i < m && j >= 0)
        {
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};
