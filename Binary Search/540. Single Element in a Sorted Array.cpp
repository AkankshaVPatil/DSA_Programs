//https://leetcode.com/problems/single-element-in-a-sorted-array/description/
//540. Single Element in a Sorted Array
//TC - O(longn), SC - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;//0
        int r = nums.size()-1;//6

        while(l < r)// 4< 6
        {
            int mid = (l+r)/2;//5
            bool isEven;
            if((r-mid) % 2 == 1)//6-5
                isEven = false;
            else
                isEven = true;

            if(nums[mid] == nums[mid + 1])
            {
                if(isEven)
                    l = mid + 2;
                else
                    r = mid - 1;
            }
            else 
            {
                if(isEven)
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        return nums[r];
    }
};
