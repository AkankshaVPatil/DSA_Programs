//https://leetcode.com/problems/binary-search/description/
//704. Binary Search
//TC = O(log N), SC - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0; 
        int hi = nums.size()-1;

        while(lo <= hi)
        {
            int mid = lo + ( hi-lo)/2;
            if(nums[mid] < target)
                lo = mid+1;
            else if(nums[mid] > target)
                hi = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
