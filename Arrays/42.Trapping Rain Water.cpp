//https://leetcode.com/problems/trapping-rain-water/description/
//42. Trapping Rain Water

// ------- Approach 1: using stack
// TC - O(n),  SC - O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int area = 0;
        for(int i = 0; i < height.size(); i++)
        {
            while(!st.empty() && height[i] > height[st.top()])
            {
                int poped = st.top();
                st.pop();
                if(!st.empty())
                {
                    int width = i - st.top() - 1;
                    int h =  min(height[i], height[st.top()]) - height[poped];
                    area += width * h;
                }
            }
            st.push(i);
        }
        return area;
    }
};


// ------- Approach 1: using 2 pointers(l and r)
// TC - O(n),  SC - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lval = height[l], rval = height[r], sum = 0;
        while(l < r)
        {
            if(lval <= rval)
            {
                sum += lval - height[l];// 1 1 
                l++;
                lval = max(lval, height[l]);
            }
            else
            {
                sum+= rval - height[r];
                r--;
                rval = max(rval, height[r]);
            }
        }
        return sum;
    }
};
