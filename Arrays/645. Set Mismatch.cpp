//https://leetcode.com/problems/set-mismatch/description/
//645. Set Mismatch
//TC - O(n), SC - O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        for(int i = 0; i < n; i++)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                ans[0] = abs(nums[i]);
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
                ans[1] = i+1;
        }

        return ans;
    }
};
