//https://leetcode.com/problems/minimum-genetic-mutation/description/
//433. Minimum Genetic Mutation
// TC - O(4*B*L) //4 size of "ACGT", L - size of string , B - size of Bank array
// SC - O(B)
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string>q;

        q.push(startGene);
        visited.insert(startGene);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                string str = q.front();
                q.pop();

                if(str == endGene)
                    return level;
                
                for(auto ch:"ACGT")
                {                    
                    for(int i = 0; i < str.size(); i++)
                    {
                        string temp = str;
                        temp[i] = ch;
                        if(st.find(temp) != st.end() && visited.find(temp) == visited.end())
                        {
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
