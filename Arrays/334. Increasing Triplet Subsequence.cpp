//https://leetcode.com/problems/increasing-triplet-subsequence/description/
//334. Increasing Triplet Subsequence
// TC - O(n), SC - O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX, num2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= num1)
                num1 = nums[i];
            else if(nums[i] <= num2)
                num2 = nums[i];
            else //if(nums[i] > num1 && nums[i] > num2)
                return true;
        }
        return false;
    }
};
