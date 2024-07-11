//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description
//1190. Reverse Substrings Between Each Pair of Parentheses
// TC - O(n), SC - O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;

        for(auto c:s)
        {
            if(c == ')')
            {
                string str = "";
                while(!st.empty() && st.top() != '(')
                {
                    str += st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
                       
                for(auto ch:str)
                    st.push(ch);
            }
            else
            {
                st.push(c);
            }
        }
        string str = "";
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
