//https://leetcode.com/problems/contains-duplicate-ii/description/
//219. Contains Duplicate II
// TC - O(n), SC - O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>umap;

        for(int i = 0; i < nums.size(); i++)
        {
            if(!umap.contains(nums[i]))
                umap[nums[i]] = i;
            else
            {
                if(abs(i - umap[nums[i]] <= k))
                    return true;
                umap[nums[i]] = i;
            }
        }
        return false;
    }
};
