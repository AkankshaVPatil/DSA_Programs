//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description
//1653. Minimum Deletions to Make String Balanced.cpp
//------------Approach-I----------
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

//------------Approach-II----------
// TC - O(n), SC - O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = 0;
        for(auto c:s)
        {
            if(c == 'a')
                a_count++;
        }

        int count = INT_MAX, b_count = 0;
        for(auto c:s)
        {
            if(c == 'a')
                a_count--;
            count = min(count, a_count + b_count);
            if(c == 'b')
                b_count++;
        }
        return count;
    }
};
