//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//84. Largest Rectangle in Histogram
// TC - O(n), SC - O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int poped = st.top();
                st.pop();

                int area = 0;
                if(!st.empty())
                    area = heights[poped] * (i - st.top() - 1);
                else
                    area = heights[poped] * (i - 1);

                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int poped = st.top();
            st.pop();

            int area = 0;
            if(!st.empty())
                area = heights[poped] * (heights.size() - st.top() - 1);
            else
                area = heights[poped] * (heights.size() - 1);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
