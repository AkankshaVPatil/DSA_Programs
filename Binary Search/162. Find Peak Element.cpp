//https://leetcode.com/problems/find-peak-element/
//162. Find Peak Element
//---------Approach-1---------
// TC - O(logn), SC - O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] < nums[mid+1])
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};

//---------Approach-II---------
// TC - O(logn), SC - O(logn)
class Solution {
public:
    int binarySearch(vector<int>& nums, int lo, int hi)
    {
        if(lo == hi) return lo;
        int mid = lo + (hi - lo)/2;
        if(nums[mid] < nums[mid+1])
            return binarySearch(nums, mid + 1, hi);

        return binarySearch(nums, lo, mid);
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1);
    }
};
