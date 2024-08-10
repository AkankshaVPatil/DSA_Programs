//https://leetcode.com/problems/longest-palindrome/description/
//409. Longest Palindrome.cpp
// TC - O(n), SC - O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>freq;

        for(char c:s)
        {
            freq[c]++;
        }

        int count = 0;
        bool isOddFreq = false;
        for(auto fr:freq)
        {
            count += (fr.second/2) * 2;
            if(fr.second % 2 != 0)
                isOddFreq = true;
        }

        return (isOddFreq) ? count+1 : count;
    }
};
