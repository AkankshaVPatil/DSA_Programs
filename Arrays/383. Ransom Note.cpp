//https://leetcode.com/problems/ransom-note/description/
//383. Ransom Note
// TC - O(n), SC - O(26)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>count(26, 0);
        for(char c:magazine)
        {
            count[c - 'a']++;
        }

        for(char c:ransomNote)
        {
            if(count[c - 'a'] == 0)
                return false;
            count[c - 'a']--;
        }
        return true;
    }
};
