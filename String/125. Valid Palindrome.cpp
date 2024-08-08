//https://leetcode.com/problems/valid-palindrome/description/
//125. Valid Palindrome
//------Approach-1-----
// TC - O(n), SC - O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto c:s)
        {
            if(isalnum(c))
            {
                if(isalpha(c) && isupper(c))
                    str += tolower(c);
                else
                    str += c;
            }
        }

        int i = 0, j = str.size()-1;
        while(i <= j)
        {
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }
};

//-------Approach-II------
// TC - O(n), SC - O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i <= j)
        {
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else
            {
                if(tolower(s[i]) != tolower(s[j]))
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};
