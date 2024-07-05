//https://leetcode.com/problems/find-original-array-from-doubled-array/
//2007. Find Original Array From Doubled Array
// TC - O(nlogn), SC - O(n)

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 == 1) return{};
        
        sort(changed.begin(), changed.end());

        unordered_map<int, int> freq;
        for(int num:changed)
        {
            freq[num]++;
        }

        vector<int> ans;
        for(int num:changed)
        {
            if(freq[num] == 0) continue;

            int doubleVal = num * 2;
            if(!freq.contains(doubleVal) || freq[doubleVal] == 0)
                return {};
            
            ans.push_back(num);
            freq[num]--;
            freq[doubleVal]--;
        }
        return ans;
    }
};
