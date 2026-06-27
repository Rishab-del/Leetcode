class Solution {
public:
int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;
            if (vis[ni][nj])
                continue;
            // Reverse flow: move to equal or higher height
            if (heights[ni][nj] >= heights[i][j])
                dfs(heights, ni, nj, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        // Pacific: top row & left column
        for (int i = 0; i < m; i++)        //top to down
            dfs(heights, i, 0, pacific);
        for (int j = 0; j < n; j++)           //left to right
            dfs(heights, 0, j, pacific);
        // Atlantic: bottom row & right column
        for (int i = 0; i < m; i++)       // top to down 
            dfs(heights, i, n - 1, atlantic);
        for (int j = 0; j < n; j++)        //left to roght 
            dfs(heights, m - 1, j, atlantic);
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};