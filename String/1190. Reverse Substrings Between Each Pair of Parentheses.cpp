//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description
//1190. Reverse Substrings Between Each Pair of Parentheses

//-----------Approach-I-----------
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

//-----------Approach-II-----------
// TC - O(n), SC - O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>vec(s.size(), -1);
        stack<int>st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                vec[st.top()] = i;
                vec[i] = st.top();
                st.pop();
            }
        }

        int flag = 1;
        string result = "";
        for(int i = 0; i < s.size(); i += flag)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                i = vec[i];
                flag = -flag;
            }
            else
                result.push_back(s[i]);
        }
        return result;
    }
};
