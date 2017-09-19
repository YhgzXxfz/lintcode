class Solution {
public:
    /*
     * @param : a 2d boolean array
     * @param : an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> grid, int k) {
        if (grid.empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int size = 0;
                if (grid[i][j]) {
                    dfs(grid, i, j, size);
                }
                if (size >= k) ++result;
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<bool>>& grid, int i, int j, int& size) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) return ;
        
        grid[i][j] = false;
        ++size;
        for (auto dir : dirs) {
            int x = i+dir[0], y = j+dir[1];
            dfs(grid, x, y, size);
        }
    }
    
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
};
