//https://leetcode.com/problems/find-pivot-index/
//724. Find Pivot Index
// TC - O(n), SC - O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        int newSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            totalSum -= nums[i];
            if(totalSum == newSum)
                return i;
            newSum += nums[i];
        }

        return -1;
    }
};
