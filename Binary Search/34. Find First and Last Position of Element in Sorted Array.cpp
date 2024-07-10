//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//34. Find First and Last Position of Element in Sorted Array
// TC - O(log(n)), SC - O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int start = -1, end = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(nums[mid] < target)
                lo = mid+1;//1
            else if (nums[mid] > target)
                hi = mid-1;//1
            else
            {
                start = mid;
                hi = mid - 1;
            }
        }
        
        lo = 0;
        hi = nums.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(nums[mid] < target)
                lo = mid+1;
            else if (nums[mid] > target)
                hi = mid-1;
            else
            {
                end = mid;
                lo = mid + 1;
            }
        }

        return {start, end};
    }
};
