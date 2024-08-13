//https://leetcode.com/problems/k-closest-points-to-origin/
//973. K Closest Points to Origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;
        for(auto p:points)
        {
            int val = (p[0]*p[0])+(p[1]*p[1]);            
            pq.push({val, p});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> vec;
        while(!pq.empty())
        {
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};
