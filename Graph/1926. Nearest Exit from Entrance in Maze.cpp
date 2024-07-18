//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
//1926. Nearest Exit from Entrance in Maze
// TC - O(m * n), SC - O(m * n)
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto isExitFound = [&](int x, int y)
        {
            return x < 0 || x >= m || y < 0 || y >= n;
        };
        int steps = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> coord = q.front(); 
                int x = coord.first;
                int y = coord.second;
                q.pop();

                for(auto d:dir)
                {
                    int xx = x + d[0];
                    int yy = y + d[1];
                    if(coord != make_pair(entrance[0], entrance[1]) && isExitFound(xx, yy) == true)
                    {
                        return steps;
                    }                    
                    if(!isExitFound(xx, yy) && maze[xx][yy] == '.' && visited[xx][yy] == false)
                    {
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
