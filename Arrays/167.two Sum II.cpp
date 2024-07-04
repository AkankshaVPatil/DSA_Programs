//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//167. Two Sum II - Input Array Is Sorted
//TC - O(N), SC - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;

        while(i < j)
        {
            int val = nums[i] + nums[j];
            if(val > target)
                j--;
            else if(val < target)
                i++;
            else
                return {i+1, j+1};
        }
        return {};
    }
};
