class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        
        for (int i = 1; i < n; ++i) {
            f[0][i] = f[0][i-1] + grid[0][i];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        
        return f[m-1][n-1];
    }
};


