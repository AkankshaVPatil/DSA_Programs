//https://leetcode.com/problems/basic-calculator/description/
//224. Basic Calculator
// TC - O(n), SC - O(n)

class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        int num = 0, res = 0, sign = 1;

        for(auto ch:s)
        {
            if(isdigit(ch))
                num = num * 10 + (ch - '0');
            else
            {
                res += num * sign;
                num = 0;
                if(ch == '+')
                    sign = 1;
                else if(ch == '-')
                    sign = -1;
                else if(ch == '(')
                {
                    st.push(res);
                    st.push(sign);
                    res = 0;
                    sign = 1;
                }
                else if(ch == ')')
                {
                    res *= st.top();
                    st.pop();
                    res += st.top();
                    st.pop();
                }
            }
        }

        res += num * sign;
        return res;
    }
};
