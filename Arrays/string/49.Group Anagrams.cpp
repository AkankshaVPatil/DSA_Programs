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
