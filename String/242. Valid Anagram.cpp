//https://leetcode.com/problems/valid-anagram/description/
//242. Valid Anagram
//-------Approach-I---------
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

//-------Approach-II---------
//TC - O(n), SC - O(1) i.e. O(26)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>vec1(26, 0);
        vector<int>vec2(26, 0);

        for(int i = 0; i < s.size();i++)
        {
            vec1[s[i] - 'a']++;
            vec2[t[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(vec1[i] != vec2[i])
                return false;
        }
        return true;
    }
};

//-------Approach-III---------
    class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>vec(26, 0);

        for(int i = 0; i < s.size();i++)
        {
            vec[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.size();i++)
        {
            vec[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(vec[i] != 0)
                return false;
        }
        return true;
    }
};
