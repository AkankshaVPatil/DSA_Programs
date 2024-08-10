//https://leetcode.com/problems/majority-element/description/
//169. Majority Element
// TC - O(n), SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElem = nums[0];
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(majElem == nums[i])
                cnt++;
            else
            {
                cnt--;
                if(cnt == 0)
                {
                    majElem = nums[i];
                    cnt++;
                }
            }
        }
        return majElem;
    }
};
