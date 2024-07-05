//https://leetcode.com/problems/group-anagrams/
//49. Group Anagrams

//------------Approach-I---------------------------------
//TC - O(n * klogk), SC - O(n * k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        for(auto s:strs)//O(n)
        {
            string str = s;
            sort(str.begin(), str.end());// O(klogk)
            umap[str].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto str:umap)//O(n)
        {
            ans.push_back(str.second);
        }
        return ans;
    }
};

//------------Approach-II---------------------------------
//TC - O(n * k), SC - O(n * k)
class Solution {
public:
    string sortString(string str)
    {
        vector<int>freq(26, 0);
        for(int i = 0; i < str.size(); i++)
        {
            freq[str[i] - 'a']++;
        }

        string SortedString = "";
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > 0)
               SortedString += string(freq[i], i + 'a'); 
        }
        return SortedString;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        for(auto str:strs)
        {
            string sortedstr = sortString(str);//
            umap[sortedstr].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto str:umap)
        {
            ans.push_back(str.second);
        }
        return ans;
    }
};
