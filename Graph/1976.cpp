//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// 1976. Number of Ways to Arrive at Destination
// Dijkstra Algorithm - Graph

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>adj;
        long long MOD = 1e9 + 7;
        for(auto road:roads)
        {
            int u = road[0];
            int v = road[1];
            int t = road[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        vector<long long>sol(n, 0);
        vector<long long>time(n, LONG_MAX);
        sol[0] = 1;
        time[0] = 0;
        while(!pq.empty())
        {
            long long t = pq.top().first;//0
            long long u = pq.top().second;//0
            pq.pop();

            if(time[u] < t) continue;

            for(auto edge:adj[u])
            {
                long long v = edge.first;//
                long long tm = edge.second;

                if(t + tm < time[v])
                {
                    sol[v] = sol[u];//1 1
                    time[v] = t + tm;//0 2
                    pq.push({t+tm, v});
                }
                else if(t + tm == time[v])
                    sol[v] = (sol[v] + sol[u])%MOD;
            }
        }
        return sol[n-1]%MOD;
    }
};
