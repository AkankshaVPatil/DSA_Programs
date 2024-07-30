//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description
//1653. Minimum Deletions to Make String Balanced.cpp
// TC - O(n), SC - O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cntr = 0;
        for(auto c:s)
        {
            if(!st.empty() && st.top() == 'b' && c == 'a')
            {
                cntr++;
                st.pop();
            }
            else
                st.push(c);
        }
        return cntr;
    }
};
