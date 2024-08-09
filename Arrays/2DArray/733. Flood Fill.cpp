//https://leetcode.com/problems/flood-fill/description/
//733. Flood Fill

class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int color, int m, int n, int val) 
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(image[i][j] != val) return;

        image[i][j] = color;

        solve(image, i+1, j, color, m, n, val);
        solve(image, i, j+1, color, m, n, val);
        solve(image, i-1, j, color, m, n, val);
        solve(image, i, j-1, color, m, n, val);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        int val = image[sr][sc];
        if(val == color) return image;

        solve(image, sr, sc, color, m, n, val);
        return image;
    }
};
