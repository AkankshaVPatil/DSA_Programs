//https://leetcode.com/problems/3sum-closest/description/
// 16. 3Sum Closest
// TC - O(n),  SC - O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // -4, -1 , 1 , 2
        int closestSum = 1000000;
        for(int i = 0; i < n-2; i++)
        {
            int j = i + 1;
            int k = n-1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - closestSum))
                    closestSum = sum;

                if(sum < target)
                    j++;
                else
                    k--;
            }
        }
        return closestSum;
    }
};
