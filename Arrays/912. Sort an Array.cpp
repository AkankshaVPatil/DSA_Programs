//https://leetcode.com/problems/sort-an-array/description/
//912. Sort an Array
//TC - O(n), SC - O(n)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto i:nums)
            freq[i]++;
        
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        int j = 0;
        for(int i = minNum; i <= maxNum; i++)
        {
            if(freq.contains(i))
            {
                while(freq[i]--)
                    nums[j++] = i;
            }
        }
        return nums;
    }
};
