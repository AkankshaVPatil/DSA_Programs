//https://leetcode.com/problems/maximum-subarray/description/
//53. Maximum Subarray
//TC - O(n), SC - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Sum = nums[0], maxSum = Sum;
        for(int i = 1; i < nums.size(); i++)
        {
            Sum = max(Sum + nums[i], nums[i]);
            maxSum = max(maxSum, Sum);
        }
        return maxSum;
    }
};
