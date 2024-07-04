//https://leetcode.com/problems/container-with-most-water/description/
// 11. Container With Most Water
// TC - O(n), SC- O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = 0, maxarea = INT_MIN;
        
        while(l < r)
        {
            area = min(height[l], height[r]) * (r - l);
            maxarea = max(maxarea, area);

            if(height[l] <= height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};
