//https://leetcode.com/problems/valid-parentheses/description/
//20. Valid Parentheses
// TC - O(n), SC - O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(auto ch:s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                {
                    if((st.top() == '(' && ch == ')')
                        || (st.top() == '[' && ch == ']')
                        || (st.top() == '{' && ch == '}'))
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};
