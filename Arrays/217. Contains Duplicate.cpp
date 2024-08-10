//https://leetcode.com/problems/contains-duplicate/description/
//217. Contains Duplicate
//-----Approach-I-------
//TC - O(nlogn), SC - O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};

//-----Approach-II-------
//TC - O(n), SC - O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(st.contains(nums[i]))
                return true;
            st.insert(nums[i]);
        }
        return false;
    }
};

//-----Approach-III-------
//TC - O(nlogn), SC - O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        if(st.size() < nums.size())
            return true;
        return false;
    }
};
