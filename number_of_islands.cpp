class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> used(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] && !used[i][j])
                {
                    findIsland(used, i, j, grid);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void findIsland(vector<vector<bool>>& used, int i, int j, vector<vector<bool>>& grid)
    {
        if (!grid[i][j] || used[i][j]) return;
        
        used[i][j] = true;
        
        if (i > 0) findIsland(used, i-1, j, grid);
        if (i < grid.size()-1) findIsland(used, i+1, j, grid);
        if (j > 0) findIsland(used, i, j-1, grid);
        if (j < grid[0].size()-1) findIsland(used, i, j+1, grid);
    }
};

