//https://leetcode.com/problems/continuous-subarray-sum/description/
//523. Continuous Subarray Sum
// TC - O(n), SC - O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(umap.contains(sum % k))
            {
                if(i - umap[sum % k] >= 2)
                    return true;
            }
            else
                umap[sum % k] = i;
        }
        return false;
    }
};
