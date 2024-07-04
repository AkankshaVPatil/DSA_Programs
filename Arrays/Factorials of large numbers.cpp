//https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
//Factorials of large numbers
// TC - O(N*logN*logN), SC - O(N)

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>res(100000, 0);//4 2
        res[0] = 1;
        int sz = 1;
            
        for(int i = 2; i <= N; i++)//O(N)
        {
            int carry = 0;
            for(int j = 0; j < sz; j++) // O(logN)
            {
                int mult = i * res[j] + carry;
                
                carry = mult / 10;
                res[j] = mult % 10;
            }
            
            while(carry > 0)
            {
                res[sz] = carry % 10;
                sz++;
                carry = carry / 10;
            }
        }
        
        vector<int>ans;
        for(int i = sz-1; i >= 0; i--)
        {
            ans.push_back(res[i]);
        }
        return ans;
    }
};
