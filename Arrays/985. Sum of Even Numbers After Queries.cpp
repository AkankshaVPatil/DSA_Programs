//https://leetcode.com/problems/sum-of-even-numbers-after-queries/
//985. Sum of Even Numbers After Queries
// TC - O(n + m), SC - O(m)

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int totalSumEven = 0;
        for(int i = 0; i < nums.size(); i++) O(N)
        {
            if(nums[i] % 2 == 0)
                totalSumEven += nums[i];
        }

        vector<int> ans;
        for(auto q:queries)// O(M)
        {
            int idx = q[1];//1
            int val = q[0];//-3

            if(nums[idx] % 2 == 0)
                totalSumEven -= nums[idx];
            
            nums[idx] += val;//2
            if(nums[idx] % 2 == 0)
                totalSumEven += nums[idx];

            ans.push_back(totalSumEven);
        }
        return ans;
    }
};
