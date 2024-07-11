//
//1190. Reverse Substrings Between Each Pair of Parentheses
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;

        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(str.length());
            else if(s[i] == ')')
            {
                int l = st.top();
                st.pop();
                reverse(str.begin()+l, str.end());
            }
            else
                str += s[i];
        }
        return str;
    }
};
