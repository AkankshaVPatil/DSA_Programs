//https://leetcode.com/problems/sort-colors/description/
//75. Sort Colors

-----------Approach-I-----------
// TC - O(N), SC - O(N)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int>freq;

        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int i = 0;
        for(auto &itr:freq)
        {
            int cntr = itr.second;
            while(cntr--)
                nums[i++] = itr.first;
        }
    }
};

---------Approach-II---------------
// TC - O(N), SC - O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0;
        int r = nums.size()-1;

        while(mid <= r)
        {
            if(nums[mid] == 2)
            {
                swap(nums[mid], nums[r]);
                r--;
            }
            else if(nums[mid] == 0)
            {
                swap(nums[mid], nums[l]);
                mid++;
                l++;
            }
            else
                mid++;
        }
    }
};
