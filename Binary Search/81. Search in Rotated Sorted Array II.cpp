//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
//81. Search in Rotated Sorted Array II
// TC - O(logn), SC - O(1)
class Solution {
public:
    int findPivote(vector<int>& nums)
    {
        int l = 0, r = nums.size()-1;

        while(l < r)// 1 < 1
        {
            while(l < r && nums[l] == nums[l+1])
                l++;
            while(l < r && nums[r] == nums[r-1])
                r--;
                
            int mid = (l + r)/2;//0

            if(nums[mid] > nums[r])
                l = mid + 1;//1
            else
                r = mid;//1
        }
        return r;
    }

    bool search(vector<int>& nums, int target, int l, int r)
    {
        while(l <= r)//1 < 1
        {
            int mid = (l + r)/2;//1
            if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int pivoteIndex = findPivote(nums);

        if(search(nums, target, 0, pivoteIndex-1))
            return true;
        
        if(search(nums, target, pivoteIndex, nums.size()-1))
            return true;
        return false;
    }
};
