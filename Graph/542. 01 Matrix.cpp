//https://leetcode.com/problems/01-matrix/description/
//542. 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>>ans(m, vector<int>(n, -1));
        queue<pair<int, int>>q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto d:dir)
            {
                int xx = x+d[0];
                int yy = y+d[1];

                if(xx >= 0 && yy >= 0 && xx < m && yy < n && ans[xx][yy] == -1)
                {
                    ans[xx][yy] = ans[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }

        return ans;
    }
};
