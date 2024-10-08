//https://leetcode.com/problems/two-sum/description/
//1. Two Sum
// TC - O(n), SC - O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if(!umap.contains(val))
                umap[nums[i]] = i;
            else
                return {umap[val], i};
        }
        return {};
    }
};
