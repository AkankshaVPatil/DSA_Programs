//https://leetcode.com/problems/3sum/description/
//15. 3Sum
// TC - O(n*n), SC - O(1)


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());//nlogn

        for(int i = 0; i <= n-3; i++)//n
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            while(j < k) // O(n)
            {
                int sum = nums[i] + nums[j] + nums[k];//-3
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k)
                    {
                        if(nums[j] == nums[j-1]) 
                            j++;
                        else
                            break;
                    }
                }
            }
        }
        return ans;
    }
};
