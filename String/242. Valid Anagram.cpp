//https://leetcode.com/problems/valid-anagram/description/
//242. Valid Anagram
//TC - O(n), SC - O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t)
            return true;
        return false;
    }
};
