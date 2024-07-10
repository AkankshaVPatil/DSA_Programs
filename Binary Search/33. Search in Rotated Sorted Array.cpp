//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//33. Search in Rotated Sorted Array
//TC - O(logn) , SC O(1)

class Solution {
public:
    int findPivote(vector<int>& nums)
    {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }

    int binaryserach(vector<int>& nums, int target,int l, int r)
    {
        while(l <= r)// 4 <= 4
        {
            int mid = (l+r)/2;//4
            if(nums[mid] > target)
                r = mid - 1;//4
            else if(nums[mid] < target)
                l = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int pivoteIndex = findPivote(nums);

        int idx = binaryserach(nums, target, 0, pivoteIndex-1);
        if(idx != -1) return idx;

        idx = binaryserach(nums, target, pivoteIndex, nums.size()-1);
        return idx;
    }
};
