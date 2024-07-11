//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
//1047. Remove All Adjacent Duplicates In String
//TC - O(n), SC - O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch:s)
        {
            if(!st.empty() && st.top() == ch)
            {
                st.pop();
            }
            else
                st.push(ch);
        }

        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
