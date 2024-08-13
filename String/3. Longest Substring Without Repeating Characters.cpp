//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//3. Longest Substring Without Repeating Characters
//-------------Approach-I----------------
//TC - O(n), SC - O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        string str = "";
        int len = 0, maxlen = INT_MIN;
        for(int i = 0; i < s.size(); i++)
        {
            if(str.find(s[i]) == string::npos)
            {
                str += s[i];
                len++;
            }
            else
            {
                while(str.find(s[i]) != string::npos)
                {
                    str = str.substr(1);
                    len--;
                }
                str += s[i];
                len++;
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};
