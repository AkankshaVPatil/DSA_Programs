//https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description
//2134. Minimum Swaps to Group All 1's Together II
// TC - O(n), SC - O(1)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalone = 0;
        for(int i:nums)
        {
            if(i == 1)
                totalone++;
        }

        int currone = 0;
        int j = 0;
        for(; j < totalone; j++)
        {
            if(nums[j] == 1)
                currone++;
        }

        int swaps = totalone - currone;

        int i = 0;
        while(j < 2*n)
        {
            if(nums[i%n] == 1)
                currone--;
        
            if(nums[j%n] == 1)
                currone++;

            swaps = min(swaps, totalone - currone);

            i++;
            j++;
        }

        return swaps;
    }
};
